// Learning.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <iomanip>
#include "Subnetting.cpp"
#include "Vectors.cpp"
//#include "Sorting.cpp"
//#include "Structure.cpp"
//#include "LargestNumber.cpp"
//#include "Strings.cpp"
//#include "Namespaces.cpp"


using namespace std;

float square(float x); // Good Habit
void fun(int&); // Bad Habit

void by_ptr(int* ptr)

{

	*ptr = *ptr + 1;

}

int main() {
	char c = 'T';
	int x = 1, * p = nullptr; // same as = NULL or = 0
	void* pointer;//*pointer = 0; PROHIBTED Serious problems
	int* garbage = new int;
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
	cout << endl << endl;

	p = &x; // p points to x
	cout << *p << endl; // value of x (Derefrencing)
	*p = 30; // now x == 30
	cout << x << endl;
	cout << endl << endl;

	cout << "Size of Char in bytes " << sizeof(char) << endl;
	cout << "Size of Pointer in bits " << sizeof(p) * 8 << endl;
	cout << "Size of Int in bits " << sizeof x * 8 << endl;
	cout << "Size of Double in bytes " << sizeof 3.14444444 << endl;
	cout << endl << endl;


	vector<int> vect{ 1, 2, 3 };
	int* ptr = vect.data();
	int* ptr2 = &vect[0];
	cout << (ptr == ptr2) << endl; //True
	ptr = vect.data() + 1;
	ptr[-1] = *ptr + ptr[1];
	cout << vect[0] << endl; // It's 5
	cout << endl << endl;


	cout << square(2.f) << endl;// 2 is actual parameter or argument
	fun(x); // expression will make compilation error (e.g. fun(x + 1) )
	cout << *garbage << endl;
	delete garbage;//delete[] for array release


	int variable = 1;
	int* pointerr = &variable;
	by_ptr(pointerr);
	cout << "variable = " << variable << endl;

	cout << ('A' < 'a') << endl; // 1


}

float square(float x = 1) { // float x is formal parameter. void fun(void) is absolete. =1 is default parameter
	//x != 1. Fun but True.
	return x * x;
}

void fun(int& x) { // passing by reference it can be done with pointer like C but risky and not recommended
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
