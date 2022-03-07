using System;
using static System.Console;

namespace ProblemThree
{
    class _12
    {


        //static void Main(string[] args)
        //{
        //    int a = int.Parse(ReadLine());
        //    int b = int.Parse(ReadLine());

        //    WriteLine(Func(a, b));
        //}

        //[문제 12] 두 정수 사이의 합
        //두 정수 a, b가 주어졌을 때 a와 b 사이에 속한 모든 정수의 합을 return 하는 함수를 완성하세요. 
        //예를 들어 a = 3, b = 5인 경우, 3 + 4 + 5 = 12이므로 12를 return 합니다.

        static long Func(int a, int b)
        {
            int min = Math.Min(a, b);
            int max = Math.Max(a, b);
            long sum = 0;

            for(int i = min; i <= max; i++)
            {
                sum += i;
            }

            return sum;
        }
    }
}
