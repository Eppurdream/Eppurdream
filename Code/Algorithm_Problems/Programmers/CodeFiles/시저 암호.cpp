#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == ' ') 
        {
            answer += ' ';
            continue;
        }
        
        int temp = s[i] + n;
        
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            if(temp > 'z')
            {
                answer += temp - ('z' - 'a') - 1;
            }
            else
            {
                answer += temp;
            }
        }
        else if(s[i] >= 'A' && s[i] <= 'Z')
        {
            if(temp > 'Z')
            {
                answer += temp - ('z' - 'a') - 1;
            }
            else
            {
                answer += temp;
            }
        }

        
    }
    
    return answer;
}