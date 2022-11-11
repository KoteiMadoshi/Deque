#ifndef LINKEDDEQUE_HPP_INCLUDED
#define LINKEDDEQUE_HPP_INCLUDED

#include <iostream>
#include "deque.hpp"

using namespace std;

template< class value_type >
class linkeddeque;

template< class value_type >
class node {
	friend class linkeddeque<value_type>;

private:
	value_type e;
	node<value_type>* next;
	node<value_type>* prev;
};

template< class value_type >
class linkeddeque : public deque<value_type> {
public:
	//constructor
	linkeddeque();
	//copy constructor
	linkeddeque(const linkeddeque<value_type>&);
	//destructor
	~linkeddeque();


	bool empty() const;
	value_type read_back() const;
	value_type read_front() const;
	void pop_back();
	void pop_front();
	void push_back(const value_type&);
	void push_front(const value_type&);
	void print_deque() const;

	void operator=(const linkeddeque<value_type>&);
	bool operator==(const linkeddeque<value_type>&);

private:
	node<value_type>* head;
	node<value_type>* tail;
};

template< class value_type >
linkeddeque<value_type>::linkeddeque() {
	this->head = nullptr;
	this->tail = nullptr;
}

template< class value_type >
linkeddeque<value_type>::linkeddeque(const linkeddeque<value_type>& q) {
	this->head = nullptr;
	node<value_type>* iterq;
	iterq = q.head;
	while (iterq != nullptr) {
		this->push_back(iterq->e);
		iterq = iterq->next;
	}
}

template< class value_type >
linkeddeque<value_type>::~linkeddeque() {
	node<value_type>* iter;
	iter = this->head;
	while (iter != nullptr) {
		this->pop_front();
		iter = this->head;
	}
}

template < class value_type >
bool linkeddeque<value_type>::empty() const {
	return (this->head == nullptr);
}

template < class value_type >
value_type linkeddeque<value_type>::read_back() const {
	invaliddequeoperator error;
	if (this->empty()) {
		throw error.invalidread();
	}
	return this->tail->e;
}

template < class value_type >
value_type linkeddeque<value_type>::read_front() const {
	invaliddequeoperator error;
	if (this->empty()) {
		throw error.invalidread();
	}
	return this->head->e;
}

template< class value_type >
void linkeddeque<value_type>::pop_back() {
	invaliddequeoperator error;
	if (this->empty()) {
		throw error.invalidpop();
	}
	else if (this->head == this->tail) {
		node<value_type>* oldtail;
		oldtail = this->head;
		this->head = nullptr;
		this->tail = nullptr;
		delete oldtail;
	}
	else {
		node<value_type>* oldtail;
		oldtail = this->tail;
		this->tail = this->tail->prev;
		this->tail->next = nullptr;
		delete oldtail;
	}
}

template< class value_type >
void linkeddeque<value_type>::pop_front() {
	invaliddequeoperator error;
	if (this->empty()) {
		throw error.invalidpop();
	}
	else if (this->head == this->tail) {
		node<value_type>* oldhead;
		oldhead = this->head;
		this->head = nullptr;
		this->tail = nullptr;
		delete oldhead;
	}
	else {
		node<value_type>* oldhead;
		oldhead = this->head;
		this->head = this->head->next;
		this->head->prev = nullptr;
		delete oldhead;
	}
}

template< class value_type >
void linkeddeque<value_type>::push_back(const value_type& x) {
	if (this->empty()) {
		node<value_type>* newnode = new node<value_type>;
		newnode->e = x;
		this->head = newnode;
		this->tail = newnode;
		this->head->prev = nullptr;
		this->tail->next = nullptr;
	}
	else {
		node<value_type>* newnode = new node<value_type>;
		newnode->e = x;
		newnode->next = nullptr;
		newnode->prev = this->tail;
		this->tail->next = newnode;
		this->tail = newnode;
	}
}

template< class value_type >
void linkeddeque<value_type>::push_front(const value_type& x) {
	if (this->empty()) {
		node<value_type>* newnode = new node<value_type>;
		newnode->e = x;
		this->head = newnode;
		this->tail = newnode;
		this->head->prev = nullptr;
		this->tail->next = nullptr;
	}
	else {
		node<value_type>* newnode = new node<value_type>;
		newnode->e = x;
		newnode->prev = nullptr;
		newnode->next = this->head;
		this->head->prev = newnode;
		this->head = newnode;
	}
}

template< class value_type >
void linkeddeque<value_type>::print_deque() const {
	node<value_type>* iter;
	iter = this->head;
	cout << "Deque: [";
	while (iter != nullptr) {
		if (iter->next == nullptr) {
			cout << iter->e;
		}
		else {
			cout << iter->e << ", ";
		}
		iter = iter->next;
	}
	cout << "]." << endl;
}

template< class value_type >
void linkeddeque<value_type>::operator=(const linkeddeque<value_type>& q) {
	node<value_type>* iter;
	iter = this->head;
	while (iter != nullptr) {
		this->pop_front();
		iter = iter->next;
	}
	node<value_type>* iterq;
	iterq = q.head;
	while (iterq != nullptr) {
		this->push_back(iterq->e);
		iterq = iterq->next;
	}
}

template< class value_type >
bool linkeddeque<value_type>::operator==(const linkeddeque<value_type>& q) {
	if (this->empty() != q.empty()) {
		return false;
	}
	else {
		node<value_type>* iter;
		node<value_type>* iterq;
		iter = this->head;
		iterq = q.head;
		while (iter != nullptr && iterq != nullptr) {
			if (iter->e != iterq->e) {
				return false;
			}
			iter = iter->next;
			iterq = iterq->next;
		}
		if (iter == iterq) {
			return true;
		}
		return false;
	}
}



#endif // !LINKEDDEQUE_HPP_INCLUDED