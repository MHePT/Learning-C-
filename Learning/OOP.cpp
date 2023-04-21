#include "OOP.h"

Stack_OOP::Stack_OOP(int Size) : Size(Size) , Top(-1){
	this->Size = Size;//Same effect
	//(*this).Size = Size; they are the same
	Stack_arr = new int[Size];//Created in heap
	++Counter;
}

Stack_OOP::Stack_OOP(Stack_OOP const &source) {//When want to copy a version of current object
	// when ommited it will be cloned without change in variables
	// const to not modify the source object
	++Counter;
}

Stack_OOP::~Stack_OOP() {// Distructor
		delete[] Stack_arr;
		delete Stack_arr;
}

bool Stack_OOP::push(int value) {

	if (isFull())
		return false;

	Stack_arr[++Top] = value;	
	return true;
}

int  Stack_OOP::pop() {

	if (isEmpty())
		return -1;

	return Stack_arr[Top--];
}


int Stack_OOP::Counter = 0;

bool Stack_OOP::isEmpty() {
	return Top == -1;
}

bool Stack_OOP::isFull() {
	return Top == Size;
}

AddingStack::AddingStack() : Stack_OOP(){
	sum = 0;
}


bool AddingStack::push(int value) {
	if (isFull())
		return false;
	sum += value;
	Stack_OOP::push(value);
	return true;
}

int AddingStack::pop() {
	int value = Stack_OOP::pop();
	sum -= value;
	return value;
}

int AddingStack::Get_Sum(){
	return sum;
}

/*Instances can be declared and accessed as following
Stack s1; //Created in Stack
Stack* s2 = new Stack , s3 = new Stack(100); // Created in heap

s1.push(1);
s2->push(2);
(*s3).push(3);

delete s2;
delete s3;

Instances can be copied or cloned as following
~~IT'S DANGEROUS AS Stack_arr IS SHARED AMONG ALL WITH SAME PIECE OF MEMORY ALLOCATED

Stack s2 = s1;
or 
Stack s2(s1);

can be mitigate it by:
	Stack(Stack const &source) {
	source.Stack_arr = new int[source.Size];
	}
*/

Element::Element(int value){
	this->value = value;
	std::cout << "Element(" << value << ") constructed!" << std::endl;
}


Collection::Collection() : el2(2), el1(1){// To invoke other constructor than the default
	std::cout << "Collection constructed!" << std::endl;
}	//or
	//Collection();


A::A(A& src){
	cout << "copying A..." << endl;
}

A::A() { };

void A::do_it(){
	cout << "A is doing something" << endl;
}


B::B(B& src){
	cout << "copying B..." << endl;
}

B::B() { };

void B::do_it(){
	cout << "B is doing something" << endl;
}


Compo::Compo(Compo& src) : f2(src.f2), f1(src.f1){ // order doesn't matter they are not same type
	cout << "Copying Compo..." << endl;
	}

Compo::Compo() { };

void run_OOP1(){

	Compo  co1;
	Compo  co2 = co1;

	co2.f1.do_it();
	co2.f2.do_it();

}/* Output is
*	copying A...
*	copying B...
*	Copying Compo...
*	A is doing something
*	B is doing something
*
*/