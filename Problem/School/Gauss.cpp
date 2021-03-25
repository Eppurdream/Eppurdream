#include <iostream>
using namespace std;
//{ ( 1+n ) X n } / 2
int Gaus(int n)
{
	return ((1 + n) * n) / 2;
}

int main()
{
	int i;
	cin >> i;
	cout << Gaus(i);
}
