#include <iostream>

class Stack {
private://We can ommit it the default is private

	int* Stack_arr;
	int Top;//Created in Stack
	int Size;//Created in Stack
	static int Counter; //Created in Stack

public:

	Stack(int Size = 10) {
		this->Size = Size;
	//(*this).Size = Size; they are the same
		Stack_arr = new int[Size];//Created in heap
		Top = -1;
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
	sum += value;
	Stack::push(value);
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