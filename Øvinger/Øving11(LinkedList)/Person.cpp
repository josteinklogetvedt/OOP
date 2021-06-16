#include "Person.h"

Person::Person(std::string first, std::string last)
    :firstname{first}, lastname{last}{}

std::ostream& operator<<(std::ostream& os, Person& p){
    os << p.firstname << " " << p.lastname;
    return os;
}

bool operator<(const Person& p1, const Person& p2){ //Sorterer etter lastname
    if (p1.getLastname() == p2.getLastname()){
        return p1.getFirstname() < p2.getFirstname(); //Sjekker fornavn hvis de har likt etternavn
    }return p1.getLastname() < p2.getLastname();  
}

void insertOrdered(std::list<Person> &l, const Person& p){
    bool inserted = false;
    for (auto it = l.begin(); it != l.end(); ++it){
        if (p < *it && !inserted){
            l.insert(it, p);
            inserted = true;
        }
    }
    if (!inserted){
        l.push_back(p);
    }
}

void printList(std::list<Person> &l){
    for (auto it =l.begin();  it != l.end(); ++it){
		std::cout << *it << std::endl;
	}
}

