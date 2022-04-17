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