```
    1. 피보나치수열 구현
    2. 하노이 탑 구현하기 (재귀함수 사용)
    3. n값을 입력 받아 1부터 n까지의 덧셈 구현하기 (재귀함수 필수 사용)
    4. 입력받은 십진수를 거꾸로 출력하는 프로그램 작성하기 (재귀함수 필수 사용)
```

- 풀이 코드

```cpp
    // 1번 문제

    #include <iostream>
    using namespace std;
    
    void Fibonacci(int *a, int max, int min)
    {
        a[0] = 0;
        a[1] = 1;
        if (max == 2)
        {
            for (int i = 0; i < 30; i++)
            {
                cout << a[i] << " ";
            }
            return;
        }
        else 
        {
            a[min + 1] = a[min - 1] + a[min];
            Fibonacci(a, --max, ++min);
        }
    }
    
    int main()
    {
        int const Max = 30;
        int Min = 1;
        int fibonacci[Max] = {0, };
        Fibonacci(fibonacci, Max, Min);
    }
```

- 피보나치 수열의 최대값을 입력 받으면 그 결과값을 배열에 넣는 과정을 출력하는 코드이다.
- 재귀함수가 반복되며 피보나치수열의 이전 값들을 알아야 했기에 포인터를 사용해서 배열을 가져온 것 이외에는 특별한 것 없이 간단하게 풀었다.

```cpp
    // 2번 문제

    #include <iostream>
    using namespace std;
    
    void Hanoi(int num, char from, char by, char to)
    {
        if (num == 1)
        {
            cout << "원반 1을" << from << "에서 " << to << "로 이동" << endl;
        }
        else 
        {
            Hanoi(num - 1, from, to, by);
    
            cout << "원반" << num << "을(를)" << from << "에서 " << to << "로 이동" << endl;
    
            Hanoi(num - 1, by, from, to);
        }
    }
    
    int main()
    {
        Hanoi(3, 'A', 'B', 'C');
    }
```

- 하노이 탑을 구하는 과정을 텍스트로 구현한 코드이다
- 하노이 탑을 어떻게 해야 코드로 나타 낼 수 있을까? 하고 나온 방법이 텍스트로 나타내는 것이다. 이 방법으로 구현을 하고자 하고 얼마 되지 않아서 완성 할 수 있었다.

```cpp
    // 3번 문제

    #include <iostream>
    using namespace std;
    
    int all = 0;
    
    int Function(int a)
    {
        if (a == 0) {
            return all;
        }
        all += a;
        return Function(--a);
    }
    
    int main()
    {
        int temp;
        cin >> temp;
        cout << Function(temp) << endl;
    }
```

- 0부터 n까지의 수를 다 더해서 그 결과값을 재귀함수를 사용해서 출력하는 함수이다.
- 가장 큰 값부터 1씩 빼가며 더하면 된다는 것과 재귀함수가 뭔지를 알고 있었기에 쉽게 풀 수 있었다.

```cpp
    #include <iostream>
    #include <vector>
    using namespace std;
    
    void Isize(int num, int& count)
    {
        if (num <= 0)
            return;
        else 
        {
            num /= 10;
            Isize(num, ++count);
        }
    }
    
    void Bonus(int num, int count, int ex, int* arr)
    {
        for (int i = 1; i < count; i++)
        {
            ex *= 10;
        }
        for (int i = 0; i < count; i++)
        {
            arr[i] = num / ex;
            num -= arr[i] * ex;
            ex /= 10;
        }
        for (int i = count - 1; i >= 0; i--)
        {
            cout << arr[i];
        }
    }
    
    int main()
    {
        int num = 0;
        int count = 0;
        int ex = 1;
        int exTemp = 0;
        cin >> num;
        Isize(num, count);
        int* arr = new int[count];
        int* arrTemp = new int[count];
        Bonus(num, count, ex, arr);
    }
```

- 정수를 입력 받아 그 수의 길이를 구하고 해당하는 수를 거꾸로 출력하는 함수이다.
- 10진수 정수를 거꾸로 만들기 위해서 여러 방법을 생각했는데 결국 나온 방법이 1의 자리수부터 천천히 나눠가는 것이였다. 이 방법을 주로하여 풀이하였다.
- 약 1년이 지난 지금 이 코드를 보며 느낀점으로 변수명과 함수명이 매우 좋지 않아보인다는 것이다.