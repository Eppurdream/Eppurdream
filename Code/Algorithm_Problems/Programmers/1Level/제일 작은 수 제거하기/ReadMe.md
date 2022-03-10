```
    문제 설명
    정수를 저장한 배열, arr 에서 가장 작은 수를 제거한 배열을 리턴하는 함수, solution을 완성해주세요. 단, 리턴하려는 배열이 빈 배열인 경우엔 배열에 -1을 채워 리턴하세요. 예를들어 arr이 [4,3,2,1]인 경우는 [4,3,2]를 리턴 하고, [10]면 [-1]을 리턴 합니다.

    제한 조건
    arr은 길이 1 이상인 배열입니다.
    인덱스 i, j에 대해 i ≠ j이면 arr[i] ≠ arr[j] 입니다.
    입출력 예
    arr	return
    [4,3,2,1]	[4,3,2]
    [10]	[-1]
```

- 풀이 코드

```cpp
    #include <string>
    #include <vector>
    #include <algorithm>

    using namespace std;

    vector<int> solution(vector<int> arr) {
        vector<int> answer;
        int lower = 200000000;
        
        if(arr.size() == 1) return vector<int>{ -1 };
        
        for(int i = 0; i < arr.size(); i++)
        {
            if(arr[i] < lower)
            {
                lower = arr[i];
            }
        }
        
        vector<int>::iterator iter = find(arr.begin(), arr.end(), lower);
        
        arr.erase(iter);
        
        answer = arr;
        
        return answer;
    }
```

- 주어진 배열의 가장 작은 값만 빼서 리턴해주는 함수이다.
- 문제에서 설명하는대로 코드를 그대로 작성하였더니 잘 작동이 되어서 어려움 없이 풀 수 있었다.