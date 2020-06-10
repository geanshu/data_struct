#include<fstream>
#include<string>
#include<random>
using namespace std;

void creat(int n)
{
	default_random_engine e;
	e.seed(10); 
	string str1="_1.txt",str2=to_string(n);
	str1=str2+str1;
	ofstream OutFile(str1);
	for(int i=0;i<n;i++)
		OutFile <<e()<< '\n';
}

int main()
{
	for(int i=100;i<=1000000;i*=10)
		creat(i);
	return 0;
}
