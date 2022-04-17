#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int temp = 0;
    
    for(int i = 0; i < numbers.size(); i++)
    {
        for(int n = 0; n < numbers.size(); n++)
        {
            if(i == n) continue;
            
            if(find(answer.begin(), answer.end(), numbers[i] + numbers[n]) == answer.end())
            {
                answer.emplace_back(numbers[i] + numbers[n]);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}