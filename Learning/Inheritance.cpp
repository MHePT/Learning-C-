#include "Inheritance.h"


Pet::Pet(string n){
    name = n;
}

void Pet::run(){
    cout << name << "the Pet says: I'm running" << endl;
}

void Pet::make_sound(){
    cout << name << " the Pet says: Shh! Shh!" << endl;
}

Dog::Dog(string n) : Pet(n) {}

void Dog::run() {
    cout << name << "the Dog says: I'm running" << endl;
}

void Dog::make_sound(){
    cout << name << "the Dog says: Woof! Woof!" << endl;
}


Cat::Cat(string n) : Pet(n) {};

void Cat::run() {
    cout << name << "the Cat says: I'm running" << endl;
}

void Cat::make_sound(){
    cout << name << "the Cat says: Meow! Meow!" << endl;
}


// This Example does not validate the input and can make validation error(Very big trouble)
void run_Inheritance1(){

    Pet *a_pet1 = new Cat("Tom");
    Pet *a_pet2 = new Dog("Spike");
    Dog *a_pet3 = new Dog("Dogy");
    Pet *a_pet32 = a_pet3; 



    a_pet1 -> run();

    static_cast<Dog *>(a_pet1) -> make_sound(); // DownCasting 

    a_pet2 -> run();

    //(Cat* (a_pet2)) -> make_sound(); // DownCasting

    a_pet3 -> run();

    ((Pet *) a_pet3) -> make_sound(); // UpperCasting

    a_pet32 -> make_sound(); // Uppercasting

    delete a_pet1;
    delete a_pet2;
    delete a_pet3;
    delete a_pet32;

}/* Output is
*
*    Tom the Pet says: I'm running
*    Tom the Dog says: Woof! Woof!
*    Spike the Pet says: I'm running
*    Spike the Cat says: Meow! Meow!
*    Dogy the Dog says: I'm running
*    Dogy the Pet says: Shh! Shh!
*    Dogy the Pet says: Shh! Shh!
*
*    it's a nightmare
*
*    C++ offer Solution:
*
*    a_pet1 -> run();
*
*    dynamic_cast<Cat *>(a_pet1) -> make_sound();
*
*    a_pet2 -> run();
*
*    try{dynamic_cast<Cat *> -> make_sound();} // error because it not casted not compatable returns null (==nullptr)
*    catch (...){}
*
*    dynamic_cast<Dog *> -> make_sound();
*
*
*    Output is
*    
*    Tom the Pet says: I'm running
*    Tom the Cat says: Meow! Meow!
*    Spike the Pet says: I'm running
*    Spike the Dog says: Woof! Woof!
*
*/


Pet2::Pet2(string n){
    name = n;
    make_sound();
}

void Pet2::make_sound(){// Polimorphism Phenomenon
    cout << name << " the Pet says: Shh! Shh!" << endl;
}

void Pet2::name_me(string name){
    this->name = name;
}


Cat2::Cat2(string n) : Pet2(n) { }

void Cat2::make_sound(){
    cout << name << " the Cat says: Meow! Meow!" << endl;
}


Dog2::Dog2(string n) : Pet2(n) { }

void Dog2::make_sound() {
    cout << name << " the Dog says: Woof! Woof!" << endl;
}


void play_with_pet_by_value(string name, Pet2 pet){ // Makes a copy of th object
    pet.name_me(name);
}

void play_with_pet_by_pointer(string name, Pet2* pet){
    pet->name_me(name);
    pet->make_sound();
}

void play_with_pet_by_reference(string name, Pet2& pet){
    pet.name_me(name);
    pet.make_sound();
}


void run_Inheritance2(){

    Pet2* a_pet1, * a_pet2;
    Cat2* a_cat;
    Dog2* a_dog;


    a_pet1 = a_cat = new Cat2("Kitty");

    a_pet2 = a_dog = new Dog2("Doggie");

    a_pet1->make_sound();

    a_cat->make_sound();

    static_cast<Pet2*>(a_cat)->make_sound();

    a_pet2->make_sound();

    a_dog->make_sound();

    static_cast<Pet2*>(a_dog)->make_sound();

    delete a_pet1;
    delete a_pet2;
    delete a_cat;
    delete a_dog;

}/* Output is
*    Kitty the Pet says: Shh! Shh!
*    Doggie the Pet says: Shh! Shh!
*    Kitty the Cat says: Meow! Meow!
*    Kitty the Cat says: Meow! Meow!
*    Kitty the Cat says: Meow! Meow!
*    Doggie the Dog says: Woof! Woof!
*    Doggie the Dog says: Woof! Woof!
*    Doggie the Dog says: Woof! Woof!
*/

void run_Inheritance3(){

    Pet2 *p1  = new Pet2("P1");
    Pet2  p2("P2");


    play_with_pet_by_pointer("anonymous", p1);
    play_with_pet_by_reference("no_name", p2);
    play_with_pet_by_pointer("no_name", &p2);
    play_with_pet_by_reference("anonymous", *p1);

    delete p1;

}/* Output is
*    anonymous the Pet says:  Shh! Shh!
*    no_name the Pet says:  Shh! Shh!
*    no_name the Pet says:  Shh! Shh!
*    anonymous the Pet says:  Shh! Shh!
*/


int fun(const int n){ // The Variable will not be modified niether inside or outside the function
    return n * n;
}

int fun(const int& n){//Compiler: "I’m not going to modify your actual parameter"

    return n/n; // n++ gives error

}/*If the function is constant e.g. int fun() const{}; it will not invok any non const function or change
 the class variables
 Constant object can't invoke functions nor modify variables 
 */