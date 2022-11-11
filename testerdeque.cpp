#include <iostream>
#include "arraydeque.hpp"
#include "linkeddeque.hpp"

using namespace std;


int main(int argc, char *argv[]) {
	int dim = 20;
	arraydeque<int> deque(dim);
	//linkeddeque<int> deque;

	try
	{
		deque.pop_back();
	}
	catch (invaliddequeoperator error)
	{
		error.print_error();
		cout << endl;
	}

	try
	{
		deque.pop_front();
	}
	catch (invaliddequeoperator error)
	{
		error.print_error();
		cout << endl;
	}

	try
	{
		deque.read_back();
	}
	catch (invaliddequeoperator error)
	{
		error.print_error();
		cout << endl;
	}

	try
	{
		deque.read_front();
	}
	catch (invaliddequeoperator error)
	{
		error.print_error();
		cout << endl;
	}

	deque.print_deque();
	cout << endl;

	try
	{
		for (int i = 0; i < dim - 5; ++i) {
			deque.push_front(i);
		}
	}
	catch (invaliddequeoperator error)
	{
		error.print_error();
		cout << endl;
	}

	cout << "Front element: " << deque.read_front() << endl << "Back element: " << deque.read_back() << endl;
	deque.print_deque();
	cout << endl;

	try
	{
		for (int i = 0; i < dim - 5; ++i) {
			deque.push_back(i);
		}
	}
	catch (invaliddequeoperator error)
	{
		error.print_error();
		cout << endl;
	}

	cout << "Front element: " << deque.read_front() << endl << "Back element: " << deque.read_back() << endl;
	deque.print_deque();
	cout << endl;

	try
	{
		for (int i = 0; i < 5; ++i) {
			deque.pop_back();
		}
	}
	catch (invaliddequeoperator error)
	{
		error.print_error();
		cout << endl;
	}

	cout << "Front element: " << deque.read_front() << endl << "Back element: " << deque.read_back() << endl;
	deque.print_deque();
	cout << endl;

	try
	{
		for (int i = 0; i < 3; ++i) {
			deque.pop_front();
		}
	}
	catch (invaliddequeoperator error)
	{
		error.print_error();
		cout << endl;
	}

	cout << "Front element: " << deque.read_front() << endl << "Back element: " << deque.read_back() << endl;
	deque.print_deque();
	cout << endl;

	arraydeque<int> deque2(dim);
	//linkeddeque<int> deque2;
	try
	{
		deque2 = deque;
	}
	catch (invaliddequeoperator error)
	{
		error.print_error();
		cout << endl;
	}

	cout << "Deque2:" << endl;
	deque2.print_deque();
	cout << endl;

	arraydeque<int> deque3(deque2);
	//linkeddeque<int> deque3(deque2);
	cout << "Deque3:" << endl;
	deque3.print_deque();
	cout << endl;

	deque3.pop_back();
	cout << "Deque3:" << endl;
	deque3.print_deque();
	cout << endl;

	cout << ((deque2 == deque3) ? "Deque2 and Deque3 equal." : "Deque2 and Deque3 not equal.") << endl;
	

	cout << endl;
	system("PAUSE");
	return 0;
}