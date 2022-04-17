#include <string>
#include <iostream>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int beforeTemp = 0;
    int temp = 0;
        
    for(int i = 0; i < dartResult.size(); i++)
    {
        switch(dartResult[i])
        {
            case 'S':
                temp *= 1;
                break;
            case 'D':
                temp *= temp;
                break;
            case 'T':
                temp *= temp * temp;
                break;
            case '*':
                answer += beforeTemp;
                temp *= 2;
                break;
            case '#':
                temp *= -1;
                break;
        }
            
        if(dartResult[i] >= '0' && dartResult[i] <= '9')
        {
            answer += temp;
            beforeTemp = temp;
            cout << temp << endl;
            if(dartResult[i + 1] == '0')
            {
                temp = 10;
                i++;
            }else {
                temp = dartResult[i] - '0';
            }
        }
    }
        
    answer += temp;
    cout << temp << endl;
        
    return answer;
}