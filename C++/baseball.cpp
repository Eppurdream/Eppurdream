#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    int strike = 0;
    int ball = 0;
    srand(time(NULL));

    int answer[3] = { 0, };

    answer[0] = rand() % 9 + 1;

    do
    {
        answer[1] = rand() % 9 + 1;
    } while (answer[0] == answer[1]);

    do
    {
        answer[2] = rand() % 9 + 1;
    } while (answer[0] == answer[2] || answer[1] == answer[2]);

    //std::cout << answer[0] << ", " << answer[1] << ", " << answer[2] << std::endl;

    int input[3] = { 0, };


    while (true)
    {
        std::cin >> input[0] >> input[1] >> input[2];

        //std::cout << answer[0] << ", " << answer[1] << ", " << answer[2] << std::endl;
        //std::cout << input[0] << ", " << input[1] << ", " << input[2] << std::endl;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (answer[i] == input[j])
                {
                    if (i == j)
                    {
                        strike++;
                    }
                    else
                    {
                        ball++;
                    }
                }
            }
        }

        if (strike == 3)
        {
            cout << "이겼다" << endl;
            break;
        }
        else if (strike == 0 && ball == 0)
        {
            cout << "아웃" << endl;
        }
        else
        {
            cout << "스트라이크 : " << strike << ", 볼 : " << ball << endl;
        }
        strike = 0;
        ball = 0;
    }



    return 0;
}
