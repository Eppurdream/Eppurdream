```
    문제 설명
    두 수를 입력받아 두 수의 최대공약수와 최소공배수를 반환하는 함수, solution을 완성해 보세요. 배열의 맨 앞에 최대공약수, 그다음 최소공배수를 넣어 반환하면 됩니다. 예를 들어 두 수 3, 12의 최대공약수는 3, 최소공배수는 12이므로 solution(3, 12)는 [3, 12]를 반환해야 합니다.

    제한 사항
    두 수는 1이상 1000000이하의 자연수입니다.
    입출력 예
    n	m	return
    3	12	[3, 12]
    2	5	[1, 10]
    입출력 예 설명
    입출력 예 #1
    위의 설명과 같습니다.

    입출력 예 #2
    자연수 2와 5의 최대공약수는 1, 최소공배수는 10이므로 [1, 10]을 리턴해야 합니다.
```

- 풀이 코드

```cpp
    #include <string>
    #include <vector>

    using namespace std;

    vector<int> solution(int n, int m) {
        vector<int> answer;
        
        if(n > m)
        {
            int temp = m;
            m = n;
            n = temp;
        }
        
        int min = 0;
        int max = 0;
        
        for(int i = 1; i <= n; i++)
        {
            if(n % i == 0 && m % i == 0)
            {
                min = i;
            }
        }
        
        max = n * (m / min);
        
        answer.push_back(min);
        answer.push_back(max);
        
        return answer;
    }
```

- 주어진 두 정수의 최대공약수와 최소공배수를 구해서 배열의 형식으로 리턴해주는 함수이다.
- 먼저 계속 최소공배수를 구할때 까지 반복하고나서 이후에 최대공약수는 공식을 통해서 구한 뒤 나머지 작업을 해주었다.
- 굳이 노가다 작업을 하기 싫어서 공식이 있나하고 찾아보았는데 있어서 그대로 사용하게 되었다.