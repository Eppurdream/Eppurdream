```
    문제 설명
    함수 solution은 정수 n을 매개변수로 입력받습니다. n의 각 자릿수를 큰것부터 작은 순으로 정렬한 새로운 정수를 리턴해주세요. 예를들어 n이 118372면 873211을 리턴하면 됩니다.

    제한 조건
    n은 1이상 8000000000 이하인 자연수입니다.
    입출력 예
    n	return
    118372	873211
```

- 풀이 코드

```cpp
    #include <string>
    #include <vector>
    #include <stdlib.h>

    using namespace std;

    long long solution(long long n) {
        long long answer = 0;
        
        string str = to_string(n);
        
        for(int i = 0; i < str.size(); i++)
        {
            for(int n = 0; n < str.size(); n++)
            {
                if(str[i] > str[n])
                {
                    char temp = str[i];
                    str[i] = str[n];
                    str[n] = temp;
                }
            }
        }
        
        answer = atoll(str.c_str());
        
        return answer;
    }
```

- 입력 받은 정수의 자릿수를 크기에 따라 오름차순으로 정렬한 뒤 리턴해주는 함수이다.
- 정수를 문자열로 바꾸고 버블 정렬로 어떻게 해준뒤 그걸 다시 정수로 바꿔서 리턴해주는 코드이다. 만약 라이브러리 함수를 사용하지 않고 풀었다면 30줄은 더 늘어났을 것 같다.