#include <iostream>
using namespace std;

void Isize(int num, int &count, int& ex)
{
	if (num <= 0)
	{
		ex /= 10;
		return;
	}
	Isize(num / 10, ++count, ex *= 10);
}

void Sum(int num, int ex, int sum, int temp)
{
	if (ex <= 0)
	{
		cout << sum << endl;
		return;
	}
	else
	{
		temp = num / ex;
		sum += temp;
		num -= ex * temp;
		ex /= 10;
		Sum(num, ex, sum, temp);
	}
}

int main()
{
	int num = 0;
	int count = 0;
	int ex = 1;
	int sum = 0;
	int temp = 0;
	cin >> num;
	Isize(num, count, ex);
	Sum(num, ex, sum, temp);
}
