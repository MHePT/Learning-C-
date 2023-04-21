#pragma once
#ifndef __FRIENDS__
#define __FRIENDS__

#include <iostream>

using namespace std;

class Class1 {
	friend class Friend;
	int field;
	void print();
};

class Friend {
public:
	void do_it(Class1& c);
};

void run1();

class A {
	friend class B;
	friend void do_it(A&);
private:
	int field;
protected:
	void print();
};

class B {
public:
	void do_it(A& a);
};

void do_it(A& a);
void run2();


#endif