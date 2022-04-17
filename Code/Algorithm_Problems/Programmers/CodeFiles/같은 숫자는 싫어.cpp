#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    bool isSame = true;

    for (int i = 0; i < arr.size(); i++)
    {
        isSame = true;
        for (int j = 0; j < answer.size(); j++)
        {
            if (*(answer.end() - 1) == arr[i])
            {
                isSame = false;
                break;
            }
        }
        if (isSame)
        {
            answer.push_back(arr[i]);
        }
    }


    return answer;
}