```
    1. 파스칼의 삼각형 문제

    2. 다차원 배열을 이용하여 문자열을 3개 이상 입력 받아 입력 받은 문자열을 거꾸로 출력하는 프로그램을 작성해보시오.
```

- 풀이 코드

```cpp
    // 1번문제 풀이 코드

    #include <iostream>
    using namespace std;
    
    int main()
    {
        int a[10][10]{ 0, };
    
        for (int i = 0; i < 10; i++)
        {
            a[i][0] = 1;
        }
    
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (j > 0 && i > 0)
                {
                    a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
                }
                if (a[i][j] > 0)
                {
                    cout << a[i][j] << " ";
                }
            }
            cout << endl;
        }
    }
```

- 파스칼의 삼각형을 구현해서 그 값을 2차원 배열에 넣은 것을 출력해서 보여주는 코드이다.
- 이때 당시 다차원 배열에 그리 익숙하지 않은 상태였기에 파스칼의 삼각형의 값들을 넣는 과정에서 다차원 배열에 익숙해질 수 있는 기회였다

```cpp
    // 2번문제 풀이 코드

    #include <iostream>
    using namespace std;
    
    int main()
    {
        int size;
        cout << "(띄어쓰기는 '_'으로 하기)" << endl;
        cout << "문자열을 얼마나 입력 받으실건가요 : ";
        cin >> size;
    
        char** Pch = new char*[size];
    
        for (int i = 0; i < size; i++)
        {
            Pch[i] = new char[20];
            cin >> Pch[i];
        }
    
        char temp[20]; bool notNull = false;
        for (int i = 0; i < size; i++) {
            for (int j = 19; j >= 0; j--)
            {
                temp[j] = Pch[i][19 - j];
            }
            int n = 0;
            for (int j = 0; j < 20; j++)
            {
                if (notNull) {
                    Pch[i][n] = temp[j];
                    n++;
                }
                if (temp[j] != -51)
                    notNull = true;
                //cout << "temp[" << j << "] : " << (int)temp[j] << endl;
            }
            n = 0;
            notNull = false;
        }
        cout << endl;
    
        for (int i = 0; i < size; i++) {
            cout << i << "번째 문자열 : ";
            for (int j = 0; j < 20; j++)
            {
                if (Pch[i][j] == -51)
                    break;
                cout << Pch[i][j];
            }
            cout << endl;
        }
    }
```

- 문자열의 수를 입력 받으면 그 만큼의 문자열을 입력 받고 그 문자열들을 거꾸로 변환 시켜서 다시 출력하는 코드이다.
- 문자열의 수와 문자열마다의 길이가 각각 다르기에 동적 배열을 사용하게 되었고 이에 따라 new 키워드도 사용하게 되었다 new 라는 것을 처음 사용하였기에 적응하는데 매우 힘들었던 기억이 있다