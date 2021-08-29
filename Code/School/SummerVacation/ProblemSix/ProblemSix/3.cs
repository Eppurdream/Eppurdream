using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;



namespace ProblemSix
{
    class _3
    {
        //static void Main(string[] args)
        //{
        //    Write("길이 입력 : ");
        //    int length = int.Parse(ReadLine());

        //    int[] prices = new int[length];

        //    for(int i = 0; i < length; i++)
        //    {
                
        //        prices[i] = int.Parse(ReadLine());
        //    }

        //    foreach(string str in Solution(prices))
        //    {
        //        WriteLine(str);
        //    }
        //}

        // [문제 03] 주식 가격
        // 초 단위로 기록된 주식가격이 담긴 배열 prices가 매개변수로 주어질 때,
        // 가격이 떨어지지 않은 기간은 몇 초인지를 return 하도록 solution 함수를 완성하세요.
        // (prices의 각 가격은 1 이상 10,000 이하인 자연수입니다. prices의 길이는 2 이상 100,000 이하입니다.)

        static string[] Solution(int[] prices)
        {
            List<string> result = new List<string>();

            for(int i = 0; i < prices.Length; i++)
            {
                for(int n = i; n < prices.Length; n++)
                {
                    if(prices[i] > prices[n])
                    {
                        result.Add($"{i + 1}초 시점의 ${prices[i]}은 {n - i}초 뒤에 가격이 떨어집니다.");
                        break;
                    }
                    if(n + 1 == prices.Length)
                    {
                        result.Add($"{i + 1}초 시점의 ${prices[i]}은 끝까지 가격이 떨어지지 않았습니다.");
                        break;
                    }
                }
            }

            return result.ToArray();
        }
    }
}
