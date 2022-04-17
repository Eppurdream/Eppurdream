#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    vector<int> temp;

    for (int i = 0; i < commands.size(); i++)
    {
        temp.clear();
        for (int n = commands[i][0] - 1; n <= commands[i][1] - 1; n++)
        {
            temp.push_back(array[n]);
        }

        sort(temp.begin(), temp.end());

        answer.push_back(temp[commands[i][2] - 1]);
    }

    return answer;
}