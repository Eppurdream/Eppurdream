using System;
using static System.Console;


namespace ProblemThree
{
    class _14
    {


        //static void Main(string[] args)
        //{
        //    string s = ReadLine();

        //    WriteLine(Func(s));
        //}

        //[문제 14] 문자열을 정수로 바꾸기
        //문자열 s를 숫자로 변환한 결과를 반환하는 함수를 완성하세요.
        //(s의 길이는 1 이상 5 이하입니다. s의 맨 앞에는 부호(+,-)가 올 수 있습니다. 
        //s는 부호와 숫자로만 이루어져 있습니다. s는 “0”으로 시작하지 않습니다.)

        static long Func(string s)
        {
            return long.Parse(s);

            //return s[0] == '+' ? long.Parse(s.Substring(1)) : long.Parse(s.Substring(1)) * -1;
        }
    }
}
