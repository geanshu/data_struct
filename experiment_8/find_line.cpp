#include<fstream>
#include<random>
#include<windows.h>
#include<string>
#include<iostream>
using namespace std;


int find(int* a,int n,int value)
{
	int i;
	for(i=0;i<n;i++)
		if(a[i]==value)
			break;
	return i+1;
}

void test(int n)
{
	string str1=to_string(n)+".txt",str2="line_find_"+to_string(n)+".csv";
	string str3="line_find_error_"+to_string(n)+".csv";
	ifstream readFile(str1);
	ofstream outfile1(str2, ios::out | ios::trunc);
	ofstream outfile2(str3, ios::out | ios::trunc);
	default_random_engine e;
	e.seed(1);
	int* a=new int[n];
	for(int i=0;i<n;i++)
		readFile>>a[i];
		
	outfile1<<"Search Times"<<","<<"T/¦Ìs\n";
	int temp=0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);
	int f;
	while(temp<100)
	{
		QueryPerformanceCounter(&nBeginTime);
		f=find(a,n,a[e()%n]);
		QueryPerformanceCounter(&nEndTime);
		if(f!=n+1)
		{
			temp++;
			outfile1<<f<<','<<1000000*(double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart<<'\n';
		}
	}
	temp=0;
	outfile2<<"Search Times"<<","<<"T/¦Ìs\n";
	while(temp<100)
	{
		QueryPerformanceCounter(&nBeginTime);
		f=find(a,n,e());
		QueryPerformanceCounter(&nEndTime);
		if(f==n+1)
		{
			temp++;
			outfile2<<f-1<<','<<1000000*(double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart<<'\n';
		}
	} 
	delete []a;
}

int main()
{
	 
	for(int i=100;i<=1000000;i*=10)
	{
		test(i);
		cout<<i<<"finshed!\n";
	}
		
	return 0;
}
