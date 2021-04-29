#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    int count = 0;
    cout << "몇개의 데이터를 입력 받으실건가요?? : ";
    cin >> count;
    cout << endl;
    if (count > 1000)
    {
        cout << "count가 제한 크기를 넘었습니다." << endl;
        return 0;
    }
    string str;
    stack<string> st;
    for (int i = 0; i < count; i++)
    {
        cin >> str;
        st.push(str);
    }

    int size = st.size();
    for (int i = 0; i < size; i++)
    {
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}
