#pragma once

template<typename T>
class iterator
{
public:
	iterator() : _ptr(nullptr) {}
	iterator(T* ptr) : _ptr(ptr) {}

	// ÀüÀ§Çü (front)
	iterator& operator++();
	iterator operator++(int);
	iterator& operator--();
	iterator operator--(int);

	iterator operator+(const int cnt);
	iterator operator-(const int cnt);

	bool operator==(const iterator& right)
	{
		return _ptr == right->_ptr;
	}

	bool operator!=(const iterator& right)
	{
		return !(*this == right);
	}

	T& operator*()
	{
		return *_ptr;
	}

public:
	T* _ptr;
};

