#include<iostream>
#include"list_achieve.h"
#include"list_declare.h"

using namespace std;
int main()
{
	List<char> str(1000);
	char a;
	a = getchar();
	while (a != EOF)
	{
		str.append(a);
		a = getchar();
	}

	int num = 0, alpha = 0, other = 0;
	for (int i = 0; i < str.get_size(); i++)
	{
		if (str.get_value(i) >= '0' && str.get_value(i) <= '9')
			num++;
		else if ((str.get_value(i) >= 'a' && str.get_value(i) <= 'z') || (str.get_value(i) >= 'A' && str.get_value(i) <= 'Z'))
			alpha++;
		else
			other++;
	}
	cout << alpha << ' ' << num << ' ' << other << endl;

	for (int i = 0; i < str.get_size(); i++)
	{
		if (str.get_value(i) >= '0' && str.get_value(i) <= '9')
		{
			str.earse(i);
			i--;
		}
	}

	for (int i = 0; i < str.get_size(); i++)
		cout << str.get_value(i);
}