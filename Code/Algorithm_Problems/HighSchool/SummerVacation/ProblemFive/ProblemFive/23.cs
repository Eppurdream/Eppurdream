using System;
using static System.Console;

namespace ProblemFive
{
    class _23
    {

        // [문제 23] 2024년
        // 2024년 1월 1일은 월요일입니다. 2024년 a월 b일은 무슨 요일일까요?
        // 두 수 a, b를 입력받아 2024년 a월 b일이 무슨 요일인지 리턴하는 함수를 완성하세요.
        // 요일의 이름은 일요일부터 토요일까지 각각 SUN, MON, TUE, WED, THU, FRI, SAT입니다.
        // 예를 들어 a = 6, b = 5 라면 6월 5일은 수요일이므로 문자열 “WED”를 반환하세요.
        // (2024년은 윤년입니다. 2024년 a월 b일은 실제로 있는 날입니다. 13월 26이나 2월 45일 같은 날짜는 주어지지 않습니다.)

        //static void Main(string[] args)
        //{
        //    int a = int.Parse(ReadLine());
        //    int b = int.Parse(ReadLine());

        //    WriteLine(Func(a, b));
        //}

        static string Func(int a, int b)
        {
            return DateTime.Parse($"2024-{a}-{b}").DayOfWeek
                .ToString()
                .Substring(0, 3)
                .ToUpper();
        }
    }
}
  
