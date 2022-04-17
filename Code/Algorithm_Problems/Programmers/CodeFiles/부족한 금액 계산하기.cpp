using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    long long sum = 0;
    
    for(int i = 0; i < count; i++)
    {
        sum += price * (i + 1);
    }
    
    if(money - sum > 0)
    {
        answer = 0;
    }
    else
    {
        answer = sum - money;
    }

    return answer;
}