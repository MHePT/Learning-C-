// Learning.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <iomanip>
#include "Subnetting.h"
#include "Vectors.h"
#include "Sorting.h"
#include "Structure.h"
#include "LargestNumber.h"
#include "Strings.h"
//#include "Namespaces.h"
#include "OOP.h"
#include "Inheritance.h"
#include "Friends.h"
#include "Stack.h"
#include "Exceptions.h"

using namespace std;

float square(float x); // Good Habit
void fun(int&); // Bad Habit
void by_ptr(int* ptr);
void Datatype_Sizes();
void Number_and_ASCII();
void Play_With_Pointers();
void Play_With_Vectors();
void Garbage();
void Run_Learning();


int main() {
	Run_Learning();
}

void Run_Learning() {

	int x = 1;

	Number_and_ASCII();
	cout << endl << endl;

	Play_With_Pointers();
	cout << endl << endl;

	Datatype_Sizes();
	cout << endl << endl;

	Play_With_Vectors();
	cout << endl << endl;

	Garbage();

	fun(x); // expressions will make compilation error (e.g. fun(x + 1) ) PASSED BY REFERENCE

}

float square(float x = 1) { // float x is formal parameter. void fun(void) is absolete. =1 is default parameter
	//x != 1. Fun but True.
	return x * x;
}

void fun(int& x) { // passing by reference it can be done with pointer like C but risky and not recommended
}

void by_ptr(int* ptr) {
	*ptr = *ptr + 1;
}

void Datatype_Sizes() {

	int x = 1, * p = nullptr; // same as = NULL or = 0

	cout << "Size of Char in bytes " << sizeof(char) << endl;
	cout << "Size of Pointer in bits " << sizeof(p) * 8 << endl;
	cout << "Size of Int in bits " << sizeof x * 8 << endl;
	cout << "Size of Double in bytes " << sizeof 3.14444444 << endl;

	delete p;

}

void Number_and_ASCII() {

	char c = 'T';
	int x = 1;

	x = x << 2;

	cout << 0b111 << endl << 0x111 << endl << 0111 << endl << 111 << endl;
	cout << hex << 111 << endl << oct << 111 << endl << dec << 111.0f << endl;
	cout << "\a" << setbase(10) << 300'000'000l << endl << 3e8 << endl; // \r reprint the line
	cout << "\124\x65\x73\164" << endl;
	cout << c << endl << static_cast<int>(c) << endl;
	cout << sqrtf(2) << endl << sqrt(2) << endl << sqrtl(2) << endl; //infinit loop : for(;;) = for(1;1;1)
	if (true and not false xor true or not false or 1 > 0 ? 1 : 0)
		Network4("192.168.1.1", "/24"); // &AND |OR ^XOR ~NOT
	cout << endl << x << endl;
	cout << square(2.f) << endl;// 2 is actual parameter or argument
	cout << ('A' < 'a') << endl; // 1

}

void Play_With_Pointers() {

	int x = 1;
	int* p=NULL;//Same as = 0
	int variable = 1;
	int* pointerr = &variable;
	void* pointer = 0;//*pointer = 0; PROHIBTED Serious problems

	p = &x; // p points to x
	cout << *p << endl; // value of x (Derefrencing)
	*p = 30; // now x == 30
	cout << x << endl;
	by_ptr(pointerr);// Adding 1 to variable by using the pointer
	cout << "variable = " << variable << endl;

	//delete p;
	//delete pointerr;
	delete pointer;
}

void Play_With_Vectors() {

	vector<int> vect{ 1, 2, 3 };
	int* ptr = vect.data();
	int* ptr2 = &vect[0];
	cout << (ptr == ptr2) << endl; //True
	ptr = vect.data() + 1;
	ptr[-1] = *ptr + ptr[1];
	cout << vect[0] << endl; // It's 5

	//delete ptr;
	//delete ptr2;

}

void Garbage() {

	int* garbage = new int;

	cout << *garbage << endl;

	delete garbage;//delete[] for array release

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
