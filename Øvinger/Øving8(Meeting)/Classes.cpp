#include "Classes.h"

//Opg. 1
bool Car::hasFreeSeats() const{
    return freeSeats>0;
}

void Car::reserveFreeSeat(){
    if (hasFreeSeats()){
        freeSeats -= 1;
    }
}

//Opg. 2
Person::Person(string na, string em, Car* ca)
    :name{na},email{em},carP{ca}{}

string Person::getName() const {return name;}
string Person::getEmail() const {return email;}

void Person::setEmail(string emailNew){ 
    email = emailNew;
}
bool Person::hasAvailableSeats() const {
    if (carP == nullptr){return false;}
    return carP -> hasFreeSeats(); 
}
ostream& operator<<(ostream& os, const Person& p){
    os << p.name << " " << p.email << " " << endl;
    return os;
}