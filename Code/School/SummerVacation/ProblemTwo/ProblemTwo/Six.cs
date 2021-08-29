using System;
using static System.Console;

namespace ProblemTwo
{

    // [문제 06] 최대공약수와 최소공배수
    // 두 수를 입력받아 두 수의 최대공약수와 최소공배수를 반환하는 함수를 완성해보세요.
    // 배열의 맨 앞에 최대공약수, 그다음 최소공배수를 넣어 반환하면 됩니다.
    // 예를 들어 두 수 3, 12의 최대공약수는 3, 최소공배수는 12이므로 solution(3, 12)는 3, 12를 반환해야 합니다.
    // (두 수는 1 이상 1000000이하의 자연수입니다.)

    class Six
    {
        static void Main(string[] args)
        {
            int i1 = int.Parse(ReadLine());
            int i2 = int.Parse(ReadLine());

            int[] arr = Func(i1, i2);

            WriteLine("최대공약수 : " + arr[0] + ", 최대공배수 : " + arr[1]);
        }

        static int[] Func(int i1, int i2)
        {
            int min = i1 < i2 ? i1 : i2;
            int max = i1 > i2 ? i1 : i2;
            int value = 0;

            for(int i = 1; i <= min; i++)
            {
                value = min / i;

                for(int n = value; n <= max; n += value)
                {
                    if(n == max) return new int[2] { value, (min * max) / value };
                }
            }

            // ===== 예외처리 ===== //
            WriteLine("최대공약수와 최대공배수가 없습니다");
            return new int[2] { -1, -1 };
        }
    }
}
