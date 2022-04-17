#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] % divisor == 0)
        {
            answer.push_back(arr[i]);
        }
    }
    
    for(int i = 0; i < answer.size(); i++)
    {
        for(int j = 0; j < answer.size(); j++)
        {
            if(answer[i] < answer[j])
            {
                int temp = answer[i];
                answer[i] = answer[j];
                answer[j] = temp;
            }
        }
    }
    
    if(answer.size() == 0)
    {
        answer.push_back(-1);
    }
    
    return answer;
}