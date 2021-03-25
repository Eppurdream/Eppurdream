#include <iostream>
using namespace std;

int Fac(int i)
{
	if (i == 0)
		return 1;
	else
		return i * Fac(i - 1);
}

int main()
{
	int i;
	cin >> i;
	cout << Fac(i);
}
