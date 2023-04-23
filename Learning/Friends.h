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

class A_F {
	friend class B_F;
	friend void do_it(A_F&);
private:
	int field;
protected:
	void print();
};

class B_F {
public:
	void do_it(A_F& a);
};

void do_it(A_F& a);
void run2();


#endif