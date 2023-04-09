#include <iostream>

class Pet {
protected:
    string name;
public:
    Pet(string n){
        name = n;
    }
    void run(){
        cout << name << "the Pet says: I'm running" << endl;
    }
        cout << name << " the Pet says: Shh! Shh!" << endl;
    }
};

class Dog : public Pet {
public:
    Dog(string n) : Pet(n) {};
        cout << name << "the Dog says: I'm running" << endl;
    }
    void make_sound(){
        cout << name << "the Dog says: Woof! Woof!" << endl;
    }
};

class Cat : public Pet {
public:
    Cat(string n) : Pet(n) {};
        cout << name << "the Cat says: I'm running" << endl;
    }
    void make_sound(){
        cout << name << "the Cat says: Meow! Meow!" << endl;
    }
};

/* This Example does not validate the input and can make validation error(Very big trouble)
int main(){
    Pet *a_pet1 = new Cat("Tom");
    Pet *a_pet2 = new Dog("Spike");

    a_pet1 -> run();
    static_cast<Dog *>(a_pet1) -> make_sound(); // DownCasting 
    a_pet2 -> run();
    (Cat* (a_pet2)) -> make_sound(); // DownCasting
} Output is

    Tom the Pet says: I'm running
    Tom the Dog says: Woof! Woof!
    Spike the Pet says: I'm running
    Spike the Cat says: Meow! Meow!
    Dogy the Dog says: I'm running
    Dogy the Pet says: Shh! Shh!
    Dogy the Pet says: Shh! Shh!

    it's a nightmare

    C++ offer Solution:

    a_pet1 -> run();
    dynamic_cast<Cat *>(a_pet1) -> make_sound();
    a_pet2 -> run();
    try{dynamic_cast<Cat *> -> make_sound();} // error because it not casted not compatable returns null (==nullptr)
    dynamic_cast<Dog *> -> make_sound();

    Output is
    
    Tom the Pet says: I'm running
    Tom the Cat says: Meow! Meow!
    Spike the Pet says: I'm running
    Spike the Dog says: Woof! Woof!

*/


class Pet2 {
protected:
    string name;
public:
    Pet2(string n){
        name = n;
    }
    virtual void make_sound(){// Polimorphism Phenomenon
        cout << name << " the Pet says: Shh! Shh!" << endl;
    }
        this->name = name;
    }
    void make_sound(){
        cout << name << " says: no comments" << endl;
    }
};

class Cat2 : public Pet2 {
public:
    Cat2(string n) : Pet2(n) { }
    void make_sound(){
        cout << name << " the Cat says: Meow! Meow!" << endl;
    }
};

class Dog2 : public Pet2 {
public:
    Dog2(string n) : Pet2(n) { }
    void make_sound() {
        cout << name << " the Dog says: Woof! Woof!" << endl;
    }
};
{
    pet.name_me(name);
}
    pet->name_me(name);
    pet->make_sound();
}

void play_with_pet_by_reference(string name, Pet2& pet){
    pet.name_me(name);
    pet.make_sound();
}
/*
int main(){
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
} Output is
    Kitty the Pet says: Shh! Shh!
    Doggie the Pet says: Shh! Shh!
    Kitty the Cat says: Meow! Meow!
    Kitty the Cat says: Meow! Meow!
    Kitty the Cat says: Meow! Meow!
    Doggie the Dog says: Woof! Woof!
    Doggie the Dog says: Woof! Woof!
    Doggie the Dog says: Woof! Woof!


int main(){
    Pet *p1  = new Pet();
    Pet  p2;

    play_with_pet_by_pointer("anonymous", p1);
    play_with_pet_by_reference("no_name", p2);
    play_with_pet_by_pointer("no_name", &p2);
    play_with_pet_by_reference("anonymous", *p1);
} Output is
    anonymous says: no comments
    no_name says: no comments
    no_name says: no comments
    anonymous says: no comments
*/