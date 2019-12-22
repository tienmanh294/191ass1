/* Created by Nguyen Duc Dung on 2019-09-03.
 * =========================================================================================
 * Name        : dsaLib.h
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - HCMUT
 * Description : The data structure library for Assignment 1
 * Course      : Data Structure and Algorithms - Fall 2019
 * =========================================================================================
 */

#ifndef DSA191_A1_DSALIB_H
#define DSA191_A1_DSALIB_H
#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

class DSAException {
    int     _error;
    string  _text;
public:

    DSAException() : _error(0), _text("Success") {}
    DSAException(int err) : _error(err), _text("Unknown Error") {}
    DSAException(int err, const char* text) : _error(err), _text(text) {}

    int getError() { return _error; }
    string& getErrorText() { return _text; }
};

template <class T>
struct L1Item {
    T data;
    L1Item<T> *pNext;
    L1Item() : pNext(NULL) {}
    L1Item(T &a) : data(a), pNext(NULL) {}
};

template <class T>
class L1List {
    L1Item<T>   *_pHead;// The head pointer of linked list
    size_t      _size;// number of elements in this list
public:
    L1List() : _pHead(NULL), _size(0) {}
    ~L1List();

    void    clean();
    bool    isEmpty() {
        return _pHead == NULL;
    }
    size_t  getSize() {
        return _size;
    }

    T&      at(int i);// give the reference to the element i-th in the list
    T&      operator[](int i);// give the reference to the element i-th in the list

    bool    find(T& a, int& idx);// find an element similar to a in the list. Set the found index to idx, set idx to -1 if failed. Return true if success.
    int     insert(int i, T& a);// insert an element into the list at location i. Return 0 if success, -1 otherwise
    int     remove(int i);// remove an element at position i in the list. Return 0 if success, -1 otherwise.

    int     push_back(T& a);// insert to the end of the list
    int     insertHead(T& a);// insert to the beginning of the list

    int     removeHead();// remove the beginning element of the list
    int     removeLast();// remove the last element of the list

    void    reverse();

    void    traverse(void (*op)(T&)) 
	{
        // TODO: Your code goes here
		
    }
    void    traverse(void (*op)(T&, void*), void* pParam)
	{
        // TODO: Your code goes here
		op(pHead->data, pParam);
    }
};

template<class T>
inline L1List<T>::~L1List()
{
	this->clean();
}

template<class T>
inline void L1List<T>::clean()
{
	L1Item<T>* del = _pHead;
	while (_pHead != NULL) 
	{
		del = _pHead;
		_pHead = _pHead->pNext;
		recycle(del);
		_size--;
	}
}

template<class T>
inline T& L1List<T>::at(int i)
{
	int count = 0;
	L1Item<T>* walk = _pHead;

	while ( walk!=NULL) 
	{
		if (count == i) 
		{
			return walk;
		}
		count++;
		walk = walk->pNext;
	}
	
	// TODO: insert return statement here
	asset(o);
}

template<class T>
inline T& L1List<T>::operator[](int i)
{
	int count = 0;
	L1Item<T>* walk = _pHead;

	while (walk != NULL)
	{
		if (count == i)
		{
			return walk;
		}
		count++;
		walk = walk->pNext;
	}
	asset(0);
	// TODO: insert return statement here
}

template<class T>
inline bool L1List<T>::find(T& a, int& idx)
{
	L1Item<T>* walk = _pHead;
	int count = 0;
	while (walk != NULL) 
	{
		if (walk->data != a)
		{
			count++;
			walk = walk->pNext;
		}
		else 
		{
			idx = count;
			return true;
		}
	}
	idx = -1;
	return false;
}

template<class T>
inline int L1List<T>::insert(int i, T& a)
{
	if (i > _size)return -1;
	L1Item<T>* New = new L1Item<T>(a);
	if (_size == 0) 
	{
		New->pNext = _pHead;
		_pHead = New;
		return 0;
	}
	L1Item<T>* temp = _pHead;
	int count = 0;
	while (count != i)
	{
		temp = temp->pNext;
		count++;
	}
	New->pNext = temp->pNext;
	temp->pNext = New;
	_size++;
	return 0;
}

template<class T>
inline int L1List<T>::remove(int i)
{
	if (i > _size)return false;
	L1Item<T>* temp = _pHead;
	L1Item<T>* pre;
	int count = 0;
	while (count != i)
	{
		pre = temp;
		temp = temp->pNext;
		count++;
	}
	if (temp == _pHead) 
	{
		_pHead = _pHead->pNext;
	}
	else if (temp->pNext == NULL && temp != NULL) 
	{
		pre->pNext = NULL;
	}
	else pre->pNext = temp->pNext;
	recycle(temp);
	_size--;
	return 0;
}

/// Insert item to the end of the list
/// Return 0 if success, -1 otherwise
template <class T>
int L1List<T>::push_back(T &a) 
{
	L1Item<T>* New = new L1Item<T>(a);
	this->at(_size - 1)->pNext = New;
    // TODO: Your code goes here
    return 0;
}

/// Insert item to the front of the list
/// Return 0 if success, -1 otherwise
template <class T>
int L1List<T>::insertHead(T &a) {
    // TODO: Your code goes here
	L1Item<T>* New = new L1Item<T>(a);
	New->pNext = _pHead;
	_pHead = New;
    return 0;
}

/// Remove the first item of the list
/// Return 0 if success, -1 otherwise
template <class T>
int L1List<T>::removeHead() {
    // TODO: Your code goes here
	L1Item<T>* del = _pHead;
	_pHead = _pHead->pNext;
	recycle(del);
	_size--;
    return -1;
}

/// Remove the last item of the list
/// Return 0 if success, -1 otherwise
template <class T>
int L1List<T>::removeLast() {
    // TODO: Your code goes here
	this->at(_size - 2)->pNext = NULL;
	recycle(this->at(_size - 1));
    return -1;
}

template<class T>
inline void L1List<T>::reverse()
{
	L1Item<T>* current = _pHead;
	L1Item<T>* prev = NULL, * next = NULL;

	while (current != NULL) {
		// Store next 
		next = current->pNext;

		// Reverse current node's pointer 
		current->pNext = prev;

		// Move pointers one position ahead. 
		prev = current;
		current = next;
	}
	_pHead = prev;
}

#endif //DSA191_A1_DSALIB_H
