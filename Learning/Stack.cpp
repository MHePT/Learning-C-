#include "Stack.h"

stack_size_error::stack_size_error(const string& msg) : length_error(msg){ };
stack_bad_alloc::stack_bad_alloc(const string& msg) : bad_alloc(){ };
stack_overflow::stack_overflow(const string& msg) : logic_error(msg){ };
stack_empty::stack_empty(const string& msg) : logic_error(msg){ };

Stack::Stack(int Size) {
    this->Size = Size;
    if (this->Size <= 0)
        throw stack_size_error("stack size must be >= 0");
    try {
        stack = new int[this->Size];
    }catch (bad_alloc& ba) {
        throw stack_bad_alloc("Memory is full. Cannot allocate Stack");
    }
    Top = -1;
}

Stack::~Stack() {
    delete[] stack;
}

bool Stack::isEmpty(){
    return Top == -1;
}

bool Stack::isFull() {
    return Top == Size;
}

int Stack::pop() {
    if (isEmpty())
        throw stack_empty("Stack is Empty");
    return stack[Top--];
}

bool Stack::push(int value) {

    if (isFull())
        throw stack_overflow("Stack is Full Cannot add new Data");
    stack[++Top]= value;
    return true;
}