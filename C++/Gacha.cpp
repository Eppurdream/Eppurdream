#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	srand((unsigned)time(NULL));
	
	int Random; 
	int one = 0, two = 0, three = 0, four = 0, five = 0;
	for (int i = 0; i < 1000; i++) {
		Random = rand() % 100 + 1;
		if (Random > 0 && Random <= 50)
		{
			one++;
		}
		else if (Random > 50 && Random <= 75)
		{
			two++;
		}
		else if (Random > 75 && Random <= 90)
		{
			three++;
		}
		else if (Random > 90 && Random <= 97)
		{
			four++;
		}
		else if (Random > 97 && Random <= 100)
		{
			five++;
		}
	}
	cout << "1성 : " << one << ", 2성 : " << two << ", 3성 : " << three << ", 4성 : " << four << ", 5성 : " << five;
	return 0;
}
