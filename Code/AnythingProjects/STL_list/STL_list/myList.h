#pragma once

template <typename T>
class Node
{
public:
	Node() : _prev(nullptr), _next(nullptr), _data(T()) {}
	Node(const T& value) : _next(nullptr), _prev(nullptr), _data(value) {}
public:
	Node* _prev;
	T _data;
	Node* _next;
};

template <typename T>
class iterator
{
public:
	iterator() : _node(nullptr) {}
	iterator(Node<T>* node) : _node(node) {}

	iterator<T>& operator++()
	{
		_node = _node->_next;
		return _node;
	}
	iterator<T>& operator++(int)
	{
		iterator<T> temp = *this;
		_node = _node->_next;
		return temp;
	}
	iterator<T>& operator--()
	{
		_node = _node->_prev;
		return _node;
	}
	iterator<T>& operator--(int)
	{
		iterator<T> temp = *this;
		_node = _node->_prev;
		return temp;
	}

	T& operator*()
	{
		return _node->_data;
	}

	bool operator==(const iterator& right)
	{
		return _node == right._node;
	}

	bool operator!=(const iterator& right)
	{
		return _node != right._node;
	}
public:
	Node<T>* _node;
};

template<typename T>
class list
{
public:
	list() : _size(0)
	{
		_header = new Node<T>();
		_header->_next = _header;
		_header->_prev = _header;
	}

	~list()
	{
		while (_size > 0)
			pop_back();

		delete _header;
	}

	void push_back(const T& value)
	{
		AddNode(_header, value);
	}

	Node<T>* AddNode(Node<T> before, const T& value)
	{
		Node<T>* node = new Node<T>(value);
		Node<T>* prev = before->_prev;

		prev->_next = node;
		node->_prev = prev;

		node->_next = before;
		before->_prev = node;

		_size++;

		return node;
	}

	void pop_back()
	{
		RemoveNode(_header->_prev);
	}

	Node<T>* RemoveNode(Node<T>* node)
	{
		node->_prev->_next = node->_next;
		node->_next->_prev = node->_prev;

		Node<T>* nextNode = node->_next;
		delete node;

		_size--;

		return nextNode;
	}

	int size() { return _size; }

	typedef iterator<T> iterator;

	iterator begin()
	{
		return iterator(_header->_next);
	}

	iterator end()
	{
		return iterator(_header);
	}

	iterator insert(iterator it, const T& value)
	{
		iterator iter(AddNode(it._node, value));
		return iter;
	}

	iterator erase(iterator it)
	{
		auto node = RemoveNode(it._node);
		return iterator(node);
	}

public:
	Node<T>* _header;
	int _size;
};



