#pragma once
#ifndef __VECTORS__
#define __VECTORS__

#include <iostream>
#include <vector>

using namespace std;

void runVector();

class V {
public:

    vector<int> vec;

    V(int a0 = 0, int a1 = 0);
    V operator+(V& arg);
    V operator>>(int arg);
    V& operator=(V& arg);
    bool operator==(V& arg);
    V& operator+=(V& arg);
    V& operator++();
    V operator++(int none);
};

int operator*(V& left, V& right);
int operator~(V& arg);
bool operator>(V& l, V& r);
V& operator+(V& left, V& right);

#endif // !__VECTORS__
