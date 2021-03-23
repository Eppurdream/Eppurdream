#include <iostream>
using namespace std;

int main()
{
	int size;
	cout << "(띄어쓰기는 '_'으로 하기)" << endl;
	cout << "문자열을 얼마나 입력 받으실건가요 : ";
	cin >> size;

	char** Pch = new char*[size];

	for (int i = 0; i < size; i++)
	{
		Pch[i] = new char[20];
		cin >> Pch[i];
	}

	char temp[20]; bool notNull = false;
	for (int i = 0; i < size; i++) {
		for (int j = 19; j >= 0; j--)
		{
			temp[j] = Pch[i][19 - j];
		}
		int n = 0;
		for (int j = 0; j < 20; j++)
		{
			if (notNull) {
				Pch[i][n] = temp[j];
				n++;
			}
			if (temp[j] != -51)
				notNull = true;
			//cout << "temp[" << j << "] : " << (int)temp[j] << endl;
		}
		n = 0;
		notNull = false;
	}
	cout << endl;

	for (int i = 0; i < size; i++) {
		cout << i << "번째 문자열 : ";
		for (int j = 0; j < 20; j++)
		{
			if (Pch[i][j] == -51)
				break;
			cout << Pch[i][j];
		}
		cout << endl;
	}
}
