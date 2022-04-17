#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    string str = "";
    string strTemp = "";
    
    for(int i = 0; i < arr1.size(); i++)
    {
        int temp = (arr1[i] | arr2[i]);
        str = "";
        while(temp > 0)
        {
            if(temp % 2 == 1)
            {
                str += '#';
            }else
            {
                str += ' ';
            }
            temp /= 2;
        }
        strTemp = "";
        cout << str.size() << " ";
        
        while(str.size() < arr1.size())
        {
            str += ' ';
        }
        
        for(int n = str.size() - 1; n >= 0; n--)
        {
            //cout << n << " : " << str[n] << " ";
            cout << str[n];
            strTemp += str[n];
        }
        cout << endl;
        
        answer.push_back(strTemp);
    }
    
    cout << endl << endl;
    for(int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << endl;
    }
    
    return answer;
}