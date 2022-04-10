# DFS로 미로를 제작하고 DFS로 출구를 찾는 코드

- 코드 내용

<details>

```cpp
  #include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <tuple>
#include <Windows.h>
using namespace std;


// DFS를 이용한 미로 탈출 경로 찾기

// DFS : 깊이 우선 탐색

// 1. 미로 구현
// 2. 미로의 길을 점점 탐색해나감
// 3. 출구를 발견하면 끝

// - 1번
// 랜덤으로 가다가 가려던 방향의 2칸 뒤가 이미 뚫려 있거나 비어있다면 뒤로 간다.
// 뒤로 가면서 주변에 뚫을 수 있는 곳이 있는지 확인하고 뚫을 수 있는 곳이 있다면 그곳으로 계속 간다.
// 계속 뚫고 가는데 주변중 한칸이 출구라면 코드를 끝낸다.
// - 2번 
// 1번에서 이미 길을 다 만들어 놨기에 DFS를 이용해서 길을 찾기만 하면 된다.
// - 3번 
// 출구를 발견하면 화면을 멈추고 키 입력하면 창을 종료하도록 할거임




/*

■ ■ ■ ■ ■ ■ ■ ■ ■ ■
□ □ □ ■ ■ ■ ■ ■ ■ ■
■ ■ □ ■ ■ ■ ■ ■ ■ ■
■ ■ □ ■ ■ ■ ■ ■ ■ ■
■ ■ □ ■ ■ ■ ■ ■ ■ ■
■ ■ □ ■ ■ ■ ■ ■ ■ ■
■ □ □ ■ ■ ■ ■ ■ ■ ■
■ □ ■ ■ ■ ■ ■ ■ ■ ■
■ □ □ □ ■ ■ ■ ■ ■ □
■ ■ ■ ■ ■ ■ ■ ■ ■ ■

*/
enum MoveDir
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
};

#pragma region 미로 코드
// 미로 칸 클래스
class MazeBox
{
public:
	bool isBlocked;
	bool footprints;
private:

};

// exit : Vector2(size - 1, size - 2);

// 미로 
// 미로 칸을 이중 배열로 가졌슴
// 이동하는 기능이 있음
class Maze
{
public:
	void init();
	void release();

	bool getBoxStatus(tuple<int, int>);
	bool getFootprints(tuple<int, int>);
	void setFootprints(tuple<int, int>, bool);

	void printMapAndFinder(tuple<int, int>);

	int size;
private:
	MazeBox** maze;

	char answer;
	MoveDir dir;

	CHAR_INFO* buffer;

	stack<tuple<int, int>> moveInformation;

	int currentX;
	int currentY;

	void makeMaze();
	bool move(bool);
	bool checkBox();
};

// 초기화 함수 
// 시작할 때 호출함
void Maze::init()
{
	srand((unsigned int)time(NULL));


	cout << "미로 크기 (크기가 30이상이라면 화면을 늘려야 보여요!!) : ";
	cin >> size;

	cout << "미로 제작 과정 보실건가요? (y : n) : ";
	cin >> answer;

	if (answer == 'n')
	{
		system("cls");
		cout << "미로 제작 중..." << endl;
	}

	currentX = 1;
	currentY = 1;

	maze = new MazeBox * [size];

	for (int i = 0; i < size; i++)
	{
		maze[i] = new MazeBox[size];

		for (int n = 0; n < size; n++)
		{
			maze[i][n].isBlocked = true;
			maze[i][n].footprints = false;
		}
	}

	maze[0][1].isBlocked = false;
	maze[0][1].footprints = true;
	maze[1][1].isBlocked = false;

	buffer = new CHAR_INFO[size * size];

	makeMaze();
}

// 끝내는 함수
// 끝날 때 호출함
void Maze::release()
{
	for (int i = 0; i < size; i++)
		delete[] maze[i];

	delete[] maze;
}

bool Maze::getBoxStatus(tuple<int, int> pos)
{
	return maze[get<0>(pos)][get<1>(pos)].isBlocked;
}

bool Maze::getFootprints(tuple<int, int> pos)
{
	return maze[get<0>(pos)][get<1>(pos)].footprints;
}

void Maze::setFootprints(tuple<int, int> pos, bool value)
{
	maze[get<0>(pos)][get<1>(pos)].footprints = value;
}

void Maze::printMapAndFinder(tuple<int, int> pos)
{
	system("cls");
	COORD s = { size, size }, position = { 0, 0 };
	SMALL_RECT rect = { 0, 0, size, size };

	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++)
		{
			if (get<0>(pos) == x && get<1>(pos) == y)
			{
				buffer[x + (y * size)].Char.UnicodeChar = '%';
				buffer[x + (y * size)].Attributes = 7;
			}
			else if (maze[x][y].isBlocked)
			{
				buffer[x + (y * size)].Char.UnicodeChar = '.';
				buffer[x + (y * size)].Attributes = 7;
			}
			else if (maze[x][y].footprints)
			{
				buffer[x + (y * size)].Char.UnicodeChar = 'i';
				buffer[x + (y * size)].Attributes = 7;
			}
			else
			{
				buffer[x + (y * size)].Char.UnicodeChar = ' ';
				buffer[x + (y * size)].Attributes = 7;
			}
		}

		cout << endl;
	}

	WriteConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), buffer, s, position, &rect);
}

// 미로 만드는 함수
// 입력 값에 따라 제작 과정을 보여주기도 함
void Maze::makeMaze()
{
	COORD s = { size, size }, position = { 0, 0 };
	SMALL_RECT rect = { 0, 0, size, size };

	while (true)
	{
		if (!move(false))
		{
			// 처음으로 돌아오면
			if (moveInformation.size() == 0)
			{
				maze[2][1].isBlocked = false;
				maze[size - 2][size - 2].isBlocked = false;
				maze[size - 1][size - 2].isBlocked = false;

				system("cls");

				// 여기서 움직이는 변수에 따라 움직임을 보여줘야 함
				for (int y = 0; y < size; y++)
				{
					for (int x = 0; x < size; x++)
					{
						if (maze[x][y].isBlocked)
						{
							cout << "■";
						}
						else
						{
							cout << "□";
						}
					}

					cout << endl;
				}

				break;
			}
			else
			{
				tuple<int, int> information = moveInformation.top();

				currentX = get<0>(information);
				currentY = get<1>(information);

				moveInformation.pop();
			}
		}
		else
		{
			maze[currentX][currentY].isBlocked = false;

			if (answer == 'y')
			{
				system("cls");

				for (int y = 0; y < size; y++)
				{
					for (int x = 0; x < size; x++)
					{
						if (maze[x][y].isBlocked)
						{
							buffer[x + (y * size)].Char.UnicodeChar = '.';
							buffer[x + (y * size)].Attributes = 7;
						}
						else
						{
							buffer[x + (y * size)].Char.UnicodeChar = ' ';
							buffer[x + (y * size)].Attributes = 7;
						}
					}

					cout << endl;
				}

				WriteConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), buffer, s, position, &rect);

				Sleep(2);
			}

			moveInformation.push(make_tuple(currentX, currentY));
		}
	}
}

// 랜덤값에 따라 움직이는 함수
bool Maze::move(bool isFirst)
{
	if (isFirst)
	{
		dir = MoveDir::RIGHT;
	}
	else
	{
		dir = (MoveDir)(rand() % 4);
	}

	bool isMoved = false;

	for (int i = 0; i < 4; i++)
	{
		if (checkBox())
		{
			switch (dir)
			{
			case UP:
				currentY -= 1;
				break;
			case DOWN:
				currentY += 1;
				break;
			case LEFT:
				currentX -= 1;
				break;
			case RIGHT:
				currentX += 1;
				break;
			}

			isMoved = true;
			break;
		}
		else
		{
			if (dir == MoveDir::RIGHT)
			{
				dir = MoveDir::UP;
			}
			else
			{
				dir = (MoveDir)(dir + 1);
			}
		}
	}

	return isMoved;
}

// 갈 수 있나 못가나 판단하는 함수
// 
// 못가는 곳의 조건
// 자신이 온 곳 제외해서 상하좌우를 체크함
// 
// 체크하는 조건은 다음과 같이 있음
// 예를 들어 위를 체크한다면 
// 
// 위 1~2칸 왼쪽, 중간, 오른쪽에 뚫린 블럭이 있거나
// 가려고하는곳이 외벽이라면
// 
// 그 방향은 못가는 곳임
// 
// 못가면 false 가면 true
bool Maze::checkBox()
{
	switch (dir)
	{
	case UP:
		if (answer == 'y')
		{
			cout << "UP ";
		}
		if (currentY - 1 <= 0)
		{
			return false;
		}

		for (int x = -1; x <= 1; x++)
		{
			for (int y = -1; y >= -2; y--)
			{
				// 좌표에 이미 벽이 뚫려있다면 못감
				if (!maze[currentX + x][currentY + y].isBlocked)
				{
					return false;
				}
			}
		}

		return true;
		break;
	case DOWN:
		if (answer == 'y')
		{
			cout << "DOWN ";
		}
		if (currentY + 1 >= size - 1)
		{
			return false;
		}

		for (int x = -1; x <= 1; x++)
		{
			for (int y = 1; y <= 2; y++)
			{
				// 좌표에 이미 벽이 뚫려있다면 못감
				if (!maze[currentX + x][currentY + y].isBlocked)
				{
					return false;
				}
			}
		}

		return true;
		break;
	case LEFT:
		if (answer == 'y')
		{
			cout << "LEFT ";
		}
		if (currentX - 1 <= 0)
		{
			return false;
		}

		for (int x = -1; x >= -2; x--)
		{
			for (int y = -1; y <= 1; y++)
			{
				// 좌표에 이미 벽이 뚫려있다면 못감
				if (!maze[currentX + x][currentY + y].isBlocked)
				{
					return false;
				}
			}
		}

		return true;
		break;
	case RIGHT:
		if (answer == 'y')
		{
			cout << "RIGHT ";
		}
		if (currentX + 1 >= size - 1)
		{
			return false;
		}

		for (int x = 1; x <= 2; x++)
		{
			for (int y = -1; y <= 1; y++)
			{
				// 좌표에 이미 벽이 뚫려있다면 못감
				if (!maze[currentX + x][currentY + y].isBlocked)
				{
					return false;
				}
			}
		}

		return true;
		break;
	}
}
#pragma endregion

#pragma region 찾는 놈 코드

class Finder
{
public:
	void init(Maze maze);
	void release();
private:
	Maze maze;
	MoveDir dir;

	int currentX;
	int currentY;

	int delay;

	stack<tuple<int, int>> moveInformation;

	bool checkBox();
	bool move(bool);
	void findExit();
};

void Finder::init(Maze maze)
{
	this->maze = maze;

	currentX = 0;
	currentY = 1;

	cout << "이동 딜레이는 얼마나 하실건가요(ms 단위) : ";
	cin >> delay;

	findExit();
}

void Finder::release()
{

}

bool Finder::move(bool isFirst)
{
	if (isFirst)
	{
		dir = MoveDir::RIGHT;
	}
	else
	{
		dir = (MoveDir)(rand() % 4);
	}

	bool isMoved = false;

	for (int i = 0; i < 4; i++)
	{
		if (checkBox())
		{
			switch (dir)
			{
			case UP:
				currentY -= 1;
				break;
			case DOWN:
				currentY += 1;
				break;
			case LEFT:
				currentX -= 1;
				break;
			case RIGHT:
				currentX += 1;
				break;
			}

			isMoved = true;
			break;
		}
		else
		{
			switch (dir)
			{
			case UP:
				dir = DOWN;
				break;
			case DOWN:
				dir = LEFT;
				break;
			case LEFT:
				dir = RIGHT;
				break;
			case RIGHT:
				dir = UP;
				break;
			}
		}
	}

	return isMoved;
}

bool Finder::checkBox()
{
	switch (dir)
	{
	case UP:
		cout << "UP ";
		if (!(currentY - 1 < 0) && !maze.getBoxStatus(make_tuple(currentX, currentY - 1)) && !maze.getFootprints(make_tuple(currentX, currentY - 1)))
		{
			return true;
		}
		return false;
		break;
	case DOWN:
		cout << "DOWN ";
		if (!(currentY + 1 >= maze.size) && !maze.getBoxStatus(make_tuple(currentX, currentY + 1)) && !maze.getFootprints(make_tuple(currentX, currentY + 1)))
		{
			return true;
		}
		return false;
		break;
	case LEFT:
		cout << "LEFT ";
		if (!(currentX - 1 < 0) && !maze.getBoxStatus(make_tuple(currentX - 1, currentY)) && !maze.getFootprints(make_tuple(currentX - 1, currentY)))
		{
			return true;
		}
		return false;
		break;
	case RIGHT:
		cout << "RIGHT ";
		if (!(currentX + 1 >= maze.size) && !maze.getBoxStatus(make_tuple(currentX + 1, currentY)) && !maze.getFootprints(make_tuple(currentX + 1, currentY)))
		{
			return true;
		}
		return false;
		break;
	default:
		return true;
	}
}

void Finder::findExit()
{
	while (true)
	{
		if (!move(false))
		{
			if (currentX == maze.size - 1 && currentY == maze.size - 2)
			{
				char end;

				cout << endl << "끝ㅁ" << endl;
				cin >> end;
				break;
			}
			tuple<int, int> information = moveInformation.top();

			currentX = get<0>(information);
			currentY = get<1>(information);

			moveInformation.pop();
		}
		else
		{
			maze.printMapAndFinder(make_tuple(currentX, currentY));

			moveInformation.push(make_tuple(currentX, currentY));
			maze.setFootprints(make_tuple(currentX, currentY), true);

			Sleep(delay);
		}
	}
}

#pragma endregion

int main()
{
	Maze maze = Maze();

	maze.init();

	Finder finder = Finder();

	finder.init(maze);

	maze.release();

	return 0;
}
```
  
</details>
