#include "std_lib_facilities.h"

//Opg. 1
class Car{
    private:
        int freeSeats;
    public:
        Car(int fS)
            :freeSeats{fS}{}
        bool hasFreeSeats() const;
        void reserveFreeSeat();
};

//Opg. 2 
class Person{
    private:
        string name;
        string email;
        Car* carP;
    public:
        Person(string na,string em, Car* ca = nullptr);  //Kan man ha samme navn i parameterliste og de man skal initialisere?
        string getName() const;
        string getEmail() const;
        void setEmail(string emailNew);
        bool hasAvailableSeats() const;    
        friend ostream& operator<<(ostream& os, const Person& p); 
};