#ifndef ARRAYDEQUE_HPP_INCLUDED
#define ARRAYDEQUE_HPP_INCLUDED

#include <iostream>
#include <ostream>
#include "deque.hpp"

using namespace std;

template < class value_type >
class arraydeque : public deque<value_type> {
public:
	//constructor
	arraydeque();
	arraydeque(int);
	//copy constructor
	arraydeque(const arraydeque<value_type>&);
	//destructor
	~arraydeque();

	//operator
	bool empty() const;
	value_type read_front() const;
	value_type read_back() const;
	void push_front(const value_type&);
	void push_back(const value_type&);
	void pop_front();
	void pop_back();
	void print_deque() const;

	//friend ostream& operator<<(ostream& os, const arraydeque<value_type>& q);

	void operator=(const arraydeque<value_type>&);
	bool operator==(const arraydeque<value_type>&);


private:
	value_type* deque;
	int maxdim;
	int head;
	int lenght;

};

template < class value_type >
arraydeque<value_type>::arraydeque() {
	this->maxdim = 10;
	this->deque = new value_type[this->maxdim];
	this->head = 0;
	this->lenght = 0;
}

template < class value_type >
arraydeque<value_type>::arraydeque(int maxdim) {
	this->maxdim = maxdim;
	this->deque = new value_type[this->maxdim];
	this->head = 0;
	this->lenght = 0;
}

template < class value_type >
arraydeque<value_type>::arraydeque(const arraydeque<value_type>& q) {
	this->maxdim = q.maxdim;
	this->deque = new value_type[this->maxdim];
	this->head = 0;
	this->lenght = q.lenght;
	for (int i = 0; i < q.lenght; ++i) {
		this->deque[this->head + i] = q.deque[(q.head + i) % q.maxdim];
	}
}

template< class value_type >
arraydeque<value_type>::~arraydeque() {
	delete[] deque;
}

template< class value_type >
bool arraydeque<value_type>::empty() const {
	return (this->lenght == 0);
}

template< class value_type >
value_type arraydeque<value_type>::read_front() const {
	invaliddequeoperator error;
	if (empty()) {
		throw error.invalidread();
	}
	return this->deque[this->head];
}

template< class value_type >
value_type arraydeque<value_type>::read_back() const {
	invaliddequeoperator error;
	if (this->empty()) {
		throw error.invalidread();
	}
	return this->deque[(this->head + (this->lenght - 1)) % this->maxdim];
}

template< class value_type >
void arraydeque<value_type>::push_front(const value_type& x) {
	invaliddequeoperator error;
	if (this->lenght == this->maxdim) {
		throw error.invalidpush();
	}
	this->head -= 1;
	if (this->head == -1) {
		this->head = this->maxdim - 1;
	}
	this->deque[this->head] = x;
	this->lenght += 1;
}

template< class value_type >
void arraydeque<value_type>::push_back(const value_type& x) {
	invaliddequeoperator error;
	if (this->lenght == this->maxdim) {
		throw error.invalidpush();
	}
	this->deque[(this->head + this->lenght) % this->maxdim] = x;
	this->lenght += 1;
}

template< class value_type >
void arraydeque<value_type>::pop_front() {
	invaliddequeoperator error;
	if (this->lenght == 0) {
		throw error.invalidpop();
	}
	this->lenght -= 1;
	this->head += 1;
	if (this->head == this->maxdim) {
		this->head = 0;
	}
}

template< class value_type >
void arraydeque<value_type>::pop_back() {
	invaliddequeoperator error;
	if (this->lenght == 0) {
		throw error.invalidpop();
	}
	this->lenght -= 1;
}

template< class value_type >
void arraydeque<value_type>::print_deque() const {
	cout << "Deque: [";
	for (int i = 0; i < this->lenght; ++i) {
		if (i == this->lenght - 1) {
			cout << this->deque[(this->head + i) % this->maxdim];
		}
		else {
			cout << this->deque[(this->head + i) % this->maxdim] << ", ";
		}
	}
	cout << "]. " << endl;
}

template< class value_type >
void arraydeque<value_type>::operator=(const arraydeque<value_type>& q) {
	invaliddequeoperator error;
	if (this->maxdim < q.maxdim) {
		throw error.invalidassignment();
	}
	this->head = 0;
	this->lenght = q.lenght;
	for (int i = 0; i < q.lenght; ++i) {
		this->deque[this->head + i] = q.deque[(q.head + i) % q.maxdim];
	}
}

template< class value_type >
bool arraydeque<value_type>::operator==(const arraydeque<value_type>& q) {
	if (this->lenght != q.lenght) {
		return false;
	}
	for (int i = 0; i < this->lenght; ++i) {
		if (this->deque[(this->head + i) % this->maxdim] != q.deque[(q.head + i) % q.maxdim]) {
			return false;
		}
	}
	return true;
}

#endif // !ARRAYDEQUE_HPP_INCLUDED