#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    for(int i = 0; i < arr1.size(); i++)
    {
        vector<int> v;
        for(int n = 0; n < arr1[i].size(); n++)
        {
            v.push_back(arr1[i][n] + arr2[i][n]);
        }
        answer.push_back(v);
    }
    
    return answer;
}