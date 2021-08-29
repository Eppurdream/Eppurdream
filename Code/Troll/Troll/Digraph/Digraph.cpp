%:include<iostream>
using namespace std;

void main()
<%
    int arr<:3:> = <% 1, 2, 3 %>;

    for (int i = 0; i < 3; i++)
    {
        cout << arr<:i:> << endl;
    }
%> 
