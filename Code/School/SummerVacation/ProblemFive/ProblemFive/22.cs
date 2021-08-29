using System;
using static System.Console;



namespace ProblemFive
{
    class _22
    {

        // [문제 22] 이상한 문자 만들기
        // 문자열 s는 한 개 이상의 단어로 구성되어 있습니다. 각 단어는 하나 이상의 공백 문자로 구분되어 있습니다. 
        // 각 단어의 짝수번째 알파벳은 대문자로, 홀수번째 알파벳은 소문자로 바꾼 문자열을 return 하는 함수, solution을 완성하세요.
        // (문자열 전체의 짝/홀수 인덱스가 아니라, 단어(공백을 기준)별로 짝/홀수 인덱스를 판단해야 합니다. 
        // 첫 번째 글자는 0번째 인덱스로 보아 짝수번째 알파벳으로 처리해야 합니다.)

        //static void Main(string[] args)
        //{
        //    string s = ReadLine();

        //    WriteLine(Solution(s));
        //}

        static string Solution(string s)
        {
            string[] stringList = s.Split(' ');
            string result = "";

            for(int i = 0 ; i < stringList.Length ; i++)
            {
                char[] charArr = stringList[i].ToLower().ToCharArray();

                for(int n = 0 ; n < stringList[i].Length ; n++)
                {
                    charArr[n] = n % 2 == 0 ? Convert.ToChar(charArr[n] - 32) : charArr[n];
                }

                result += new string(charArr) + ' ';
            }

            return result;
        }
    }
}
 
