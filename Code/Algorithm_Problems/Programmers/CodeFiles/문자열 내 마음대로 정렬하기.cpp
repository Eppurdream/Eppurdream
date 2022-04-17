#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    
    for(int i = 0; i < strings.size(); i++)
    {
        for(int j = i + 1; j < strings.size(); j++)
        {
            if(strings[i][n] > strings[j][n])
            {
                string temp = strings[i];
                strings[i] = strings[j];
                strings[j] = temp;
            }
            else if(strings[i][n] == strings[j][n])
            {
                for(int m = 0; m < strings[i].size(); m++)
                {
                    if(strings[j].size() - 1 < m) break;
                    cout << "!";
                    
                    if(strings[i][m] > strings[j][m])
                    {
                        string temp = strings[i];
                        strings[i] = strings[j];
                        strings[j] = temp;
                                
                        break;
                    }
                    else if(strings[i][m] < strings[j][m])
                    {
                        break;
                    }
                }
            }
        }
    }
    
    for(int i = 0; i < strings.size(); i++)
    {
        answer.push_back(strings[i]);
    }
    
    
    return answer;
}