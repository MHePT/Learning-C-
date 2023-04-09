#include <iostream>

using namespace std;

class Stack {
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

	Stack(int Size = 10) : Size(Size) , Top(-1){
		this->Size = Size;//Same effect
	//(*this).Size = Size; they are the same
		Stack_arr = new int[Size];//Created in heap
		++Counter;
	}

	Stack(Stack const &source) {//When want to copy a version of current object
		// when ommited it will be cloned without change in variables
		// const to not modify the source object
		++Counter;
	}

	~Stack() {// Distructor
		delete[] Stack_arr;
		delete Stack_arr;
	}

	bool isEmpty();

	bool isFull();

	bool push(int value) {

		if (isFull())
			return false;

		Stack_arr[++Top] = value;	
		return true;
	}

	int pop() {

		if (isEmpty())
			return -1;

		return Stack_arr[Top--];
	}
};

int Stack::Counter = 0;

bool Stack::isEmpty() {
	return Top == -1;
}

bool Stack::isFull() {
	return Top == Size;
}

class AddingStack : Stack { // like extends in Java
private://We can ommit it the default is private

	int sum;

public:

	AddingStack() : Stack(){
		sum = 0;
	}

	bool push(int value);
	int pop();
	int Get_Sum();

};

bool AddingStack::push(int value) {
	if (isFull())
		return false;
	sum += value;
	Stack::push(value);
	return true;
}

int AddingStack::pop() {
	int value = Stack::pop();
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


class Element {

	int value;

public:

	Element(int value){
		this->value = value;
		std::cout << "Element(" << value << ") constructed!" << std::endl;
	}

};



class Collection {

	Element el1, el2;

public:

	Collection() : el2(2), el1(1){// To invoke other constructor than the default
		std::cout << "Collection constructed!" << std::endl;
	}
	//or
	//Collection();

};
/*Collection::Collection() : el2(2) , el1(1){  };*/


class A {

public:

	A(A& src){

		cout << "copying A..." << endl;

	}

	A() { };

	void do_it(){

		cout << "A is doing something" << endl;

	}

};



class B {

public:

	B(B& src){

		cout << "copying B..." << endl;

	}

	B() { };

	void do_it(){

		cout << "B is doing something" << endl;

	}

};



class Compo {

public:

	Compo(Compo& src) : f2(src.f2), f1(src.f1){ // order doesn't matter they are not same type

		cout << "Copying Compo..." << endl;

	}

	Compo() { };

	A f1;//Constructed or Copied First
	B f2;//Constructed or Copied Second

};


/*
int main(){

	Compo  co1;
	Compo  co2 = co1;

	co2.f1.do_it();
	co2.f2.do_it();

} Output is
	copying A...
	copying B...
	Copying Compo...
	A is doing something
	B is doing something

*/