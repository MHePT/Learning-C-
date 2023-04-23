#pragma once
#ifndef __OVERLOADEDOPERATORS__
#define __OVERLOADEDOPERATORS__

#include <iostream>

using namespace std;



class Arr {
    int a, b, c, d;
public:

    Arr();
    int& operator[] (int index);
};

class Fun {
public:
    int operator() (int a1, int a2);
    int operator() (int a1, int a2, int a3);
};


class P {
public:

    int no;

    P(int n);
    P();

    string operator&();
};



P& operator*(string s);

void run_operator();

#endif // !__OVERLOADEDOPERATORS__
