#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    string str = "";
    int count = 1;
    
    while(n != 0)
    {            
        str += '0' + (n % 3);
        
        n /= 3;
    }
    
    
    for(int i = str.size() - 1; i >= 0; i--)
    {        
        answer += (str[i] - '0') * count;
        count *= 3;
    }
    
    return answer;
}