using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;



namespace ProblemFive
{
    class _24
    {
        //static void Main(string[] args)
        //{
        //    Write("배열 길이 입력 : ");
        //    int i = int.Parse(ReadLine());
        //    int[] answers = new int[i];
        //    for (int n = 0; n < i; n++)
        //    {
        //        answers[n] = int.Parse(ReadLine());
        //    }

        //    foreach(string str in Func(answers))
        //    {
        //        WriteLine(str);
        //    }
        //}

        // [문제 24] 모의고사
        // 수포자 삼인방은 모의고사에 수학 문제를 전부 찍으려 합니다. 수포자는 1번 문제부터 마지막 문제까지 다음과 같이 찍습니다.
        // 1번 수포자: 1,2,3,4,5,1,2,3,4,5,…
        // 2번 수포자: 2,1,2,3,2,4,2,5,2,1,2,3,2,4,2,5,…
        // 3번 수포자: 3,3,1,1,2,2,4,4,5,5,3,3,1,1,2,2,4,4,5,5,…
        // 1번 문제부터 마지막 문제까지의 정답이 순서대로 있는 배열 answers가 주어졌을 때,
        // 가장 많은 문제를 맞힌 사람이 누구인지 배열에 담아 return 하는 함수를 작성해주세요.
        // (제한조건) -시험은 최대 10,000 문제로 구성되어 있습니다.
        // - 문제의 정답은 1,2,3,4,5 중 하나입니다.
        // - 가장 높은 점수를 받은 사람이 여럿일 경우, return 하는 값을 오름차순 정렬해주세요.

        //1번 => % 5 + 1
        //2번 => 짝수는 2, 홀수는 1, 3, 4, 5 순
        //3번 => 3, 1, 2, 4, 5 순이지만 두번씩 반복

        static string[] Func(int[] answers)
        {
            int[] arr = new int[3] { 0, 0, 0 };
            int[] repeatTwo = new int[4] { 1, 3, 4, 5 };
            int[] repeatThree = new int[5] { 3, 1, 2, 4, 5 };
            string[] strList = new string[3] { "one", "two", "three" };
            List<string> result = new List<string>();
            int max = 0;

            for (int i = 0 ; i < answers.Length ; i++) // 정답 검사
            {
                arr[0] += answers[i] == i % 5 + 1 ? 1 : 0;
                arr[1] += i % 2 == 0 ? answers[i] == 2 ? 1 : 0 : answers[i] == repeatTwo[(i / 2) % 4] ? 1 : 0;
                arr[2] += answers[i] == repeatThree[(i / 2) % 5] ? 1 : 0;
            }

            for (int i = 0 ; i < arr.Length ; i++) // 가장 많이 문제를 맞춘 수 찾기
            {
                max = arr[i] > max ? arr[i] : max;
            }

            for(int i = 0 ; i < arr.Length ; i++) // 가장 높은 점수를 가진 사람 찾기
            {
                if(arr[i] == max)
                {
                    result.Add(strList[i]);
                }
            }

            return result.ToArray();
        }
    }
}
 
