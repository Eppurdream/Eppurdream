```
    문제 설명
    0부터 9까지의 숫자 중 일부가 들어있는 정수 배열 numbers가 매개변수로 주어집니다. numbers에서 찾을 수 없는 0부터 9까지의 숫자를 모두 찾아 더한 수를 return 하도록 solution 함수를 완성해주세요.

    제한사항
    1 ≤ numbers의 길이 ≤ 9
    0 ≤ numbers의 모든 원소 ≤ 9
    numbers의 모든 원소는 서로 다릅니다.
    입출력 예
    numbers	result
    [1,2,3,4,6,7,8,0]	14
    [5,8,4,0,6,7,9]	6
    입출력 예 설명
    입출력 예 #1

    5, 9가 numbers에 없으므로, 5 + 9 = 14를 return 해야 합니다.
    입출력 예 #2

    1, 2, 3이 numbers에 없으므로, 1 + 2 + 3 = 6을 return 해야 합니다.
```

- 풀이 코드 

```cpp
    #include <string>
    #include <vector>

    using namespace std;

    int solution(vector<int> numbers) {
        int answer = 0;
        bool isSame = false;
        
        for(int i = 0; i < 10; i++)
        {
            isSame = true;
            
            for(int n = 0; n < numbers.size(); n++)
            {
                if(numbers[n] == i)
                {
                    isSame = false;
                    break;
                }
            }
            
            if(isSame)
            {
                answer += i;
            }
        }
        
        return answer;
    }
```

- 있는 수와 없는 수를 확실히 구분하기 위해서 bool 변수과 이중for문 을 사용해서 풀었다
- 이런 류의 코딩은 많이 해봤기 때문에 아직도 조금 기억에 남아있는게 신기했었다