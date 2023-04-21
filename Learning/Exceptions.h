#pragma once
#ifndef __EXCEPTIONS__
#define __EXCEPTIONS__

#include <iostream>
#include <exception>
#include <stdexcept>//Logical Error

using namespace std;

class Class{
public:
    string msg;

    explicit Class(string txt); // Constructor can't be invoked implicitly: e.g. "B fun(){return 0;}" is wrong
    ~Class();
    void hello();
};

void do_calculations(int i) noexcept(false);
void run_Exception1();
void unexp();
void function_Exception1() throw(int, bad_exception);
void run_Exception2();
void function_Exception(int i);
void broker(int i);
void run_Exception3();

#endif