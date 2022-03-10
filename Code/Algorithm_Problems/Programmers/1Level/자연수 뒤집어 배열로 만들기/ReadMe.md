```
    문제 설명
    자연수 n을 뒤집어 각 자리 숫자를 원소로 가지는 배열 형태로 리턴해주세요. 예를들어 n이 12345이면 [5,4,3,2,1]을 리턴합니다.

    제한 조건
    n은 10,000,000,000이하인 자연수입니다.
    입출력 예
    n	return
    12345	[5,4,3,2,1]
```

- 풀이 코드

```cpp
    #include <string>
    #include <vector>

    using namespace std;

    vector<int> solution(long long n) {
        vector<int> answer;
        long long num = 10000000000;
        int count = 11;
        while (count != 0)
        {
            if (n != n % num)
            {
                answer.push_back(n / num);
                n %= num;
            }
            else if (answer.size() > 0)
            {
                answer.push_back(0);
            }
            num /= 10;
            count--;
        }
        
        for (int i = 0; i < answer.size() / 2; i++)
        {
            int temp = answer[i];
            answer[i] = answer[answer.size() - (i + 1)];
            answer[answer.size() - (i + 1)] = temp;
        }
        
        return answer;
    }
```

- 자연수를 입력 받으면 그 값을 거꾸로 해서 배열의 형태로 저장시켜주는 함수이다.
- long long에서 가장 큰 단위인 100억부터 해서 /, %를 잘 활용해서 자릿수마다의 값을 구하고 배열에 잘 넣어주어서 풀 수 있었다.