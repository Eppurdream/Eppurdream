using System;
using System.Collections.Generic;
using static System.Console;


namespace ProblemFour
{
    class Program
    {

        //[문제 16] 소수 찾기
        //1부터 입력받은 숫자 n 사이에 있는 소수의 개수를 반환하는 함수를 완성하세요.
        //소수는 1과 자기 자신으로만 나누어지는 수를 의미합니다. (1은 소수가 아닙니다.)

        //static void Main(string[] args)
        //{
        //    int n = int.Parse(ReadLine());

        //    WriteLine(Func(n));
        //}

        static int Func(int n)
        {
            List<double> primeList = new List<double>();
            int count = 0;
            bool isPrime = true;

            for(int i = 2; i < n; i++)
            {
                isPrime = true;

                for (int j = 0; j < primeList.Count; j++) // 소수 중 같은게 있는지 검사
                {
                    if (primeList[j] == i)
                    {
                        isPrime = false;
                    }
                }

                for(int j = 2; j < i; j++) // 1과 자기자신 이외에 나눠지는게 있는지 검사
                {
                    if (primeList.Contains(i / (double)j))
                    {
                        isPrime = false;
                    }     
                }

                if(isPrime)
                {
                    count++;
                    primeList.Add(i);
                }
            }

            return count;
        }
    }
}
