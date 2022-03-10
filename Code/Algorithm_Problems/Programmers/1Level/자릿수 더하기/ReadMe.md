```
    문제 설명
    자연수 N이 주어지면, N의 각 자릿수의 합을 구해서 return 하는 solution 함수를 만들어 주세요.
    예를들어 N = 123이면 1 + 2 + 3 = 6을 return 하면 됩니다.

    제한사항
    N의 범위 : 100,000,000 이하의 자연수
    입출력 예
    N	answer
    123	6
    987	24
    입출력 예 설명
    입출력 예 #1
    문제의 예시와 같습니다.

    입출력 예 #2
    9 + 8 + 7 = 24이므로 24를 return 하면 됩니다.
```

- 풀이 코드

```cpp
    #include <iostream>

    using namespace std;
    int solution(int n)
    {
        int answer = 0;
        int num = 100000000;
        
        while(num > 0)
        {
            if(n != n % num)
            {
                answer += n / num;
                n %= num;
            }
            num /= 10;
        }
        

        return answer;
    }
```

- 모든 자릿수의 합을 구해서 리턴하는 함수이다.
- int 중 가장 큰 단위인 억 단위부터 나눠가며 자릿수마다의 값을 구하고 더해가며 답을 구해나갔다.
- 방법을 한번 고안해내고 나서는 빠르게 문제를 풀 수 있었다.