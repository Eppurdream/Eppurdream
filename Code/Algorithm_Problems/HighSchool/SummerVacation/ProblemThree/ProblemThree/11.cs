using System;
using static System.Console;

namespace ProblemThree
{
    class Program
    {
        // [문제 11] 자릿수 더하기
        // 자연수 N이 주어지면, N의 각 자릿수의 합을 구해서 return 하는 soulution 함수를 만들어주세요.
        // 예를 들어 N이 123이면 1 + 2 + 3 = 6을 return 하면 됩니다.

        //static void Main(string[] args)
        //{
        //    int n = int.Parse(ReadLine());
        //    WriteLine(Func(n));
        //}

        static long Func(int n)
        {
            string str = n.ToString();
            long sum = 0;

            for(int i = 0; i < str.Length; i++)
            {
                sum += str[i] - '0';
            }

            return sum;
        }
    }
}
