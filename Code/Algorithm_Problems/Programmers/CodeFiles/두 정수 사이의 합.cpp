#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int a, int b) {
    long long answer = 0;
    long long sum = (a + b);
    long long length = ((a > b ? a - b : b - a) + 1);
    
    if(a != b)
    {
        return (long long)(length * sum / 2);
    }
    
    return a;
}