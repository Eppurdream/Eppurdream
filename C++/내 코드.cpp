#include <iostream>
#include <string>
using namespace std;

int main()
{
	char MyNum[14];
	cin >> MyNum;
	string gender; char birthday[10]; int age;

	int Number[11]{ 8, 12, 15, 18, 25, 34, 39, 47, 54, 66, 90 };
	char area

	if (MyNum[6] <= 2) 
	{
		birthday[0] = '1';
		birthday[1] = '9';
		birthday[2] = MyNum[0];
		birthday[3] = MyNum[1];
	}
	else 
	{
		birthday[0] = '2';
		birthday[1] = '0';
		birthday[2] = MyNum[0];
		birthday[3] = MyNum[1];
	}

	int ibirthyear = (birthday[0] - '0') * 1000 + (birthday[1] - '0') * 100 + (birthday[2] - '0') * 10 + (birthday[3] - '0') * 1;
	age = 2021 - ibirthyear + 1;

	if (MyNum[6] % 2 == 1)
		gender = "남자";
	else
		gender = "여자";


	//48 ~ 57
	return 0;
}
