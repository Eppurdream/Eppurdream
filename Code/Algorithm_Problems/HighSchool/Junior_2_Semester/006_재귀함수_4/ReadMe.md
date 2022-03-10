```
    1. 숫자 n을 입력받아 n부터 1까지의 숫자를 역순으로 출력하기(재귀함수 필수)
    2. 숫자 2개를 입력 받아 두 수 사이의 홀수 출력(재귀함수 필수)
    3. 숫자 2개를 입력 받아 두 수 사이의 짝수 출력하기(재귀함수 필수)
```

- 풀이 코드

```cpp
    // 1번 문제

    #include <iostream>
    using namespace std;
    
    void Reverse(int num)
    {
        if (num == 0)
            return;
        cout << num << endl;
        Reverse(--num);
    }
    
    int main()
    {
        int num = 0;
        cin >> num;
        Reverse(num);
    }
```

- 입력 받은 수부터 1까지 모두 출력하는 함수
- 이전에 재귀함수를 사용하며 충분히 익숙해졌기에 구조를 빠르게 짤 수 있었고 문제도 빠르게 풀 수 있었다.
- 이 코드를 쓰기 전 선생님이 함수명을 내용에 맞는 이름으로 작성하라고 하셔서 이전보다는 좋아진 느낌이다.

```cpp
    // 2번 문제

    #include <iostream>
    using namespace std;
    
    void func(int num1, int num2)
    {
        if (num1 > num2)
            return;
        if (num1 % 2 == 1)
        {
            cout << num1 << endl;
            func(num1 += 2, num2);
        }
        else
        {
            func(++num1, num2);
        }
    }
    
    int main()
    {
        int num1 = 0;
        int num2 = 0;
        cout << "첫 번째 수 입력";
        cin >> num1;
        cout << "두 번째 수 입력";
        cin >> num2;
    
        cout << num1 << "과 " << num2 << "의 홀수들" << endl;
        func(num1, num2);
    }
```

- 정수를 입력 받으면 두 정수 사이의 모든 홀수들을 출력하는 함수이다.
- 재귀함수의 구조를 짜는 것은 어렵지 않았으며 나머지 연산자를 활용해서 더욱 간단히 코드를 작성하였다.

```cpp
    // 3번 문제

    #include <iostream>
    using namespace std;
    
    void func(int num1, int num2)
    {
        if (num1 > num2)
            return;
        if (num1 % 2 != 1)
        {
            cout << num1 << endl;
            func(num1 += 2, num2);
        }
        else
        {
            func(++num1, num2);
        }
    }
    
    int main()
    {
        int num1 = 0;
        int num2 = 0;
        cout << "첫 번째 수 입력";
        cin >> num1;
        cout << "두 번째 수 입력";
        cin >> num2;
    
        cout << num1 << "과 " << num2 << "의 짝수들" << endl;
        func(num1, num2);
    }
```

- 정수 두 개를 입력 받아서 두 수 사이의 모든 짝수를 출력하는 함수이다.
- 이미 홀수를 출력하는 코드를 작성한 적이 있었기에 나머지 연산하는 부분만 조금 수정해서 코드를 작성하였다.