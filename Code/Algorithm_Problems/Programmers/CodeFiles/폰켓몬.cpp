#include <vector>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    vector<int> notSame;
    bool isSame = true;
    
    for(int i = 0; i < nums.size(); i++)
    {
        isSame = true;
        for(int j = 0; j < notSame.size(); j++)
        {
            if(nums[i] == notSame[j])
            {
                isSame = false;
                break;
            }
        }
        if(isSame)
        {
            notSame.push_back(nums[i]);
        }
    }
    
    if(notSame.size() > nums.size() / 2)
    {
        answer = nums.size() / 2;
    }
    else
    {
        answer = notSame.size();
    }
    
    return answer;
}