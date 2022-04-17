#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int lower = 200000000;
    
    if(arr.size() == 1) return vector<int>{ -1 };
    
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] < lower)
        {
            lower = arr[i];
        }
    }
    
    vector<int>::iterator iter = find(arr.begin(), arr.end(), lower);
    
    arr.erase(iter);
    
    answer = arr;
    
    return answer;
}