#include <iostream>
#include <Windows.h>
#include <time.h>
using namespace std;

int main() 
{
	srand(time(NULL));
	int Num[11]{ 0, };

	for (int i = 3; i > 0; i--)
	{
		system("cls");
		cout << i;
		Sleep(1000);
	}
	system("cls");

	for (int i = 0; i < _countof(Num); i++)
	{
		Num[i] = rand() % 100;
		cout << Num[i] << ", ";
		Sleep(1000);
	}
	system("cls");

	int answer = 0;
	for (int i = 0; i < _countof(Num); i++)
	{
		cin >> answer;

		if (answer != Num[i])
		{
			cout << "틀렸슴니다" << endl;
			return 0;
		}
	}

	cout << "모두 정답입니다" << endl;
	return 0;
}
