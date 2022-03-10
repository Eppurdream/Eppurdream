using System;
using static System.Console;


namespace ProblemFour
{
    class _18
    {



        //static void Main(string[] args)
        //{
        //    string s = ReadLine();

        //    WriteLine(Func(s));
        //}

        // [문제 18] 가운데 글자 가져오기
        // 단어 s의 가운데 글자를 반환하는 함수를 만들어보세요.
        // 단어의 길이가 짝수라면 가운데 두글자를 반환하면 됩니다.

        static string Func(string s)
        {
            return s.Length % 2 == 0 ? s.Substring(s.Length / 2 - 1, 2) 
                                     : s.Substring(s.Length / 2, 1);
        }
    }
}
