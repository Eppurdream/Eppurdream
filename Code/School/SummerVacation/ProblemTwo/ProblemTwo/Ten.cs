using System;
using System.Linq;
using static System.Console;

namespace ProblemTwo
{

    // [문제 10] 자연수 뒤집어 배열로 만들기
    // 자연수 n을 뒤집어 각 자리 숫자를 원소로 가지는 배열 형태로 return 해 주세요.
    // 예를 들어 n이 12345이면 [5,4,3,2,1] 을 리턴합니다.

    class Ten
    {
        //static void Main(string[] args)
        //{
        //    int n = int.Parse(ReadLine());

        //    Solution(n);
        //}

        static char[] Solution(int n)
        {
            char[] arr = n.ToString().ToArray();
            Array.Reverse(arr);
            return arr;
        }
    }
}
