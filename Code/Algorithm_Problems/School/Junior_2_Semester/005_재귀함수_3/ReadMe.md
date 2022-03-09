```
    1. 숫자를 5개 입력 받아 그 중 최댓값을 출력하는 프로그램 작성하기(재귀함수 필수)
    2. 4자리 이상의 수를 입력 받아 각 자리수의 합을 구하는 프로그램 작성하기(재귀함수 필수)
    3. 구구단을 출력하는 프로그램 작성하기(재귀함수 필수)
```

- 풀이 코드

```cpp
    // 1번 문제

    #include <iostream>
    using namespace std;
    
    void MaxNum(int num, int &num2, int count)
    {
        if (count == 0)
            return;
        cout << "숫자 입력 : ";
        cin >> num;
        if (num > num2)
            num2 = num;
        MaxNum(num, num2, --count);
    }
    
    int main()
    {
        int num = 0;
        int num2 = 0;
        int count = 0;
        cout << "몇개의 숫자를 입력하실건가요 : ";
        cin >> count;
    
        MaxNum(num, num2, count);
        cout << "가장 큰 숫자는 " << num2 << " 입니다" << endl;
    }
```

- 몇개의 숫자를 입력하면 그 중 가장 큰 수를 골라서 출력해주는 코드이다
- 재귀함수로 이걸 어떻게 할건지 생각을 했는데 입력 할때마다 큰지 작은지를 비교해서 하는 방법을 사용하였다. 비교해서 큰 값은 & 키워드를 사용해서 함수가 끝나도 저장 될 수 있도록 코드를 작성하였다. 

```cpp
    // 2번 문제

    #include <iostream>
    using namespace std;
    
    void Isize(int num, int &count, int& ex)
    {
        if (num <= 0)
        {
            ex /= 10;
            return;
        }
        Isize(num / 10, ++count, ex *= 10);
    }
    
    void Sum(int num, int ex, int sum, int temp)
    {
        if (ex <= 0)
        {
            cout << sum << endl;
            return;
        }
        else
        {
            temp = num / ex;
            sum += temp;
            num -= ex * temp;
            ex /= 10;
            Sum(num, ex, sum, temp);
        }
    }
    
    int main()
    {
        int num = 0;
        int count = 0;
        int ex = 1;
        int sum = 0;
        int temp = 0;
        cin >> num;
        Isize(num, count, ex);
        Sum(num, ex, sum, temp);
    }
```

- 어떠한 정수를 입력받아서 그 자리수에 맞는 수들을 모두 더해서 출력하는 코드이다.
- 처음 입력 받은 수의 길이를 구하고 그 길이를 이용해서 첫번째 자리부터 나눠가며 그 값들을 하나씩 더해가며 총 합을 구하였다. 이전에 이와 비슷한 알고리즘을 작성한 기억이 있어서 그걸 비슷하게 가져와서 사용했다.

```cpp
    // 3번 문제

    #include <iostream>
    using namespace std;
    
    void Multi(int i1, int i2)
    {
        cout << i1 << " x " << i2 << " = " << i1 * i2 << endl;
        if (i1 == 9 && i2 == 9)
            return;
        if (i2 == 9)
        {
            i1++;
            i2 = 0;
        }
        Multi(i1, ++i2);
    }
    
    int main()
    {
        int i1 = 2;
        int i2 = 1;
        Multi(i1, i2);
    }
```

- 구구단 중 2단부터 9단 까지 모두 출력하게 하는 코드이다.
- 구구단의 처음부터 끝까지 출력해야 하기에 변수를 2개를 만들어서 하나하나 더해가며 출력하였다.
- 지금까지는 재귀함수 대신 반복문을 사용하는 것이 더욱 편한 경우가 많았는데 이번 문제에서는 재귀함수를 더 편하게 사용할 수 있었던 것을 느꼇던 것 같다.