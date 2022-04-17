#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    bool isSame = false;
    
    for(int i = 0; i < 10; i++)
    {
        isSame = true;
        
        for(int n = 0; n < numbers.size(); n++)
        {
            if(numbers[n] == i)
            {
                isSame = false;
                break;
            }
        }
        
        if(isSame)
        {
            answer += i;
        }
    }
    
    return answer;
}