```
    1. 데이터의 개수가 n개가 들어오고, n개 데이터의 순서를 거꾸로 출력하는 프로그램을 작성하시오(스택 사용)
    2. 주어진 수식을 계산한 결과값을 출력하는 프로그램을 작성하시오. (스택 사용)
    <입력>
    - 첫 행에 수식이 빈 칸 없는 문자열로 주어진다.
    - 사용되는 문자는 숫자(0~9), 괄호, 사칙연산자(+,-,*,/)이다.
    - 수식 안의 괄호는 한 쌍 이내로 주어진다.
    3. 큰 수를 표현할 때 자릿수를 쉽게 구분하기 위해 천단위 구분 기호인 콤마(,)를 사용한다. 
    어떤 수가 입력되면 천단위 구분 기호를 넣어 그 수를 다시 출력하는 프로그램을 작성하시오.
```

- 풀이 코드

```cpp
    // 1번 문제

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
```

- 수를 얼마나 입력 받을지 받고 그 수 만큼 정수를 입력하게 하며 입력 받은 정수들을 스택에 넣어서 pop하며 출력하는 코드이다.
- 문제가 스택의 구조를 그대로 이용하면 되었기에 쉽게 풀 수 있었다.

```cpp
    // 2번 문제

    #include <iostream>
    #include <stack>
    #include <string>
    #include <sstream>
    #include <vector>
    
    using namespace std;
    
    long sum(stack<long> st)
    {
        long allInt = 0;
        int size = st.size();
        for (int i = 0; i < size; i++)
        {
            allInt += st.top();
            st.pop();
        }
        return allInt;
    }
    
    long expre(vector<string>& vs, int first, int end)
    {
        char sign = '+';
        char beforeSign;
        long _int = 0;
        long temp = 0;
        int signCount = 0;
        stack<long> st;
        stack<int> parentheses;
        for (int i = first; i < end; i++)
        {
            stringstream ss(vs[i]);
            ss >> _int;
            if (vs[i].length() == 1)
            {
                switch (vs[i][0])
                {
                case '+':
                    sign = '+';
                    signCount++;
                    break;
                case '-':
                    sign = '-';
                    signCount++;
                    break;
                case '*':
                    sign = '*';
                    signCount++;
                    break;
                case '/':
                    signCount++;
                    sign = '/';
                    break;
                case '(':
                    break;
                case ')':
                    break;
                default:
                    if ('0' <= vs[i][0] && vs[i][0] <= '9')
                    {
                        _int = vs[i][0] - '0';
                        switch (sign)
                        {
                        case '+':
                            st.push(_int);
                            break;
                        case '-':
                            st.push(-(_int));
                            break;
                        case '*':
                            temp = st.top() * _int;
                            st.pop();
                            st.push(temp);
                            break;
                        case '/':
                            temp = st.top() / _int;
                            st.pop();
                            st.push(temp);
                            break;
                        }
                    }
                    break;
                }
            }
            else
            {
                switch (sign)
                {
                case '+':
                    st.push(_int);
                    break;
                case '-':
                    st.push(-(_int));
                    break;
                case '*':
                    temp = st.top() * _int;
                    st.pop();
                    st.push(temp);
                    break;
                case '/':
                    temp = st.top() / _int;
                    st.pop();
                    st.push(temp);
                    break;
                }
            }
        }
        return sum(st);
    }
    
    int main()
    {
        string expression;
        vector<string> vs;
        getline(cin, expression);
        stringstream ss(expression);
        int parCount = 0;
        while (getline(ss, expression, ' ')) // ' '를 기준으로 문자열을 나누기
        {
            vs.push_back(expression);
        }
    
        stack<int> parentheses;
        stack<int> parenthesesEnd;
        for (int i = 0; i < vs.size(); i++)
        {
            if (vs[i][0] == '(')
            {
                parentheses.push(i);
                parCount++;
            }
        }
        for (int i = vs.size() - 1; i >= 0; i--)
        {
            if (vs[i][0] == ')')
            {
                parenthesesEnd.push(i);
            }
        }
    
        long result;
        for (int i = parCount; i > 0; i--)
        {
            result = expre(vs, parentheses.top(), parenthesesEnd.top());
            for (int i = parentheses.top(); i <= parenthesesEnd.top(); i++)
            {
                vs[i] = ' ';
            }
            vs[parentheses.top()] = to_string(result);
            while (true)
            {
                parentheses.top()++;
                parenthesesEnd.top()++;
                if (parenthesesEnd.top() == vs.size())
                {
                    break;
                }
                vs[parentheses.top()] = vs[parenthesesEnd.top()];
                vs[parenthesesEnd.top()] = ' ';
            }
            parentheses.pop();
            parenthesesEnd.pop();
        }
        cout << expre(vs, 0, vs.size());
    }
    
    // 4 + 4 * ( 1 + 3 + 5 + 7 * 3 + 2 + 5 - 2 * 3 * 6 / 3 - 9 + 4 / 3 * 4 + 1 + 2 + 3 + 4 + -7 - -9 + 0 - 0 / 1 * 4 - 3 - 6 + -9 * 1 + 10 * 11 + 1000 + 3000 / 12 * 120 - 9 - 9 - -9 + 27 - 0 * 23 + 21000000 ) - 디버깅용 수식
```

- 정해진 수식을 입력받으면 그 수식의 계산값을 출력하는 코드이다.
- 문제를 처음 접했을 때는 간단해 보였지만 속을 살펴보니 스택_2에서 작성한 미로 그 다음으로 힘들게 푼 문제였다.
- 수식마다 우선순위가 있었기에 괄호 -> *, / -> +, - 순서를 맞추기 위해서 수식을 처음부터 끝까지 순회할때 +, -를 만나면 스택에 넣고 *, /, ()를 만나면 스택에 넣기전 먼저 계산한 값을 넣었다 그리고 나중에 모든 수식을 순회한 뒤 마지막 계산을 하고 답을 낼 수 있었다. 
- 이러한 어려운 문제를 만났을 때 나 혼자서 고민하는 시간보다 주변 사람들에게 물어보고 다른 지식을 찾아보는 시간이 더 많았던거 같았던 느낌이다.

```cpp
    // 3번 문제

    #include <iostream>
    #include <string>
    #include <stack>
    using namespace std;
    
    int main()
    {
        string str;
        cin >> str;
    
        for (int i = 0; i < str.size(); i++)
        {
            cout << str[i];
            if ((i + 1) % 3 == str.size() % 3 && i + 1 != str.size())
            {
                cout << ',';
            }
        }
    }
```

- 숫자를 입력 받으면 , 를 천단위 마다 넣어줘서 출력하는 코드이다.
- 숫자를 평벙히 int, long에 입력 받으면 제한이 있었기에 string을 사용했었다.