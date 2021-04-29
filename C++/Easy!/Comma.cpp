#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i];
		if ((i + 1) % 3 == str.size() % 3 && i + 1 != str.size())
		{
			cout << ',';
		}
	}
}
