#include <iostream>
#include "myList.h"
using namespace std;

int main()
{
	// list : ���Ḯ��Ʈ => ���� ���� ����Ʈ
	// �߰� ���� ������ ���ϴ�
	// ó���� �� ���Ե� �����ϴ�
	// ���� ������ �ȵȴ�
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