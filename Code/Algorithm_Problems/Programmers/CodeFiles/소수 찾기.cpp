#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 1;
    bool isPrime = true;
    
    for(int i = 3; i <= n; i+=2)
    {
        isPrime = true;
        
        for(int j = 3; j * j <= i; j+=2)
        {
            if(i % j == 0)
            {
                isPrime = false;
                break;
            }
        }
        
        if(isPrime)
        {
            answer++;
        }
    }
    
    return answer;
}