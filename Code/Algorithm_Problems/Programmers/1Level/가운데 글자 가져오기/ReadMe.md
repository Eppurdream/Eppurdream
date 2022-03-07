```
    문제 설명
    단어 s의 가운데 글자를 반환하는 함수, solution을 만들어 보세요. 단어의 길이가 짝수라면 가운데 두글자를 반환하면 됩니다.

    재한사항
    s는 길이가 1 이상, 100이하인 스트링입니다.
    입출력 예
    s	return
    "abcde"	"c"
    "qwer"	"we"
```

- 풀이 코드

```cpp
    #include <string>
    #include <vector>

    using namespace std;

    string solution(string s) {
        string answer = "";
        
        if(s.size() % 2 == 0)
        {
            answer = s[s.size() / 2 - 1];
            answer += s[s.size() / 2];
        }
        else
        {
            answer = s[s.size() / 2];
        }
        
        return answer;
    }
```

- 홀수를 2로 나누었을 때만 유의하면 되는 문제이므로 이를 유의해서 쉽게 풀 수 있었다.