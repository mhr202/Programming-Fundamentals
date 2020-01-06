#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
	bool f = false;
	char para[400] = "Cheating is the getting of a reward for ability by dishonest means or finding an easy way out of an unpleasent situations to gain unfair advantage in a competitive situation. This broad definition will neccessarily include acts of bribery, cronyism, sleaze, nepotism and any situation where individuals are given preference using inappropriate criteria.";
	char find[10], replace[10];
	cout << "The paragraph *****" << endl << para << endl << endl;
	cout << "Find: ";
	gets_s(find);
	cout << "Replace with: ";
	gets_s(replace);

	for (int i = 0; para[i] != '\0';i++)
	{
		if (para[i] == find[0])
		{
			int x = i;
			f = true;
			for (int j = 1; find[j] != '\0' && f == true; j++)
			{

				if (find[j] != para[x++])
					f = false;
			}
		}

	}
	if (f == true)
	{
		cout << "found";
	}
	else if (f == false)
	{
		cout << "Not Found";
	}


}