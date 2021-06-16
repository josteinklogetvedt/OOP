#pragma once
#include <list>
#include <string>
#include <iostream>
#include <ostream>

class Person{
    private:
        std::string firstname;
        std::string lastname;
    public:
        Person(std::string first, std::string last);
        friend std::ostream& operator<<(std::ostream& os, Person& p);
        std::string getFirstname() const {return firstname;};
        std::string getLastname() const {return lastname;};        
};

bool operator<(Person& p1, const Person& p2);
void insertOrdered(std::list<Person> &l, const Person& p);
void printList(std::list<Person> &l);

