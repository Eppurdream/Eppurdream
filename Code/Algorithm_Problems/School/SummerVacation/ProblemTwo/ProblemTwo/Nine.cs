using System;
using System.Linq;
using static System.Console;


namespace ProblemTwo
{
    class Nine
    {

        // [문제 09] 정수 내림차순으로 배치하기
        // 함수 solution은 정수 n을 매개변수로 입력받습니다.
        // n의 각 자릿수를 큰 것부터 작은 순으로 정렬한 새로운 정수를 return 해 주세요.
        // 예를 들어, n이 118372면 873211을 return 하면 됩니다.
        // (n은 1 이상 8000000000 이하인 자연수입니다.)

        //static void Main(string[] args)
        //{
        //    int n = int.Parse(ReadLine());

        //    WriteLine(Solution(n));
        //}

        static int Solution(int n)
        {
            char[] arr = n.ToString().ToArray();
            string result = "";

            for(int i = 0; i < arr.Length; i++)
            {
                for(int j = i; j < arr.Length; j++)
                {
                    if(arr[i] < arr[j])
                    {
                        char temp = arr[j];
                        arr[j] = arr[i];
                        arr[i] = temp;
                    }
                }
            }

            foreach(char c in arr)
            {
                result += c;
            }

            return int.Parse(result);
        }
    }
}
