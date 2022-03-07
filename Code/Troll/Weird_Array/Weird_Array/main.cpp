#include <iostream>
using namespace std;

void main()
{
	int arr[10]{ 0,1,2,3,4,5,6,7,8,9 }; // 평범한 배열 선언

	for (int i = 0; i < 10; i++)
	{
		cout << i[arr] << "\t"; // arr[i]가 아닌 다른 방식
	}

	cout << endl << endl;

	int arr2[10][10];

	for (int i = 0; i < 10; i++)
	{
		for (int n = 0; n < 10; n++)
		{
			i[n[arr2]] = i * 10 + n; // 위와 같이 특이한 방식 사용
		}
	}


	return;
}
