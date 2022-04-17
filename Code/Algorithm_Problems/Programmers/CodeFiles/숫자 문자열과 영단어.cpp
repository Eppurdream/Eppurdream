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