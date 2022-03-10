```
    1-1. 팩토리얼 함수 구현 (재귀함수만 사용)
    1-2. 팩토리얼 함수를 재귀함수를 사용하지 않고 구현하기
    2-1. 가우스의 계산법 구현하기
    2-2. 가우스의 계산법을 사용하지 않고 1부터 100까지의 덧셈 구현하기(무조건 재귀함수만 사용)
```

- 풀이 코드

```cpp
    // 1-1번 문제

    #include <iostream>
    using namespace std;
    
    int Fac(int i)
    {
        if (i == 0)
            return 1;
        else
            return i * Fac(i - 1);
    }
    
    int main()
    {
        int i;
        cin >> i;
        cout << Fac(i);
    }
```

- 팩토리얼을 재귀함수를 사용해서 구현해낸 코드이다.
- 팩토리얼을 구현하기 위해서 재귀함수를 반 강제로 사용하였는데 이를 통해서 조금이나마 재귀함수에 가까워 질 수 있었다.

```cpp
    // 1-2번 문제

    #include <iostream>
    using namespace std;
    
    int Fac(int i)
    {
        int num = 1;
        for (int n = i; n > 0; n--)
        {
            num *= n;
        }
        return num;
    }
    
    int main()
    {
        int i;
        cin >> i;
        cout << Fac(i);
    }
```

- 재귀함수를 사용하지 않고 팩토리얼을 구현한 코드이다.
- 재귀함수를 대체할 수 있는 것이 반복문이기에 반복문을 사용해서 풀이하였다.

```cpp
    // 2-1번 문제

    #include <iostream>
    using namespace std;
    //{ ( 1+n ) X n } / 2
    int Gaus(int n)
    {
        return ((1 + n) * n) / 2;
    }
    
    int main()
    {
        int i;
        cin >> i;
        cout << Gaus(i);
    }
```

- 가우스의 계산법을 사용하여 0부터 i까지의 합을 구한 코드이다.
- 가우스의 계산법을 그대로 가져다 쓰면 되기에 어렵지 않게 풀 수 있었다.

```cpp
    // 2-2번 문제

    #include <iostream>
    using namespace std;
    
    int Gaus(int i)
    {
        if (i == 0)
            return 0;
        else
            return i + Gaus(i - 1);
    }
    
    int main()
    {
        int i;
        cin >> i;
        cout << Gaus(i);
    }
```

- 가우스의 계산법을 공식을 사용하지 않고 재귀함수를 사용하여 푼 코드이다.
- 팩토리얼과 구조가 비슷하였기에 그대로 작성해서 풀 수 있었다.