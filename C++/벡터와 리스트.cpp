#include <iostream>
#include <vector>
#include <list>
#include <time.h>
using namespace std;

int main()
{
	vector<int> vec;
	list<int> li;


	for (int i = 0; i < 10000; i++)
	{
		vec.emplace_back(i);
	}
	for (int i = 0; i < 10000; i++)
	{
		li.emplace_back(i);
	}

	time_t vecstart = time(null);
	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
	{
		cout << *iter << endl;
	}
	time_t vecend = time(null);
	time_t listart = time(null);
	for (list<int>::iterator iter = li.begin(); iter != li.end(); iter++)
	{
		cout << *iter << endl;
	}
	time_t liend = time(null);
	


	cout << endl;
	cout << endl;
	cout << endl;
	cout << "vector 걸린 시간 : " << (double)(vecend - vecstart) << endl;
	cout << "list 걸린 시간 : " << (double)(liend - listart) << endl;
}
