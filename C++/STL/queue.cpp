#include <iostream>
using namespace std;

template<typename T>
class queue {
private:
	T* arr;
	int isize;
	int maxSize;
	bool isConstSize;
public:
	queue();
	~queue();
	void push(T t);
	void pop();
	T front();
	T rear();
	int size();
	void fmaxSize(T t);
};

template<typename T>
queue<T>::queue()
{
	arr = (T*)malloc(0);
	isize = 0;
	maxSize = 0;
	isConstSize = false;
}

template<typename T>
queue<T>::~queue()
{
	free(arr);
}

template<typename T>
void queue<T>::push(T t)
{
	if (isConstSize)
	{
		if (maxSize <= isize)
		{
			cout << "크기를 초과하셨서요.." << "maxSize : " << maxSize << endl;
			return;
		}
	}
	if (maxSize > isize)
	{
		arr[isize] = t;
		isize++;
		return;
	}
	void* temp = realloc(arr, sizeof(T) * (isize + 1));
	if (temp == NULL)
	{
		return;
	}
	arr = (T*)temp;
	arr[isize] = t;
	isize++;
	maxSize = isize;
}

template<typename T>
void queue<T>::pop()
{
	if (isize == 0)
	{
		cout << "안에 든게 더 이상 없어요" << endl;
		//throw out_of_range("size가 0 이에요."); // 에러가 나기에 주석처리
		return;
	}
	for (int i = 0; i < isize; i++)
	{
		arr[i] = arr[i + 1];
	}
	isize--;
}

template<typename T>
T queue<T>::front()
{
	if (isize == 0)
	{
		cout << "size를 초과한 연산입니다." << endl;
		//throw out_of_range("size를 초과한 연산입니다."); // 에러가 나기에 주석처리
		return NULL;
	}
	return arr[0];
}

template<typename T>
T queue<T>::rear()
{
	if (isize == 0)
	{
		cout << "size를 초과한 연산입니다." << endl;
		//throw out_of_range("size를 초과한 연산입니다."); // 에러가 나기에 주석처리
		return NULL;
	}
	return arr[isize - 1];
}

template<typename T>
int queue<T>::size()
{
	return isize;
}

template<typename T>
void queue<T>::fmaxSize(T t)
{
	void* temp = realloc(arr, sizeof(T) * t);
	if (temp == NULL)
	{
		return;
	}
	arr = (T*)temp;
	isConstSize = true;
	maxSize = t;
}

int main()
{
	queue<int> q;
	q.fmaxSize(4);
	q.pop();
	for (int i = 0; i < 6; i++)
	{
		q.push(i);
	}

	for (int i = 0; i < 6; i++)
	{
		cout << "front : " << q.front() << "\t";
		cout << "rear : " << q.rear() << endl;
		q.pop();
	}
	return 0;
}
