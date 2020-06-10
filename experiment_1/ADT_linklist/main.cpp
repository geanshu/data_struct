#include<iostream>
#include"linklist_achieve.h"
#include"List-declare.h"

using namespace std;


int main()
{
	Linklist<char> str;
	char a = getchar();
	while (a != EOF)
	{
		str.push_back(a);
		a = getchar();
	}

	int alpha = 0, num = 0, other = 0, i = 0;
	for (Link<char>* current = str.get_head(); current != str.get_tail();)
	{
		if ((current->getval() >= 'A' && current->getval() <= 'Z') || (current->getval() >= 'a' && current->getval() <= 'z'))
		{
			alpha++;
			current = current->getnext();
			i++;
		}
		else if (current->getval() >= '0' && current->getval() <= '9')
		{
			num++;
			current = str.earse(i);
		}
		else
		{
			i++;
			other++;
			current = current->getnext();
		}
	}
	cout << alpha << ' ' << num << ' ' << other << endl;

	for (Link<char>* current = str.get_head(); current != str.get_tail(); current = current->getnext())
		cout << current->getval();
}