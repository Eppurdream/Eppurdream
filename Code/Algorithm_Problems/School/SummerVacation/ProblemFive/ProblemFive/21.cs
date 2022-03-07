using System;
using System.Collections.Generic;
using static System.Console;

namespace ProblemFive
{
    class Program
    {



        //static void Main(string[] args)
        //{
        //    Write("배열 길이 입력 : ");
        //    int[] numbers = new int[int.Parse(ReadLine())];
        //    for (int i = 0; i < numbers.Length; i++)
        //    {
        //        numbers[i] = int.Parse(ReadLine());
        //    }

        //    foreach (int i in Func(numbers))
        //    {
        //        WriteLine(i);
        //    }
        //}

        // [문제 21] 두 개 뽑아서 더하기
        // 정수 배열 numbers가 주어집니다.
        // numbers에서 서로 다른 인덱스에 있는 두 개의 수를 뽑아 더해서 만들 수 있는 모든 수를
        // 배열에 오름차순으로 담아 return 하도록 함수를 완성해주세요.
        // (numbers의 길이는 2 이상 100이하이며, 모든 수는 0 이상 100 이하입니다.)

        static int[] Func(int[] numbers)
        {
            List<int> numList = new List<int>();

            for(int i = 0 ; i < numbers.Length - 1 ; i++)
            {
                for(int n = i + 1 ; n < numbers.Length ; n++)
                {
                    if(!numList.Exists(x => x == numbers[i] + numbers[n]))
                    {
                        numList.Add(numbers[i] + numbers[n]);
                    }
                }
            }

            numList.Sort();
            return numList.ToArray();
        }
    }
} 
