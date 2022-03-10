```
    문제 설명
    문자열 s는 한 개 이상의 단어로 구성되어 있습니다. 각 단어는 하나 이상의 공백문자로 구분되어 있습니다. 각 단어의 짝수번째 알파벳은 대문자로, 홀수번째 알파벳은 소문자로 바꾼 문자열을 리턴하는 함수, solution을 완성하세요.

    제한 사항
    문자열 전체의 짝/홀수 인덱스가 아니라, 단어(공백을 기준)별로 짝/홀수 인덱스를 판단해야합니다.
    첫 번째 글자는 0번째 인덱스로 보아 짝수번째 알파벳으로 처리해야 합니다.
    입출력 예
    s	return
    "try hello world"	"TrY HeLlO WoRlD"
    입출력 예 설명
    "try hello world"는 세 단어 "try", "hello", "world"로 구성되어 있습니다. 각 단어의 짝수번째 문자를 대문자로, 홀수번째 문자를 소문자로 바꾸면 "TrY", "HeLlO", "WoRlD"입니다. 따라서 "TrY HeLlO WoRlD" 를 리턴합니다.
```

- 풀이 코드

```cpp
    #include <string>
    #include <vector>

    using namespace std;

    string solution(string s) {
        string answer = "";
        bool upper = true;
        
        
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ') 
            {
                upper = true;
                answer += ' ';
                continue;
            }
            
            char temp;
            
            if(s[i] >= 'a' && s[i] <= 'z')
            {
                temp = (char)(s[i] - 32);
            }
            else
            {
                temp = s[i];
            }
            
            answer += upper ? temp : (char)(temp + 32);
            
            upper = !upper;
        }
        
        
        return answer;
    }
```

- 입력 받은 문자열을 대문자, 소문자, 대문자 --- 순서대로 변환시켜주는 함수이다.
- 영문자는 32를 더하거나 빼면 소문자와 대문자로 만들 수 있다는 방법을 알고 있었기에 간단한 예외처리만 해주고나서 풀이 할 수 있었다.