#include "Overloaded_Operators.h"

Arr::Arr(){
        a = b = c = d = 0;
}

int& Arr::operator[] (int index){//Can not be implemented as a global function

    switch (index) {
    case 1:  return a;
    case 2:  return b;
    case 3:  return c;
    case 4:  return d;
    default: throw range_error("bad index");
    }
}

int Fun::operator() (int a1, int a2){//Can not be implemented as a global function
    return a1 > a2 ? a1 : a2;
}

int Fun::operator() (int a1, int a2, int a3){//Can not be implemented as a global function
    return a1 > a2 ? (a1 > a3 ? a1 : a3) : (a2 > a3 ? a2 : a3);
}


P::P(int n) : no(n) { }

P::P() : no(0) { }

string P::operator&(){//pseudo-pointers or so-called smart pointers. can be used as key in database
    string res = "";

    switch (no) {
    case 0: res = "alpha";
    case 1: res = "bravo";
    case 2: res = "charlie";
    }

    return res;
}

P& operator*(string s){//pseudo-pointers or so-called smart pointers.  can be used as key in database

    P* p;

    if (!s.compare("alpha"))
        p = new P(0);

    else if (!s.compare("bravo"))
        p = new P(1);

    else if (!s.compare("charlie"))
        p = new P(2);

    else
        p = new P(-1);

    return *p;
}

void run_operator(){
    Fun f;
    cout << f(1, 2) << endl;
    cout << f(1, 2, 3) << endl;

    P p1(2);

    string s = &p1;
    P p2 = *s;

    cout << "'" << s << "' -> " << p2.no << endl;
}/*Output
~2
~3
~'charlie' -> 2
*/

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Non-overloadable operators
* ?:
* .
* ::
* sizeof
* 
* Other overloadable operators
*operator,
*operator->
*operator new
*operator new[]
*operator delete
*operator delete[]
*operator typename 
* 
* that using these operators falls into issues reserved strictly for the professional level of programming.
*/