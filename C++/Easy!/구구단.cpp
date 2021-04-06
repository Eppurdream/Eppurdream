
#include <iostream>
using namespace std;

void Multi(int i1, int i2)
{
	cout << i1 << " x " << i2 << " = " << i1 * i2 << endl;
	if (i1 == 9 && i2 == 9)
		return;
	if (i2 == 9)
	{
		i1++;
		i2 = 0;
	}
	Multi(i1, ++i2);
}
