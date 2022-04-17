#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    int num = 100000000;
    
    while(num > 0)
    {
        if(n != n % num)
        {
            answer += n / num;
            n %= num;
        }
        num /= 10;
    }
    

    return answer;
}