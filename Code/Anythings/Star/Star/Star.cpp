#include <iostream>
using namespace std;

int main()
{
	cout << "----------------------------------------Triangle----------------------------------------" << endl << endl;

	for (int i = 0; i < 10; i++)
	{
		for (int n = 1; n <= i; n++)
		{
			cout << "*";
		}
		cout << endl;
	}

	cout << endl << "----------------------------------------Reverse Triangle----------------------------------------" << endl << endl;

	for (int i = 0; i < 10; i++)
	{
		for (int n = 10; n > i; n--)
		{
			cout << "*";
		}
		cout << endl;
	}

	cout << endl << "----------------------------------------Pyramid----------------------------------------" << endl << endl;

	for (int i = 0; i < 10; i++)
	{
		for(int n = 10; n > i; n--)
		{ 
			cout << " ";
		}
		for (int n = 0; n < i * 2 + 1; n++)
		{
			cout << "*";
		}
		cout << endl;
	}

	cout << endl << "----------------------------------------Rhombus----------------------------------------" << endl << endl;

	int temp = 0;

	for (int i = 0; i < 21; i++)
	{
		for (int n = 10; n > temp; n--)
		{
			cout << " ";
		}
		for (int n = 0; n < temp * 2 + 1; n++)
		{
			cout << "*";
		}
		cout << endl;

		temp += i >= 10 ? -1 : 1;
	}

	cout << endl << "----------------------------------------Empty Rhombus----------------------------------------" << endl << endl;

	temp = 0;

	for (int i = 0; i < 21; i++)
	{
		for (int n = 10; n > temp; n--)
		{
			cout << " ";
		}
		for (int n = 0; n < temp * 2 + 1; n++)
		{
			if (n == 0 || n % temp == 0 && n != temp)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;

		temp += i >= 10 ? -1 : 1;
	}

	cout << endl << "----------------------------------------Circle----------------------------------------" << endl << endl;

	int length = 15;

	for (int i = -length; i < length; i++)
	{
		for (int n = -length; n < length; n++)
		{
			if (i * i + n * n < length * length)
			{
				cout << "* ";
			}
			else
			{
				cout << "  ";
			}
		}
		cout << endl;
	}
}