#include <iostream>
using namespace std;

int Fac(int i)
{
	int num = 1;
	for (int n = i; n > 0; n--)
	{
		num *= n;
	}
	return num;
}

int main()
{
	int i;
	cin >> i;
	cout << Fac(i);
}
