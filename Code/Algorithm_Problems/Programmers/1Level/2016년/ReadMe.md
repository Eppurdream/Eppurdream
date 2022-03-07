```
    문제 설명
    2016년 1월 1일은 금요일입니다. 2016년 a월 b일은 무슨 요일일까요? 두 수 a ,b를 입력받아 2016년 a월 b일이 무슨 요일인지 리턴하는 함수, solution을 완성하세요. 요일의 이름은 일요일부터 토요일까지 각각 SUN,MON,TUE,WED,THU,FRI,SAT

    입니다. 예를 들어 a=5, b=24라면 5월 24일은 화요일이므로 문자열 "TUE"를 반환하세요.

    제한 조건
    2016년은 윤년입니다.
    2016년 a월 b일은 실제로 있는 날입니다. (13월 26일이나 2월 45일같은 날짜는 주어지지 않습니다)
    입출력 예
    a	b	result
    5	24	"TUE"
```

- 풀이 코드

```cpp
    #include <string>
    #include <vector>

    using namespace std;

    string solution(int a, int b) {
        string answer = "";
        
        int mouths[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        string weeks[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
        int mouthCount = 1;
        int dayCount = 1;
        int weekCount = 4;
        bool exit = false;
        
        for (int i = 0; i < 12; i++)
        {
            for (int n = 0; n < mouths[i]; n++)
            {
                if (weekCount > 6)
                {
                    weekCount = 0;
                }
                if (mouthCount == a && dayCount == b)
                {
                    answer = weeks[weekCount];
                    exit = true;
                    break;
                }
                dayCount++;
                weekCount++;
            }
            
            if(exit) break;
            
            mouthCount++;
            dayCount = 1;
        }
        
        return answer;
    }
```

- 이 문제의 방법을 찾지 못하여서 결국 노가다로 푼 문제이다 그래서 시간이 많이 걸린 감이 있다.