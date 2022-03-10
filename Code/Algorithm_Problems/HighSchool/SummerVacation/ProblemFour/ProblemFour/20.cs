using System;
using System.Collections.Generic;
using static System.Console;


namespace ProblemFour
{
    class _20
    {


        //static void Main(string[] args)
        //{
        //    Write("n : ");
        //    int n = int.Parse(ReadLine());
        //    Write("i : ");
        //    int i = int.Parse(ReadLine());
        //    List<string> strings = new List<string>();

        //    for (int j = 0; j < i; j++)
        //    {
        //        strings.Add(ReadLine());
        //    }

        //    Func(strings, n);

        //    for(int j = 0; j < strings.Count; j++)
        //    {
        //        WriteLine(strings[j]);
        //    }
        //}

        // [문제 20] 문자열 내 마음대로 정렬하기
        // 문자열로 구성된 리스트 strings와 정수 n이 주어졌을 때,
        // 각 문자열의 인덱스 n번째 글자를 기준으로 오름차순 정렬하려 합니다. 
        // 예를 들어, strings가[“sun”, “bed”, “car”]이고 
        // n이 1이면 각 단어의 인덱스 1의 문자 “u”. “e”, “a”로 strings를 정렬합니다. [“car”, “bed”, “sun”]

        static void Func(List<string> strings, int n)
        {
            strings.Sort((x, y) => x[n].CompareTo(y[n]));
        }
    }
}
