```
    문제 설명
    길이가 같은 두 1차원 정수 배열 a, b가 매개변수로 주어집니다. a와 b의 내적을 return 하도록 solution 함수를 완성해주세요.

    이때, a와 b의 내적은 a[0]*b[0] + a[1]*b[1] + ... + a[n-1]*b[n-1] 입니다. (n은 a, b의 길이)

    제한사항
    a, b의 길이는 1 이상 1,000 이하입니다.
    a, b의 모든 수는 -1,000 이상 1,000 이하입니다.
    입출력 예
    a	b	result
    [1,2,3,4]	[-3,-1,0,2]	3
    [-1,0,1]	[1,0,-1]	-2
    입출력 예 설명
    입출력 예 #1

    a와 b의 내적은 1*(-3) + 2*(-1) + 3*0 + 4*2 = 3 입니다.
    입출력 예 #2

    a와 b의 내적은 (-1)*1 + 0*0 + 1*(-1) = -2 입니다.
```

- 풀이 코드

```c
    #include <stdio.h>
    #include <stdbool.h>
    #include <stdlib.h>

    // a_len은 배열 a의 길이입니다.
    // b_len은 배열 b의 길이입니다.
    int solution(int a[], size_t a_len, int b[], size_t b_len) {
        int answer = 0;
        
        for(int i = 0; i < a_len; i++)
        {
            answer += a[i] * b[i];
        }
        
        return answer;
    }
```

- 문제의 설명 그대로 코딩을 하면 되는 문제라서 그리 어렵지 않았던 것 같다