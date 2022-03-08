```
    문제 설명
    String형 배열 seoul의 element중 "Kim"의 위치 x를 찾아, "김서방은 x에 있다"는 String을 반환하는 함수, solution을 완성하세요. seoul에 "Kim"은 오직 한 번만 나타나며 잘못된 값이 입력되는 경우는 없습니다.

    제한 사항
    seoul은 길이 1 이상, 1000 이하인 배열입니다.
    seoul의 원소는 길이 1 이상, 20 이하인 문자열입니다.
    "Kim"은 반드시 seoul 안에 포함되어 있습니다.
    입출력 예
    seoul	return
    ["Jane", "Kim"]	"김서방은 1에 있다"
```

- 풀이 코드

```cpp
    #include <string>
    #include <vector>

    using namespace std;

    string solution(vector<string> seoul) {
        string answer = "";
        int x = 0;
        
        for(int i = 0; i < seoul.size(); i++)
        {
            if("Kim" == seoul[i])
            {
                x = i;
                break;
            }
        }
        
        answer = "김서방은 ";
        answer += to_string(x);
        answer += "에 있다";
        
        return answer;
    }
```

- 라이브러리를 사용하지 않고 풀었다면 귀찮은 문제가 되었겠지만 string 덕분에 간단하게 풀 수 있었던 문제이다