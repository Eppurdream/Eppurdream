#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    bool isPrime = true;
    int temp = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        for (int n = i + 1; n < nums.size(); n++)
        {
            for (int m = n + 1; m < nums.size(); m++)
            {
                temp = nums[i] + nums[n] + nums[m];

                if (temp % 2 == 0)
                {
                    continue;
                }
                else
                {
                    isPrime = true;
                    for (int j = 3; j * j <= temp; j += 2)
                    {
                        if (temp % j == 0)
                        {
                            isPrime = false;
                            break;
                        }
                    }

                    if (isPrime)
                    {
                        answer++;
                    }
                }
            }
        }
    }

    return answer;
}