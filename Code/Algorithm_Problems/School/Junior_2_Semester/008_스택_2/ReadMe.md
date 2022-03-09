```
    1. 스택을 활용한 미로 
    - 미로를 표현하기 위해 2차원 배열을 이용하여 '1'은 막힌 길이라고 가정하고, '0'은 통과할 수 있는 길로 표현한다. 미로에서 길을 찾는 프로그램을 작성해라.
    - 일정한 크기의 미로 안에서 길이 실행할 때마다 랜덤하게 생성되어 그 때마다 각기 다른 길을 찾는 프로그램 작성
```

- 문제 풀이

```cpp
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
```

- 랜덤으로 모양이 생성된 미로의 길을 알려주는 코드이다.
=========================================================
ex) 결과값
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1  
1 0 1 0 1 0 0 1 0 1 0                 1  
0         1         1   1 1 1 1 0 1   1  
1 1 1 1       1 1       1 0 0 1 1     1  
1       1 1 1 0 1 0 1 1 0 1         1 1  
1   1             1           1 1 1 0 1  
1     1 1 1 1 1       1 1 1 1 0 0 1 0 1  
1 1   1 0 0 0 0 1 0 1 0 0 0 1 1 0 0 0 1  
1 0   1 1 1 0 1 0 1 0 0 1 0 0 0 0 1 0 1  
1 1                 1 1 0 1 1 1 1 0 0 1  
1 0 1 1 0 1 1 1 1                   1 1  
1 0 0 0 1 0 0 0 1 0 1 0 1 0 1 1 1   1 1  
1 0 1 0 0 0 1 0 0 1 0 1 0 1 0 0 1     1  
1 0 0 1 1 1 0 1 0 0 0 0 0 0 0 1 1 1   1  
1 1 0 0 0 0 0 0 1 1 1 0 1 1 0 0 1     1  
1 0 1 1 1 1 1 0 0 0 1 0 0 0 1 1     1 1  
1 0 0 0 0 0 0 1 1 0 1 1 1 0 1 1   1 1 1  
1 0 1 1 1 1 1 0 1 0 0 0 1 0 0 0          
1 0 0 0 0 0 0 0 0 0 1 0 0 1 0 1 1 0 0 1  
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1  
=========================================================
- 이 문제를 처음 만났을 때 처음으로 벽에 막힌 느낌이였다. 그래서 어떻게든 풀기 위해서 알고리즘을 생각해내려고 노력했으며 주변에 질문을 참 많이 했던 기억이 난다.
- 이 코드를 다시 돌아보면 참 가독성이 낮고 복잡하게 작성한 것 같다. 그래도 비교적 예전보다는 함수명이나 변수명이 나아진것이 보인다