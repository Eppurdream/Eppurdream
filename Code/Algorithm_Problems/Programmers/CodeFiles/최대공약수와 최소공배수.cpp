#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    if(n > m)
    {
        int temp = m;
        m = n;
        n = temp;
    }
    
    int min = 0;
    int max = 0;
    
    for(int i = 1; i <= n; i++)
    {
        if(n % i == 0 && m % i == 0)
        {
            min = i;
        }
    }
    
    max = n * (m / min);
    
    answer.push_back(min);
    answer.push_back(max);
    
    return answer;
}