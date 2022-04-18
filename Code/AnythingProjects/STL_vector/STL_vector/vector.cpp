#include "vector.h"

template<typename T>
void vector<T>::push_back(const T& value)
{
	if (_size == _capacity) // 더 이상 확장이 불가능한 상태
	{
		int newCapa = static_cast<int>(_capacity * 1.5f);
		if (newCapa == _capacity)
			newCapa++;
		reserve(newCapa);
	}
	_data[_size] = value;
	_size++;
}

template<typename T>
void vector<T>::pop_back()
{
	_size--;
}

template<typename T>
void vector<T>::reserve(int capacity)
{
	_capacity = capacity;
	T* newData = new T[_capacity];

	_size = _capacity < _size ? _capacity : _size;

	for (int i = 0; i < _size; i++)
	{
		newData[i] = _data[i];
	}

	if (_data != nullptr)
		delete[] _data;

	_data = newData;
}

template<typename T>
T& vector<T>::operator[](const int pos)
{
	return _data[pos];
}
