#include "std_lib_facilities.h"

//Opg. 1
class Animal{
    protected:
        string name;
        int age;
    public:
        Animal(string n, int a)
            :name{n},age{a}{}
        virtual string toString() = 0;  //Gjør klassen abstrakt
};

class Dog : public Animal{
    public:
        Dog(string n, int a)
            :Animal{n,a}{}
        string toString() override;
};

class Cat : public Animal{
    public:
        Cat(string n, int a)
            :Animal{n,a}{}
        string toString() override;
};

void testAnimal();