#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    int count = 0;
    
    for(int i = left; i <= right; i++)
    {
        count = 0;
        for(int n = 1; n <= i; n++)
        {
            if(i % n == 0)
            {
                count++;
            }
        }
        
        answer += count % 2 == 0 ? i : -i;
    }
    
    return answer;
}