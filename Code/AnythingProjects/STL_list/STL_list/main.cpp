#include <iostream>
#include "myList.h"
using namespace std;

int main()
{
	// list : 연결리스트 => 이중 연결 리스트
	// 중간 삽입 삭제가 편하다
	// 처음과 끝 삽입도 가능하다
	// 임의 접근이 안된다
	//

	list<int> li;

	for (int i = 0; i < 100; i++)
	{
		li.push_back(i);
	}

	list<int>::iterator itBegin = li.begin();
	list<int>::iterator itEnd = li.end();

	for (auto it = li.begin(); it != li.end(); ++it)
	{
		cout << *it << endl;
	}



	return 0;
}