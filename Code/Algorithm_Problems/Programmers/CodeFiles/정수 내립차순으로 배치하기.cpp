#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    string str = to_string(n);
    
    for(int i = 0; i < str.size(); i++)
    {
        for(int n = 0; n < str.size(); n++)
        {
            if(str[i] > str[n])
            {
                char temp = str[i];
                str[i] = str[n];
                str[n] = temp;
            }
        }
    }
    
    answer = atoll(str.c_str());
    
    return answer;
}