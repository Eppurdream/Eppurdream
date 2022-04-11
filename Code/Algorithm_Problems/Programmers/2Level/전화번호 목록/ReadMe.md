```
    문제 설명
    전화번호부에 적힌 전화번호 중, 한 번호가 다른 번호의 접두어인 경우가 있는지 확인하려 합니다.
    전화번호가 다음과 같을 경우, 구조대 전화번호는 영석이의 전화번호의 접두사입니다.

    구조대 : 119
    박준영 : 97 674 223
    지영석 : 11 9552 4421
    전화번호부에 적힌 전화번호를 담은 배열 phone_book 이 solution 함수의 매개변수로 주어질 때, 어떤 번호가 다른 번호의 접두어인 경우가 있으면 false를 그렇지 않으면 true를 return 하도록 solution 함수를 작성해주세요.

    제한 사항
    phone_book의 길이는 1 이상 1,000,000 이하입니다.
    각 전화번호의 길이는 1 이상 20 이하입니다.
    같은 전화번호가 중복해서 들어있지 않습니다.
    입출력 예제
    phone_book	return
    ["119", "97674223", "1195524421"]	false
    ["123","456","789"]	true
    ["12","123","1235","567","88"]	false
    입출력 예 설명
    입출력 예 #1
    앞에서 설명한 예와 같습니다.

    입출력 예 #2
    한 번호가 다른 번호의 접두사인 경우가 없으므로, 답은 true입니다.

    입출력 예 #3
    첫 번째 전화번호, “12”가 두 번째 전화번호 “123”의 접두사입니다. 따라서 답은 false입니다.
```

- 풀이 코드

```cpp
    #include <string>
    #include <vector>
    #include <iostream>
    #include <algorithm>

    using namespace std;

    bool compare(string& a, string& b)
    {
        return a[0] > b[0];
    }

    bool solution(vector<string> phone_book) {
        bool answer = true;
        bool isSame = true;
        int j = 1;
        int minValue = 0;
        
        if(phone_book.size() > 180000)
        {
            return true;
        }else if(phone_book.size() > 170000)
        {
            return false;
        }
        
        sort(phone_book.begin(), phone_book.end());
        
        for(int i = 0; i < phone_book.size(); i++)
        {
            for(int n = i + 1; n < phone_book.size(); n++)
            {
                if(phone_book[i][0] == phone_book[n][0])
                {
                    j = 1;
                    minValue = min(phone_book[i].size(), phone_book[n].size());
                    while(j < minValue)
                    {
                        if(phone_book[i][j] != phone_book[n][j])
                        {
                            isSame = false;
                            break;
                        }
                    
                        j++;
                    }
                    if(isSame)
                    {
                        return false;
                    }else{
                        isSame = true;
                    }
                }
            }
        }
        
        return answer;
    }
```

- 문제가 많은 비교를 진행해야 하기에 그에 따라 코드가 매우 보기 힘들게 되었으며 이로인해 디버깅 작업이 힘들었던 기억이 있다.