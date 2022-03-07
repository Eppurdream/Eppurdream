#include <iostream>
using namespace std;

void main()
{
	int arr[10]{ 0,1,2,3,4,5,6,7,8,9 };

	for (int i = 0; i < 10; i++)
	{
		cout << i[arr] << "\t";
	}

	cout << endl << endl;

	int arr2[10][10];

	for (int i = 0; i < 10; i++)
	{
		for (int n = 0; n < 10; n++)
		{
			i[n[arr2]] = i * 10 + n;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		for (int n = 0; n < 10; n++)
		{
			cout << i[n[arr2]] << "\t";
		}
		cout << endl;
	}

	return;
}
