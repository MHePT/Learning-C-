#include <iostream>

using namespace std;

class Class {
	friend class Friend;
	int field;
	void print(){
		cout << "It's a secret, that field = " << field << endl;
	}
};

class Friend {
public:
	void do_it(Class& c){
		c.field = 100;
		c.print();
	}
};
/*
int main(){
	Class o;
	Friend f;
	f.do_it(o);

}Output is
	It's a secret, that field = 100
*/

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	~~~~~FRIENDSHIP RULES~~~~~
	~a class may be a friend of many classes
	~a class may have many friends
	~my friend’s friend isn’t my friend
	~friendship isn’t inherited – the subclass has to define its own friendships

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/


class A {
	friend class B;
	friend void do_it(A&);
private:
	int field;
protected:
	void print(){
		cout << "It's a secret, that field = " << field << endl;
	}
};
class B {
public:
	void do_it(A& a){
		a.print();
	}
};

void do_it(A& a){
	a.field = 99;
}
/*
int main(){
	A a; B b;
	do_it(a);
	b.do_it(a);
} Output is
	It's a secret, that field = 99
*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	~~~~~FRIENDSHIP RULES~~~~~
	~a friendship declaration must contain a complete prototype of the friend function (including return type);
	a function with the same name, but incompatible in the sense of the parameters’ conformance, 
	will not be recognized as a friend
	~a class may have many friend functions
	~a function may be a friend of many classes
	~a class may recognize as friends both global and member functions

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/