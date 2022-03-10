```
    문제 설명
    임의의 양의 정수 n에 대해, n이 어떤 양의 정수 x의 제곱인지 아닌지 판단하려 합니다.
    n이 양의 정수 x의 제곱이라면 x+1의 제곱을 리턴하고, n이 양의 정수 x의 제곱이 아니라면 -1을 리턴하는 함수를 완성하세요.

    제한 사항
    n은 1이상, 50000000000000 이하인 양의 정수입니다.
    입출력 예
    n	return
    121	144
    3	-1
    입출력 예 설명
    입출력 예#1
    121은 양의 정수 11의 제곱이므로, (11+1)를 제곱한 144를 리턴합니다.

    입출력 예#2
    3은 양의 정수의 제곱이 아니므로, -1을 리턴합니다.
```

- 풀이 코드

```cpp
    #include <string>
    #include <vector>

    using namespace std;

    long long solution(long long n) {
        long long answer = 0;
        
        for (long long i = 0; i * i <= n; i++)
        {
            if (i * i == n)
            {
                long long iplus = i + 1;
                answer = iplus * iplus;
                break;
            }
        }
        
        if(answer == 0) answer = -1;
        
        return answer;
    }
```

- 정수를 입력 받으면 그 정수의 제곱근이 양의 정수인지 아닌지 판단하고 그에 따라 맞다면 +1한것의 제곱을 리턴, 아니라면 -1을 리턴하는 함수이다.
- 그냥 간단한 반복문을 사용해서 풀이하였지만 속도가 매우 느리다는 단점이 있다.