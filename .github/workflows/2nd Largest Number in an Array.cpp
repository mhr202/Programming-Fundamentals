#include <iostream>
using namespace std;

int main()
{
	int a[5] = { 1 , 2 ,3 , 4, 5 }, x = a[0], y = a[0];
	for (int i = 1; i < 5; i++)
	{
		
		if (a[i] > x)
			x = a[i];
	}
	for (int i = 0; i < 5; i++)
	{

		if (a[i] != x && y < a[i])
			y = a[i];
	}
	cout << y ;
	system("pause");
}