#include<iostream>
#include<list>

using namespace std;

int main()
{
	list<int> ring;
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
		ring.push_back(i+1);
	
	int num=1;
	list<int>::iterator it=ring.begin();
	while(ring.size()!=1)
	{
		if(num%k==0||(num-num/10*10==k))
		{
			it=ring.erase(it);
			it--;
		}
		num++;	
		it++;
		if(it==ring.end())
			it=ring.begin();
	}
	cout<<*(ring.begin());
}
