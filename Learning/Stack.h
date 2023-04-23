#pragma once
#ifndef __STACK__
#define __STACK__

#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;

class Stack {

    int* stack;
    int Size;
    int Top;

public:

    Stack(int Size = 100);
    ~Stack();
    bool push(int value);
    Stack& operator<< (int value);
    int pop();
    Stack& operator>> (int& value);
    bool isEmpty();
    bool isFull();

};

class stack_size_error : public length_error {
public:
    explicit stack_size_error(const string& msg);
};

class stack_bad_alloc : public bad_alloc {
public:
    explicit stack_bad_alloc(const string& msg);
};

class stack_overflow : public logic_error {
public:
    explicit stack_overflow(const string& msg);
};

class stack_empty : public logic_error {
public:
    explicit stack_empty(const string& msg);
};

#endif