```
    문제 설명
    정수를 담고 있는 배열 arr의 평균값을 return하는 함수, solution을 완성해보세요.

    제한사항
    arr은 길이 1 이상, 100 이하인 배열입니다.
    arr의 원소는 -10,000 이상 10,000 이하인 정수입니다.
    입출력 예
    arr	return
    [1,2,3,4]	2.5
    [5,5]	5
```

- 풀이 코드

```cpp
    #include <string>
    #include <vector>

    using namespace std;

    double solution(vector<int> arr) {
        double answer = 0;
        int sum = 0;
        
        for(int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
        }
        answer = (double)sum / arr.size();
        
        return answer;
    }
```

- 정수를 담고 있는 배열안에 있는 모든 배열들의 평균값을 리턴하는 함수이다.
- 초등학교때부터 평균값 구하는 것을 해왔기에 코드 작성하는데에 많은 시간이 걸리지 않았다.