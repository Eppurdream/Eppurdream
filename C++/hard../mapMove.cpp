#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <time.h>
using namespace std;

#define UP		72
#define DOWN	80
#define LEFT	75
#define RIGHT	77

void gotoXY(int x, int y)
{
	HANDLE hOut;
	COORD Cur;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(hOut, Cur);
}

int currentX, currentY;

char ShowMap[20][21] =
{
	"XXXXXXXXXXXXXXXXXXXX",
	"X..................X",
	"X..................X",
	"X..................X",
	"X..................X",
	"X..................X",
	"X..................X",
	"X..................X",
	"X..................X",
	"X..................X",
	"X..................X",
	"X..................X",
	"X..................X",
	"X..................X",
	"X..................X",
	"X..................X",
	"X..................X",
	"X..................X",
	"X..................X",
	"XXXXXXXXXXXXXXXXXXXX"
};

void displayScreen()
{
	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 21; x++)
		{
			gotoXY(x, y);
			_putch(ShowMap[y][x]);
		}
	}

	if (currentX <= -1 || currentX >= 20)
	{
		if (currentX <= -1)
			currentX = 1;
		currentX = 20 - currentX;
	}
	if (currentY <= -1 || currentY >= 20)
	{
		if (currentY <= -1)
			currentY = 1;
		currentY = 20 - currentY;
	}
	gotoXY(currentX, currentY);
	_putch('O');

	gotoXY(20, 2);
	cout << "Q:종료";
}

void move(int dir)
{
	int dir_x = 0;
	int dir_y = 0;

	switch (dir)
	{
	case LEFT:
		dir_x = -1;
		break;
	case RIGHT:
		dir_x = 1;
		break;
	case UP:
		dir_y = -1;
		break;
	case DOWN:
		dir_y = 1;
		break;
	}

	if (ShowMap[currentY + dir_y][currentX + dir_x] != 'X')
	{
		currentX += dir_x;
		currentY += dir_y;
	}
}

int main()
{
	currentX = 1;
	currentY = 1;
	int ch = 0;
	srand(time(NULL));
	
	int ranX = 0;
	int ranY = 0;
	for (int i = 0; i < 11; i++)
	{
		ranX = rand() % 19 + 1;
		ranY = rand() % 18 + 1;
		ShowMap[ranY][ranX] = 'X';
	}

	while (true) {
		displayScreen();
		ch = _getch();


		if (ch == 0xE0 || ch == 0)
		{
			ch = _getch();

			switch (ch)
			{
			case LEFT:
			case RIGHT:
			case UP:
			case DOWN:
				move(ch);
				break;
			}
		}
		else
		{
			ch = tolower(ch);
			if (ch == 'q')
			{
				exit(0);
			}
			else if (ch == 'z')
			{
				ShowMap[currentY][currentX] = 'X';
			}
			else if (ch == 'a')
			{
				for (int x = -1; x <= 1; x++)
				{
					ShowMap[currentY][currentX + x] = '.';
				}
				for (int y = -1; y <= 1; y++)
				{
					ShowMap[currentY + y][currentX] = '.';
				}
			}
			else if (ch == 'b')
			{
				for (int x = -1; x <= 1; x++)
				{
					for (int y = -1; y <= 1; y++)
					{
						for (int x = -1; x <= 1; x++)
						{
							if (currentX + x <= -1 || currentX + x >= 20)
								continue;
							ShowMap[currentY][currentX + x] = '.';
							ShowMap[19 - currentY][19 - currentX + x] = '.';
						}
						for (int y = -1; y <= 1; y++)
						{
							if (19 - currentY + y == -1)
								continue;

							ShowMap[currentY + y][currentX] = '.';
							ShowMap[19 - currentY + y][19 - currentX] = '.';

						}
					}
				}
			}
		}
	}
}
