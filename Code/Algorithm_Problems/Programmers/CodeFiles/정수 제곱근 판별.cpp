#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    for (long long i = 0; i * i <= n; i++)
    {
        if (i * i == n)
        {
            long long iplus = i + 1;
            answer = iplus * iplus;
            break;
        }
    }
    
    if(answer == 0) answer = -1;
    
    return answer;
}