#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    long long num = 10000000000;
    int count = 11;
    while (count != 0)
    {
        if (n != n % num)
        {
            answer.push_back(n / num);
            n %= num;
        }
        else if (answer.size() > 0)
        {
            answer.push_back(0);
        }
        num /= 10;
        count--;
    }
    
    for (int i = 0; i < answer.size() / 2; i++)
    {
        int temp = answer[i];
        answer[i] = answer[answer.size() - (i + 1)];
        answer[answer.size() - (i + 1)] = temp;
    }
    
    return answer;
}