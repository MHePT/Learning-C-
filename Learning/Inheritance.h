#pragma once
#ifndef __INHERITANCE__
#define __INHERITANCE__

#include <iostream>

using namespace std;

class Pet {
protected:
    string name;
public:
    Pet(string n);
    void run();
    void make_sound();
};

class Dog : public Pet {
public:
    Dog(string n);
    void run();
    void make_sound();
};

class Cat : public Pet {
public:
    Cat(string n);
    void run();
    void make_sound();
};

void run_Inheritance1();

class Pet2 {
protected:
    string name;
public:
    Pet2(string n);
    virtual void make_sound();// Polimorphism Phenomenon
    void name_me(string name);
};

class Cat2 : public Pet2 {
public:
    Cat2(string n);
    void make_sound();
};

class Dog2 : public Pet2 {
public:
    Dog2(string n);
    void make_sound();
};

//void play_with_pet_by_value(string name, Pet2 pet);
//void play_with_pet_by_pointer(string name, Pet2* pet);
//void play_with_pet_by_reference(string name, Pet2& pet);
void run_Inheritance1();
void run_Inheritance2();
void run_Inheritance3();
//int fun(const int n);
//int fun(const int& n);

#endif
