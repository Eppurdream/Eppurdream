#include <iostream>

using namespace std;

int main(void) {
    int a;
    int b;
    cin >> a >> b;
    for(int i = 0; i < b; i++)
    {
        for(int n = 0; n < a; n++)
        {
            cout << '*';    
        }
        cout << endl;
    }
    return 0;
}