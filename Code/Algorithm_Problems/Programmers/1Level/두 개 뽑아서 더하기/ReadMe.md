```
    문제 설명
    정수 배열 numbers가 주어집니다. numbers에서 서로 다른 인덱스에 있는 두 개의 수를 뽑아 더해서 만들 수 있는 모든 수를 배열에 오름차순으로 담아 return 하도록 solution 함수를 완성해주세요.

    제한사항
    numbers의 길이는 2 이상 100 이하입니다.
    numbers의 모든 수는 0 이상 100 이하입니다.
    입출력 예
    numbers	result
    [2,1,3,4,1]	[2,3,4,5,6,7]
    [5,0,2,7]	[2,5,7,9,12]
    입출력 예 설명
    입출력 예 #1

    2 = 1 + 1 입니다. (1이 numbers에 두 개 있습니다.)
    3 = 2 + 1 입니다.
    4 = 1 + 3 입니다.
    5 = 1 + 4 = 2 + 3 입니다.
    6 = 2 + 4 입니다.
    7 = 3 + 4 입니다.
    따라서 [2,3,4,5,6,7] 을 return 해야 합니다.
    입출력 예 #2

    2 = 0 + 2 입니다.
    5 = 5 + 0 입니다.
    7 = 0 + 7 = 5 + 2 입니다.
    9 = 2 + 7 입니다.
    12 = 5 + 7 입니다.
    따라서 [2,5,7,9,12] 를 return 해야 합니다.
```

- 풀이 코드

```cpp
    #include <string>
    #include <algorithm>
    #include <vector>

    using namespace std;

    vector<int> solution(vector<int> numbers) {
        vector<int> answer;
        int temp = 0;
        
        for(int i = 0; i < numbers.size(); i++)
        {
            for(int n = 0; n < numbers.size(); n++)
            {
                if(i == n) continue;
                
                if(find(answer.begin(), answer.end(), numbers[i] + numbers[n]) == answer.end())
                {
                    answer.emplace_back(numbers[i] + numbers[n]);
                }
            }
        }
        
        sort(answer.begin(), answer.end());
        
        return answer;
    }
```

- 이 문제에서는 예전 문제에 사용한 find, sort를 주로 한 문제였기에 그리 어려운 과정 없이 풀이 할 수 있었다.