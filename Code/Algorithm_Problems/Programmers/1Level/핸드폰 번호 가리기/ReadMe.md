```
    문제 설명
    프로그래머스 모바일은 개인정보 보호를 위해 고지서를 보낼 때 고객들의 전화번호의 일부를 가립니다.
    전화번호가 문자열 phone_number로 주어졌을 때, 전화번호의 뒷 4자리를 제외한 나머지 숫자를 전부 *으로 가린 문자열을 리턴하는 함수, solution을 완성해주세요.

    제한 조건
    s는 길이 4 이상, 20이하인 문자열입니다.
    입출력 예
    phone_number	return
    "01033334444"	"*******4444"
    "027778888"	"*****8888"
```

- 풀이 코드

```cpp
    #include <string>
    #include <vector>

    using namespace std;

    string solution(string phone_number) {
        string answer = phone_number;
        
        for(int i = 0; i < phone_number.size() - 4; i++)
        {
            answer[i] = '*';
        }
        
        return answer;
    }
```

- 받은 문자열의 뒷 4자리 제외한 모든 문자는 '*'으로 변환하는 함수이다.
- string 클래스에는 size를 가져올 수 있기에 이것을 이용해서 반복문을 작성하니 간단히 풀 수 있었다.