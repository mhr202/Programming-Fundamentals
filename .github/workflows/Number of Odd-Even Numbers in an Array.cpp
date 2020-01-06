#include <iostream>
using namespace std;

int main()
{
	int n, even = 0, odd = 0;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
			even++;
		if (a[i] % 2 != 0)
			odd++;
		if (a[i] == 1);
		    odd++;

	}
}