// * 설명
// 1은 벽입니다
// 0은 갈 수 있는 길입니다
// 공백(' ')은 입구에서 출구까지의 경로입니다

#include <iostream>
#include <time.h>
#include <stack>
using namespace std;

char map[20][21] = {
	"44444444444444444444",
	"41111111111111111114",
	"01111111111111111114",
	"41111111111111111114",
	"41111111111111111114",
	"41111111111111111114",
	"41111111111111111114",
	"41111111111111111114",
	"41111111111111111114",
	"41111111111111111114",
	"41111111111111111114",
	"41111111111111111114",
	"41111111111111111114",
	"41111111111111111114",
	"41111111111111111114",
	"41111111111111111114",
	"41111111111111111114",
	"41111111111111111100",
	"41111111111111111114",
	"44444444444444444444"
};

void stackUp(int y, int x)
{
	if (map[y][x + 1] < '3' && map[y][x + 1] != '0')
		map[y][x + 1]++;
	if (map[y][x - 1] < '3' && map[y][x - 1] != '0')
		map[y][x - 1]++;
	if (map[y + 1][x] < '3' && map[y + 1][x] != '0')
		map[y + 1][x]++;
	if (map[y - 1][x] < '3' && map[y - 1][x] != '0')
		map[y - 1][x]++;
}

bool findNum(int random, int& y, int& x)
{
	switch (random)
	{
	case 1:
		if (map[y][x - 1] < '3' && map[y][x - 1] != '0')
		{
			x--;
			stackUp(y, x);
		}
		else if (map[y + 1][x] < '3' && map[y + 1][x] != '0')
		{
			y++;
			stackUp(y, x);
		}
		else if (map[y - 1][x] < '3' && map[y - 1][x] != '0')
		{
			y--;
			stackUp(y, x);
		}
		else
			return true;

		break;
	case 2:
		if (map[y][x + 1] < '3' && map[y][x + 1] != '0')
		{
			x++;
			stackUp(y, x);
		}
		else if (map[y + 1][x] < '3' && map[y + 1][x] != '0')
		{
			y++;
			stackUp(y, x);
		}
		else if (map[y - 1][x] < '3' && map[y - 1][x] != '0')
		{
			y--;
			stackUp(y, x);
		}
		else
			return true;

		break;
	case 3:
		if (map[y][x + 1] < '3' && map[y][x + 1] != '0')
		{
			x++;
			stackUp(y, x);
		}
		else if (map[y][x - 1] < '3' && map[y][x - 1] != '0')
		{
			x--;
			stackUp(y, x);
		}
		else if (map[y - 1][x] < '3' && map[y - 1][x] != '0')
		{
			y--;
			stackUp(y, x);
		}
		else
			return true;

		break;
	case 4:
		if (map[y][x + 1] < '3' && map[y][x + 1] != '0')
		{
			x++;
			stackUp(y, x);
		}
		else if (map[y][x - 1] < '3' && map[y][x - 1] != '0')
		{
			x--;
			stackUp(y, x);
		}
		else if (map[y + 1][x] < '3' && map[y + 1][x] != '0')
		{
			y++;
			stackUp(y, x);
		}
		else
			return true;

		break;
	}
	return false;
}

void moveRand(int& random, bool& isTrue, int& y, int& x, stack<int>& stX, stack<int>& stY)
{
	switch (random)
	{
	case 1:
		if (map[y][x + 1] < '3' && map[y][x + 1] != '0')
		{
			x++;
			stackUp(y, x);
		}
		else if (findNum(random, y, x))
		{ 
			isTrue = true;
		}
		break;
	case 2:
		if (map[y][x - 1] < '3' && map[y][x - 1] != '0')
		{
			x--;
			stackUp(y, x);
		}
		else if (findNum(random, y, x))
		{
			isTrue = true;
		}
		break;
	case 3:
		if (map[y + 1][x] < '3' && map[y + 1][x] != '0')
		{
			y++;
			stackUp(y, x);
		}
		else if (findNum(random, y, x))
		{
			isTrue = true;
		}
		break;
	case 4:
		if (map[y - 1][x] < '3' && map[y - 1][x] != '0')
		{
			y--;
			stackUp(y, x);
		}
		else if (findNum(random, y, x))
		{
			isTrue = true;
		}
		break;
	}
	if (!isTrue)
	{
		// 이 작업을 반복할 때마다 push를 해준다
		stX.push(x);
		stY.push(y);
	}
	map[y][x] = '0';
}

bool canGo(int x, int y)
{
	bool isGo = false;
	if (map[y][x + 1] == '0')
	{
		isGo = true;
	}
	else if (map[y - 1][x] == '0')
	{
		isGo = true;
	}
	else if (map[y + 1][x] == '0')
	{
		isGo = true;
	}
	else if (map[y][x - 1] == '0')
	{
		isGo = true;
	}

	return isGo;
}

void findWay()
{
	int x = 0; // 입구 x 값
	int y = 2; // 입구 y 값
	int exitX = 19; // 출구 x 값
	int exitY = 17; // 출구 y 값
	stack<int> stX;
	stack<int> stY;

	stack<int> dontGoX; // 가면 안되는 곳 X 값
	stack<int> dontGoY; // 가면 안되는 곳 Y 값

	stX.push(x);
	stY.push(y);

	dontGoX.push(100);
	dontGoY.push(100);

	while (true)
	{
		if (map[y][x + 1] == '0' && map[y][x + 1] != '@')
		{
			map[y][x + 1] = ' ';
			x++;
		}
		else if (map[y - 1][x] == '0' && map[y - 1][x] != '@')
		{
			map[y - 1][x] = ' ';
			y--;
		}
		else if (map[y + 1][x] == '0' && map[y + 1][x] != '@')
		{
			map[y + 1][x] = ' ';
			y++;
		}
		else if (map[y][x - 1] == '0' && map[y][x - 1] != '@')
		{
			map[y][x - 1] = ' ';
			x--;
		}
		else
		{
			map[stY.top()][stX.top()] = '0';
			stX.pop(); stY.pop();
			if (canGo(stX.top(), stY.top()))
			{
				map[y][x] = '@'; // @는 못가는 곳
			}
			x = stX.top();
			y = stY.top();
			continue;
		}
		stX.push(x);
		stY.push(y);
		if (stX.top() == exitX && stY.top() == exitY)
			break;
	}
}

void makeMap()
{
	//map[2][1];
	int y = 2;
	int x = 1;
	bool isTrue = false;
	int random;
	stack<int> stX;
	stack<int> stY;

	map[y][x] = '0';
	//스택을 쌓아주는 함수 - (처음에는 벽 빼고 모든 곳이 '1'이며 스택을 점점 쌓아가게 되어 모든 곳이 '3'이 되게 한다)
	// ex {
	// 1 1 1 1 1 1 1 1 1 1
	// 2 2 2 2 2 2 1 1 1 1
	// 0 0 0 0 0 0 2 1 1 1
	// 2 2 3 0 3 2 1 1 1 1
	// 1 2 0 0 2 1 1 1 1 1
	// }
	stackUp(y, x);
	stX.push(x);
	stY.push(y);
	while (true)
	{
		if (!isTrue)
		{
			random = rand() % 4 + 1;
			//랜덤의 방향으로 길이 생기도록 하게하는 함수
			moveRand(random, isTrue, y, x, stX, stY);
		}
		if(isTrue)
		{
			isTrue = false;

			// 스택 pop을 한 뒤 x와 y에 top 값을 저장
			stX.pop(); stY.pop();
			y = stY.top(); x = stX.top(); 
			// 다시 주변의 숫자들을 검사하기
			moveRand(random, isTrue, y, x, stX, stY);
		}

		if (stX.top() == 1 && stY.top() == 2) // 스택이 가장 처음으로 돌아온다면 while문 나가기
		{
			break;
		}
	}

	for (int y = 0; y < 20; y++) // map에서 '4'와 '3'을 '1'로 바꿔주는 코드
	{
		for (int x = 0; x < 21; x++)
		{
			if (map[y][x] == '4' || map[y][x] == '3')
			{
				map[y][x] = '1';
			}
		}
	}

	map[18][17] = '0';

	findWay();

	for (int y = 0; y < 20; y++) // map에서 '4'와 '3'을 '1'로 바꿔주는 코드
	{
		for (int x = 0; x < 21; x++)
		{
			if (map[y][x] == '@')
			{
				map[y][x] = '0';
			}
		}
	}
	system("cls");
	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 21; x++)
		{
			cout << map[y][x] << ' '; // 띄어쓰기 하는게 보기 좋아서 했어요..
		}
		cout << endl;
	}
}

int main()
{
	srand(time(NULL));
	makeMap();

}

