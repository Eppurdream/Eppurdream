#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

struct tag_munje
{
	string question;
	string answer;
	int wordcount;
	bool bused;
};

tag_munje munje[]{
	{"********", "alphabet", 8, false}
};

int main()
{
	char ch, checkch;
	string tempquestion;
	int checkcount, checkstar;

	tempquestion = munje[0].question;

	cout << "-----------------------------------" << endl;
	cout << "|       alphabet 맞히기 게임      |" << endl;
	cout << "-----------------------------------" << endl;
	cout << "|     설명 : 알파벳을 누르세요    |" << endl;
	cout << "-----------------------------------" << endl;

	cout << tempquestion << endl;

	checkcount = 0;
	checkstar = 0;
	
	for (int i = 0; i < munje[0].wordcount; i++)
	{
		checkch = _getch();
		system("cls");
		for (int j = 0; j < munje[0].wordcount; j++)
		{
			if (munje[0].answer[j] == checkch)
			{
				tempquestion[j] = checkch;
			}
		}
		cout << tempquestion << endl;
		if (munje[0].answer == tempquestion)
		{
			system("cls");
			cout << "단어를 완성시켰어요!" << endl;
			cout << "남은 기회 : " << munje[0].wordcount - i - 1 << endl;
			return 0;
		}
		
	}

	system("cls");
	cout << "단어를 결국 완성시키지 못했어요.." << endl;

	return 0;
}
