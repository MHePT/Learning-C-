#pragma once
#ifndef __OOP__
#define __OOP__

#include <iostream>

using namespace std;

class Stack_OOP {
private://We can ommit it. The default is private in C++

	int* Stack_arr;
	int Top;//Created in Stack
	int Size;//Created in Stack
	static int Counter; //Created in Stack
	/*Constant pointer:
	int * const ptr; // --ptr is PROHIBTED

	Pointer To constant:
	const int *ptr; // *ptr = 0; is PROHIBTED
	int const *ptr;

	Constant pointer To constant:
	const int * const iptr; // Either --ptr; or *ptr = 0; is PROHIBTED
	int const * const iptr;*/

public:

	Stack_OOP(int Size = 10);
	Stack_OOP(Stack_OOP const& source);//When want to copy a version of current object
		// when ommited it will be cloned without change in variables
		// const to not modify the source object

	~Stack_OOP();// Distructor
	bool isEmpty();
	bool isFull();
	bool push(int value);
	int pop();
};

class AddingStack : Stack_OOP { // like extends in Java
private://We can ommit it the default is private
	int sum;
public:

	AddingStack();
	bool push(int value);
	int pop();
	int Get_Sum();

};

class Element {
	int value;
public:
	Element(int value);
};

class Collection {
	Element el1, el2;
public:
	Collection();
};

class A {
public:
	A(A& src);
	A();
	void do_it();
};

class B {
public:
	B(B& src);
	B();
	void do_it();
};

class Compo {
public:
	Compo(Compo& src);
	Compo();
	A f1;//Constructed or Copied First
	B f2;//Constructed or Copied Second
};

void run_OOP1();

#endif // !__OOP__

