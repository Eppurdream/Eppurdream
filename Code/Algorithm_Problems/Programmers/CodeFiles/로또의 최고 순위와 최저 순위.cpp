#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int temp = 0;
    int emptyCount = 0;
    
    for(int i = 0; i < lottos.size(); i++)
    {
        if(find(win_nums.begin(), win_nums.end(), lottos[i]) != win_nums.end())
        {
            temp++;
        }else if(lottos[i] == 0)
        {
            emptyCount++;
        }
    }
    
    cout << temp + emptyCount << " " << temp << endl;
    
    if(temp + emptyCount == 0)
    {
        answer.push_back(6);
    }
    else
    {
        answer.push_back(7 - temp - emptyCount);
    }
    
    if(temp == 0)
    {
        answer.push_back(6);
    }
    else
    {
        answer.push_back(7 - temp);
    }
    
    return answer;
}