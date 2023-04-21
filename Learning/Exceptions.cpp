#include "Exceptions.h"

Class::Class(string txt) : msg(txt) {
    cout << "Object [" << msg << "] constructed" << endl;
}

Class::~Class() {
    cout << "Object [" << msg << "] destructed" << endl;
}

void Class::hello() {
    cout << "Object [" << msg << "] says: hello" << endl;
}



void do_calculations(int i) noexcept(false){ // Will throws exception. noexcept(true) will not throw or noexcept

    if (i == 0)
        throw Class("exception 1");

    Class object("object");

    if (i == 1)
        throw Class("exception 2");

    object.hello();

    if (i == 2)
        throw Class("exception 3");

}



void run_Exception1(){

    for (int i = 0; i < 3; i++) {
        try {
            cout << "-------" << endl;
            do_calculations(i);
        }

        catch (Class& exc) {
            cout << "Caught!" << endl;
            cout << exc.msg << endl;
        }
    }
}/*  Output
*-------
*Object [exception 1] constructed
*Caught!
*exception 1
*Object [exception 1] destructed
*-------
*Object [object] constructed
*Object [exception 2] constructed
*Object [object] destructed
*Caught!
*exception 2
*Object [exception 2] destructed
*-------
*Object [object] constructed
*Object [object] says: hello
*Object [exception 3] constructed
*Object [object] destructed
*Caught!
*exception 3
*Object [exception 3] destructed
*/

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* We will show you Function header informing that it will throw exception in Old C++ (Prior < C++17)
* 
* void thrower() throw(Class,string); It Can throw Class and string exceptions
* 
* void thrower throw(); It will not throw exception
* 
*/

void unexp(){
    cout << "Unexpected exception arrived!" << endl;
    throw;
}

void function_Exception1() throw(int, bad_exception){
    throw 3.14;
}

void run_Exception2(){
    set_unexpected(unexp);//Handeling Unexpected Exception
    try {
        function_Exception1();
    }

    catch (double f) {
        cout << "Got double" << endl;
    }

    catch (bad_exception bad) {
        cout << "It's so bad..." << endl;
    }

    cout << "Done" << endl;
}/* Output
*Unexpected exception arrived!
*It's so bad...
*Done
*/

void function_Exception(int i){

    switch (i) {
    case 0: throw domain_error("0");
    case 1: throw logic_error("1");
    case 2: throw exception();
    case 3: throw range_error("2");
    case 4: throw "so bad";
    }

}

void broker(int i){
    try {
        function_Exception(i);
    }catch (...) {
        cout << "Broker swept problems under the carpet " << endl;
        throw;//It can throw another type of exception
    }
}

void run_Exception3(){

    for (int i = 0; i < 5; i++) {

        try {
            broker(i);
        }catch (logic_error& le) {
            cout << "Logic error: " << le.what() << endl;
        }catch (runtime_error& re) {
            cout << "Runtime error: " << re.what() << endl;
        }catch (exception& ex) {
            cout << "Exception: " << ex.what() << endl;
        }catch (...) {
            cout << "Something bad happened" << endl;
        }
    }
}/*Output
*Broker swept problems under the carpet
*Logic error: 0
*Broker swept problems under the carpet
*Logic error: 1
*Broker swept problems under the carpet
*Exception: Unknown exception
*Broker swept problems under the carpet
*Runtime error: 2
*Broker swept problems under the carpet
*Something bad happened
*/
