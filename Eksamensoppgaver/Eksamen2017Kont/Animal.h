#pragma once
#include "std_lib_facilities.h"

class Animal{
protected:
    string name;
    int age;             //Ettersom alle medlemsvariablene gjentar seg for Dog og Human burde alle være protected.
    vector<Animal*> friends;
public:
    Animal(string name, int age)
        :name{name}, age{age}{}
    virtual string toString(){return name;}   //Hvis det ikke er virtual vil dog og human sin toString ikke override animal 
                                                //sin og dermed kun skrive Jake og Finn (ikke the Dog og the Human).

    void addFriend(Animal* ani){
        friends.push_back(ani);
    }
    vector<Animal*> getFriends(){
        return friends;
    }
};

std::ostream & operator<<(std::ostream & out, Animal &a);


class Dog : public Animal{
private:
    string color;
public:
    Dog(string name, int age, string color)
        :Animal(name,age),color{color}{}
    string toString(){return name + " the Dog";}
};

class Human : public Animal{
public:
    Human(string name, int age)
        :Animal(name,age){}
    string toString(){return name + " the Human";}
};

Animal* parseAnimal(string line);
void parseFriends(map<string, Animal *> &animals, string line);
map<string, Animal *> readAnimals(string filename);