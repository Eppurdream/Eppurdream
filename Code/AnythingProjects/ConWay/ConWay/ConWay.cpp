#include <iostream>
#include <Windows.h>
#include <vector>
using namespace std;

int main()
{
	int const MAXY = 25;
	int const MAXX = 50;
	int const SPACESHIPSY = 10;
	int const SPACESHIPSX = 10;
	int const BLOCKY = 5;
	int const BLOCKX = 5;
	char const ALIVE = '1';
	char const DEAD = ' ';
	char arr[MAXY][MAXX];
	vector<vector<int>> afterNeighbors;
	vector<vector<int>> afterDead;

	for (int i = 0; i < MAXY; i++)
	{
		for (int n = 0; n < MAXX; n++)
		{
			arr[i][n] = DEAD;
		}
	}

	arr[MAXY / 2][MAXX / 2] = ALIVE;
	arr[MAXY / 2 + 1][MAXX / 2] = ALIVE;
	arr[MAXY / 2][MAXX / 2 + 1] = ALIVE;
	arr[MAXY / 2 - 1][MAXX / 2] = ALIVE;
	arr[MAXY / 2][MAXX / 2 - 1] = ALIVE;

	arr[SPACEPARITY][SPACESHIPSX] = ALIVE;
	arr[SPACEPARITY][SPACESHIPSX + 1] = ALIVE;
	arr[SPACEPARITY][SPACESHIPSX + 2] = ALIVE;
	arr[SPACEPARITY + 1][SPACESHIPSX + 2] = ALIVE;
	arr[SPACEPARITY + 2][SPACESHIPSX + 1] = ALIVE;

	arr[BLOCKY][BLOCKX] = ALIVE;
	arr[BLOCKY + 1][BLOCKX] = ALIVE;
	arr[BLOCKY][BLOCKX + 1] = ALIVE;
	arr[BLOCKY + 1][BLOCKX + 1] = ALIVE;

	int neighborCount = 0;

	while (true)
	{
		system("cls");
		// i == y, n == x

		for (int i = 0; i < MAXY; i++)
		{
			for (int n = 0; n < MAXX; n++)
			{
				for (int m = 0; m < afterDead.size(); m++)
				{
					if (afterDead[m][0] == i && afterDead[m][1] == n)
					{
						arr[i][n] = DEAD;
					}
				}

				for (int m = 0; m < afterNeighbors.size(); m++)
				{
					if (afterNeighbors[m][0] == i && afterNeighbors[m][1] == n)
					{
						arr[i][n] = ALIVE;
					}
				}
				cout << arr[i][n];
			}
			cout << endl;
		}

		afterDead.clear();
		afterNeighbors.clear();
		Sleep(200);

		for (int i = 0; i < MAXY; i++)
		{
			for (int n = 0; n < MAXX; n++)
			{
				if (arr[i][n] == ALIVE)
				{
					neighborCount = 0;

					for (int x = -1; x <= 1; x++)
					{
						for (int y = -1; y <= 1; y++)
						{
							if (arr[i + y][n + x] == ALIVE && !(x == 0 && y == 0))
							{
								neighborCount++;
							}
						}
					}

					if (neighborCount >= 4 || neighborCount <= 1)
					{
						vector<int> vec;
						vec.push_back(i);
						vec.push_back(n);
						afterDead.push_back(vec);
					}
				}
				else
				{
					neighborCount = 0;

					for (int x = -1; x <= 1; x++)
					{
						for (int y = -1; y <= 1; y++)
						{
							if (arr[i + y][n + x] == ALIVE && !(x == 0 && y == 0))
							{
								neighborCount++;
							}
						}
					}

					if (neighborCount == 3)
					{
						vector<int> vec;
						vec.push_back(i);
						vec.push_back(n);
						afterNeighbors.push_back(vec);
					}
				}
			}
		}
	}

	return 0;
}