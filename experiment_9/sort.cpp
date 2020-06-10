#include<fstream>
#include<windows.h>
#include<string>
#include<iostream>
using namespace std;

long long swap_time,cmp_time;

void sort_bubble(int* a,int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			cmp_time++;
			if(a[j]>a[j+1])
			{
				swap(a[j],a[j+1]);
				swap_time++;
			}
		}
	}
}

void sort_quick(int* a,int n,int left, int right)
{
	if(left >= right)
		return;
	int i,j,base;
	i=left,j=right;
	base=a[(left+right)/2];
	while (i < j)
	{
		
		while(a[j] >= base && i < j)
		{
			j--;
			cmp_time++;
		}
		while (a[i] <= base && i < j)
		{
			i++;
			cmp_time++;
		}
		if(i < j)
		{
			swap(a[i],a[j]);
			swap_time++;
		}
	}
	a[left] = a[i];
	a[i] = base;
	sort_quick(a,n,left, i - 1);
	sort_quick(a,n,i + 1, right);
}

void bubble(int n)
{
	string str1=to_string(n)+".txt",str2="Bubble_"+to_string(n)+".txt";
	ifstream readFile(str1);
	ofstream outfile(str2, ios::out | ios::trunc);
	int* a=new int[n];
	for(int i=0;i<n;i++)
		readFile>>a[i];
		
	LARGE_INTEGER nFreq,nBeginTime,nEndTime;
	swap_time=0;cmp_time=0;
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);
	sort_bubble(a,n);
	QueryPerformanceCounter(&nEndTime);
	double time=1000*(double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
	cout<<"time:"<<time<<"ms\n";
	outfile<<"time:"<<time<<"ms "<<cmp_time<<' '<<swap_time<<'\n';
	for(int i=0;i<n;i++)
		outfile<<a[i]<<'\n';
	delete []a;
}

void quick(int n)
{
	string str1=to_string(n)+".txt",str2="Quick_"+to_string(n)+".txt";
	ifstream readFile(str1);
	ofstream outfile(str2, ios::out | ios::trunc);
	int* a=new int[n];
	for(int i=0;i<n;i++)
		readFile>>a[i];
		
	LARGE_INTEGER nFreq,nBeginTime,nEndTime;
	swap_time=0;cmp_time=0;
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);
	sort_quick(a,n,0,n-1);
	QueryPerformanceCounter(&nEndTime);
	double time=1000*(double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
	cout<<"time:"<<time<<"ms\n";
	outfile<<"time:"<<time<<"ms "<<cmp_time<<' '<<swap_time<<'\n';
	for(int i=0;i<n;i++)
		outfile<<a[i]<<'\n';
	delete []a;
}
int main()
{
	 
	for(int i=100;i<=1000000;i*=10)
	{
		bubble(i);
		quick(i);
		cout<<i<<"finshed!\n";
	}
		
	return 0;
}
