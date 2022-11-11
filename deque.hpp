#ifndef DEQUE_HPP_INCLUDED
#define DEQUE_HPP_INCLUDED

#include <iostream>

using namespace std;

template < class value_type >
class deque {
public:
	virtual bool empty() const = 0;
	virtual value_type read_front() const = 0;
	virtual value_type read_back() const = 0;
	virtual void push_front(const value_type&) = 0;
	virtual void push_back(const value_type&) = 0;
	virtual void pop_front() = 0;
	virtual void pop_back() = 0;
};

class invaliddequeoperator {
public:
	invaliddequeoperator() {
		this->error = "Invalid operator!";
	}

	invaliddequeoperator invalidpop() {
		this->error = "Deque empty. Impossible to pop an element.";
		return *this;
	}

	invaliddequeoperator invalidpush() {
		this->error = "Deque full. Impossible to push an element.";
		return *this;
	}

	invaliddequeoperator invalidread() {
		this->error = "Deque empty. Impossible to read an element.";
		return *this;
	}

	invaliddequeoperator invalidassignment() {
		this->error = "Invalid assignment. The maximum dimension of the left deque is lesser than the maximum dimension of the right one.";
		return *this;
	}

	void print_error() {
		cout << error << endl;
	}

private:
	string error;
};


#endif // !DEQUE_HPP_INCLUDED