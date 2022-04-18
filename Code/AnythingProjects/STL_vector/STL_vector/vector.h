#pragma once

#include "iterator.h"

template<typename T>
class vector
{
public:
	vector() : _data(nullptr), _size(0), _capacity(0) {}
	~vector() {
		if (_data != nullptr)
			delete[] _data;
	}

	void push_back(const T& value);
	void pop_back();
	void reserve(int capacity);

	T& operator[](const int pos);

	int size() { return _size; }
	int capacity() { return _capacity; }

	typedef iterator<T> iterator;

	iterator begin() { return iterator(&_data[0]); }
	iterator end() { return begin() + _size; }
public:
	T* _data;
	int _size;
	int _capacity;
};


