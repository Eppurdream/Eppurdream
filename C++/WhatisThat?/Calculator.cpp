//입력 받은 수식을 계산하는 코드에요
//수식에 띄어쓰기를 넣어야 잘 작동해요
//띄어쓰기를 한 예시는 코드 가장 밑에 있어요
 
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

// 4 + 4 * ( 1 + 3 + 5 + 7 * 3 + 2 + 5 - 2 * 3 * 6 / 3 - 9 + 4 / 3 * 4 + 1 + 2 + 3 + 4 + -7 - -9 + 0 - 0 / 1 * 4 - 3 - 6 + -9 * 1 + 10 * 11 + 1000 + 3000 / 12 * 120 - 9 - 9 - -9 + 27 - 0 * 23 + 21000000 )
