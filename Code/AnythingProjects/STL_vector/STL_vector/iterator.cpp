#include "iterator.h"

template<typename T>
iterator<T>& iterator<T>::operator++()
{
	_ptr++;
	return *this;
}

template<typename T>
iterator<T> iterator<T>::operator++(int)
{
	iterator temp = *this;
	_ptr++;
	return temp;
}

template<typename T>
iterator<T>& iterator<T>::operator--()
{
	_ptr--;
	return *this;
}

template<typename T>
iterator<T> iterator<T>::operator--(int)
{
	iterator temp = *this;
	_ptr--;
	return temp;
}

template<typename T>
iterator<T> iterator<T>::operator+(const int cnt)
{
	iterator temp = *this;
	temp._ptr += cnt;
	return temp;
}

template<typename T>
iterator<T> iterator<T>::operator-(const int cnt)
{
	iterator temp = *this;
	temp._ptr -= cnt;
	return temp;
}