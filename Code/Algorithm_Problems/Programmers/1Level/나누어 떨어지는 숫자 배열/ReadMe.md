```
    문제 설명
    array의 각 element 중 divisor로 나누어 떨어지는 값을 오름차순으로 정렬한 배열을 반환하는 함수, solution을 작성해주세요.
    divisor로 나누어 떨어지는 element가 하나도 없다면 배열에 -1을 담아 반환하세요.

    제한사항
    arr은 자연수를 담은 배열입니다.
    정수 i, j에 대해 i ≠ j 이면 arr[i] ≠ arr[j] 입니다.
    divisor는 자연수입니다.
    array는 길이 1 이상인 배열입니다.
    입출력 예
    arr	divisor	return
    [5, 9, 7, 10]	5	[5, 10]
    [2, 36, 1, 3]	1	[1, 2, 3, 36]
    [3,2,6]	10	[-1]
    입출력 예 설명
    입출력 예#1
    arr의 원소 중 5로 나누어 떨어지는 원소는 5와 10입니다. 따라서 [5, 10]을 리턴합니다.

    입출력 예#2
    arr의 모든 원소는 1으로 나누어 떨어집니다. 원소를 오름차순으로 정렬해 [1, 2, 3, 36]을 리턴합니다.

    입출력 예#3
    3, 2, 6은 10으로 나누어 떨어지지 않습니다. 나누어 떨어지는 원소가 없으므로 [-1]을 리턴합니다.
```

- 풀이 코드

```cpp
    #include <string>
    #include <vector>

    using namespace std;

    vector<int> solution(vector<int> arr, int divisor) {
        vector<int> answer;
        
        for(int i = 0; i < arr.size(); i++)
        {
            if(arr[i] % divisor == 0)
            {
                answer.push_back(arr[i]);
            }
        }
        
        for(int i = 0; i < answer.size(); i++)
        {
            for(int j = 0; j < answer.size(); j++)
            {
                if(answer[i] < answer[j])
                {
                    int temp = answer[i];
                    answer[i] = answer[j];
                    answer[j] = temp;
                }
            }
        }
        
        if(answer.size() == 0)
        {
            answer.push_back(-1);
        }
        
        return answer;
    }
```

- 나머지 연산자를 사용하고 정렬만 하면 되었기 때문에 간단하게 풀이했다.