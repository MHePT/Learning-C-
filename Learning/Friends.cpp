#include "Friends.h"

void Class1::print() {
	cout << "It's a secret, that field = " << field << endl;
}


void Friend::do_it(Class1& c){
	c.field = 100;
	c.print();
}


void run1(){
	Class1 o;
	Friend f;

	f.do_it(o);

}/*Output is
*	It's a secret, that field = 100
*/

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	~~~~~FRIENDSHIP RULES~~~~~
	~a class may be a friend of many classes
	~a class may have many friends
	~my friend’s friend isn’t my friend
	~friendship isn’t inherited – the subclass has to define its own friendships

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

void A_F::print(){
		cout << "It's a secret, that field = " << field << endl;
}


void B_F::do_it(A_F& a){
	a.print();
}


void do_it(A_F& a){
	a.field = 99;
}


void run2(){

	A_F a; B_F b;

	do_it(a);
	b.do_it(a);

}/* Output is
*	It's a secret, that field = 99
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