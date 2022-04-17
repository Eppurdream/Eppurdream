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