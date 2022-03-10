```
    1. n퀸 문제
```

- 풀이 코드

```cpp
    #include <iostream>
    #include <vector>
    using namespace std;

    void solution(int n)
    {
        bool isPush = true;

        vector<int> vec; // 퀸의 위치를 담을 벡터
        vec.push_back(0); // 처음 퀸은 0부터 시작

        while (true)
        {
            for (int i = 0; i < n * n; i++)
            {
                isPush = true; // 항상 반복문을 반복 할때마다 true로 초기화

                for (int j = 0; j < vec.size(); j++)
                {
                    if (vec[j] / n == i / n || vec[j] % n == i % n) // vec[j] / n 을 통해서 세로의 값 유추, vec[j] % n 을 통해서 가로의 값 유추
                    {
                        isPush = false;
                        break;
                    }
                    else
                    {
                        // 대각선을 조건문으로
                        for (int f = 1; f <= n; f++)
                        {
                            if ((vec[j] + (n * f) + f == i && vec[j] % n < n - f)
                                || (vec[j] + (n * f) - f == i && vec[j] % n > f - 1)
                                || (vec[j] - (n * f) + f == i && vec[j] % n < n - f)
                                || (vec[j] - (n * f) - f == i && vec[j] % n > f - 1))
                            {
                                isPush = false;
                                break;
                            }
                        }

                        if (!isPush) break;
                    }
                }

                if (isPush) // 가로, 세로, 대각선의 조건을 다 피해갔을 경우 실행
                {
                    vec.push_back(i);
                }
            }

            // vec의 크기가 n과 같을 경우 해당하는 체스판을 출력 후 리턴
            if (vec.size() == n)
            {
                for (int y = 0; y < n; y++)
                {
                    for (int x = 0; x < n; x++)
                    {
                        if (find(vec.begin(), vec.end(), (y * n) + x) == vec.end())
                        {
                            cout << "* ";
                        }
                        else
                        {
                            cout << "# ";
                        }
                    }
                    cout << endl;
                }

                return;
            }

            // 만약 n 보다 vec의 크기가 작을 경우
            // 가장 끝에 있는 값 삭제 후 
            // ++ 해가며 다른 퀸과 만나지 않는지 조사 하고
            // 만나지 않는 경우 다시 처음 부터 0 부터 n * n 까지 조사 한다

            while (true)
            {
                if (vec.size() == 0) break; // vec

                if (vec.size() == n) vec.pop_back();

                vec[vec.size() - 1]++;

                isPush = true;

                for (int j = 0; j < vec.size() - 1; j++)
                {
                    if (vec[j] / n == vec[vec.size() - 1] / n || vec[j] % n == vec[vec.size() - 1] % n)
                    {
                        isPush = false;
                        break;
                    }
                    else
                    {
                        for (int f = 1; f <= n; f++)
                        {
                            if ((vec[j] + (n * f) + f == vec[vec.size() - 1] && vec[j] % n < n - f)
                                || (vec[j] + (n * f) - f == vec[vec.size() - 1] && vec[j] % n > f - 1)
                                || (vec[j] - (n * f) + f == vec[vec.size() - 1] && vec[j] % n < n - f)
                                || (vec[j] - (n * f) - f == vec[vec.size() - 1] && vec[j] % n > f - 1))
                            {
                                isPush = false;
                                break;
                            }
                        }
                        if (!isPush) break;
                    }
                }

                if (vec[vec.size() - 1] >= n * n) // 크기가 n * n 보다 클 경우
                {
                    vec.pop_back();
                    continue;
                }
                else if (!isPush)
                {
                    continue;
                }

                break;
            }

            if (vec.size() == 0) break; // 값이 없을 경우 나감

            if (vec.size() == 1 && vec[0] > n) break; // 1개 남은 값이 n 보다 클 경우 나감
        }

        cout << "퀸을 n 만큼 놓을 수 있는 자리가 없습니다" << endl;
        return;
    }

    int main()
    {
        int n = 0;
        cin >> n;

        solution(n);

        return 0;
    }
```

- n개의 퀸을 n * n의 체스판에 서로 잡지 못하는 위치에 배치하는 코드이다.
- 원래의 계획은 n * n의 체스판에 n개의 퀸을 놓을 수 있는 경우의 수가 총 몇개 있는지에 대한 코드를 작성하려 했지만 어쩌다 보니 이렇게 코드가 변환되었다.
- 퀸의 가로, 세로, 대각선을 계산하기 위해서 조건문을 한번에 4번씩 사용하다보니 매우 헷갈리는 느낌이 있었다.
