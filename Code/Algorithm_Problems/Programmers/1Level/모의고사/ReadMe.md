```
    문제 설명
    수포자는 수학을 포기한 사람의 준말입니다. 수포자 삼인방은 모의고사에 수학 문제를 전부 찍으려 합니다. 수포자는 1번 문제부터 마지막 문제까지 다음과 같이 찍습니다.

    1번 수포자가 찍는 방식: 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...
    2번 수포자가 찍는 방식: 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ...
    3번 수포자가 찍는 방식: 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...

    1번 문제부터 마지막 문제까지의 정답이 순서대로 들은 배열 answers가 주어졌을 때, 가장 많은 문제를 맞힌 사람이 누구인지 배열에 담아 return 하도록 solution 함수를 작성해주세요.

    제한 조건
    시험은 최대 10,000 문제로 구성되어있습니다.
    문제의 정답은 1, 2, 3, 4, 5중 하나입니다.
    가장 높은 점수를 받은 사람이 여럿일 경우, return하는 값을 오름차순 정렬해주세요.
    입출력 예
    answers	return
    [1,2,3,4,5]	[1]
    [1,3,2,4,2]	[1,2,3]
    입출력 예 설명
    입출력 예 #1

    수포자 1은 모든 문제를 맞혔습니다.
    수포자 2는 모든 문제를 틀렸습니다.
    수포자 3은 모든 문제를 틀렸습니다.
    따라서 가장 문제를 많이 맞힌 사람은 수포자 1입니다.

    입출력 예 #2

    모든 사람이 2문제씩을 맞췄습니다.
```

- 풀이 코드

```cpp
    #include <string>
    #include <vector>
    #include <iostream>

    using namespace std;

    vector<int> solution(vector<int> answers) {
        vector<int> answer;
        
        const int arr1[] = {1,2,3,4,5};
        const int arr2[] = {2,1,2,3,2,4,2,5};
        const int arr3[] = {3,3,1,1,2,2,4,4,5,5};
        
        int c1 = 0,c2 = 0,c3 = 0;
        
        for(int i = 0; i < answers.size(); i++)
        {
            c1 += answers[i] == arr1[i % 5] ? 1 : 0;
            c2 += answers[i] == arr2[i % 8] ? 1 : 0;
            c3 += answers[i] == arr3[i % 10] ? 1 : 0;
        }
        
        cout << c1 << endl;
        cout << c2 << endl;
        cout << c3 << endl;
        
        if(c1 == c2 && c1 == c3) {
            answer.push_back(1);
            answer.push_back(2);
            answer.push_back(3);
        }else if(c1 > c3 && c1 == c2){
            answer.push_back(1);
            answer.push_back(2);
        }else if(c2 > c1 && c2 == c3){
            answer.push_back(2);
            answer.push_back(3);
        }else if(c3 > c2 && c1 == c3){
            answer.push_back(1);
            answer.push_back(3);
        }else if(c1 > c2 && c1 > c3){
            answer.push_back(1);
        }else if(c2 > c1 && c2 > c3){
            answer.push_back(2);
        }else if(c3 > c1 && c3 > c2){
            answer.push_back(3);
        }
        
        return answer;
    }
```

- 이때 당시 이 문제를 풀기 좋은 방법이 생각이 나지 않아 오직 노가다로 한 기억이 있다.
- if, else if, else if.... 를 계속 반복하는게 참 인상적이다