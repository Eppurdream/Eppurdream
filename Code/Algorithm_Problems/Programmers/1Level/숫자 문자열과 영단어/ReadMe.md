```
    문제 설명

    네오와 프로도가 숫자놀이를 하고 있습니다. 네오가 프로도에게 숫자를 건넬 때 일부 자릿수를 영단어로 바꾼 카드를 건네주면 프로도는 원래 숫자를 찾는 게임입니다.

    다음은 숫자의 일부 자릿수를 영단어로 바꾸는 예시입니다.

    1478 → "one4seveneight"
    234567 → "23four5six7"
    10203 → "1zerotwozero3"
    이렇게 숫자의 일부 자릿수가 영단어로 바뀌어졌거나, 혹은 바뀌지 않고 그대로인 문자열 s가 매개변수로 주어집니다. s가 의미하는 원래 숫자를 return 하도록 solution 함수를 완성해주세요.

    참고로 각 숫자에 대응되는 영단어는 다음 표와 같습니다.

    숫자	영단어
    0	zero
    1	one
    2	two
    3	three
    4	four
    5	five
    6	six
    7	seven
    8	eight
    9	nine
    제한사항
    1 ≤ s의 길이 ≤ 50
    s가 "zero" 또는 "0"으로 시작하는 경우는 주어지지 않습니다.
    return 값이 1 이상 2,000,000,000 이하의 정수가 되는 올바른 입력만 s로 주어집니다.
    입출력 예
    s	result
    "one4seveneight"	1478
    "23four5six7"	234567
    "2three45sixseven"	234567
    "123"	123
    입출력 예 설명
    입출력 예 #1

    문제 예시와 같습니다.
    입출력 예 #2

    문제 예시와 같습니다.
    입출력 예 #3

    "three"는 3, "six"는 6, "seven"은 7에 대응되기 때문에 정답은 입출력 예 #2와 같은 234567이 됩니다.
    입출력 예 #2와 #3과 같이 같은 정답을 가리키는 문자열이 여러 가지가 나올 수 있습니다.
    입출력 예 #4

    s에는 영단어로 바뀐 부분이 없습니다.
```

- 풀이 코드
    - C++
```cpp
    #include <string>
    #include <vector>
    #include <iostream>

    using namespace std;

    int solution(string s) {
        int answer = 0;
        int count = 1;
        string strAnswer = "";
        string temp = "";
        string words[10] {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                strAnswer += s[i];
            }
            else
            {
                temp += s[i];

                for(int n = 0; n < 10; n++)
                {
                    if(temp == words[n])
                    {
                        strAnswer += '0' + n;
                        temp = "";
                    }
                }
            }
        }

        for(int i = strAnswer.size() - 1; i >= 0; i--)
        {
            answer += (strAnswer[i] - '0') * count;
            count *= 10;
        }

        return answer;
    }
```

- 이 문제를 풀면서 규칙이 존재하는 열거된 숫자라는 것을 이용해서 배열로 문제를 풀었음
- 이때 당시 코드를 예쁘게 만들고 싶어서 고민하다 나온 결과이다