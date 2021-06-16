#pragma once 
#include "std_lib_facilities.h"

class Person{
private:
    int id;
    string mail;
public:
    Person(int id,string mail)
        :id{id},mail{mail}{}
    int getId() const{return id;}
    string getMail() const{return mail;}
    void setMail(const string& s){mail=s;}
};

class Driver : public Person{
private:
    string carType;
    int freeSeats;
public:
    Driver(string carType, int freeSeats, int id, string mail)
        :carType{carType},freeSeats{freeSeats},Person(id,mail){}
};

enum Campus { TRH, AAL, GJO };

class Participant {
private:
    Person* who;
    Participant* next;
public:
    Participant(Person *who)
        :who{who},next{nullptr}{} 
    Person* getWho() { return who;}
    void setNext(Participant* n) {next = n;}
    Participant* getNext() {return next; }
};

class Meeting; // Forward declaration for Meeting
Meeting *allMeetings = nullptr; // Linked list of all Meetings

class Meeting {
private:
    int day;    // Assumes 1..365, no leap‐year (ingen skudd‐år)
    int start;    // Start of meeting
    int end;    // End of meeting
    Campus location;     // Where is the meeting
    Person *owner;   // Pointer to Person‐object that owns the meeting
    Driver *driver;   // Points to a Driver (if there is any)
    Meeting *next; // Points to next object in linked list of Meeting‐objects
    Participant *firstPart; // Points to first participant of meeting
public:
    Meeting(int day, int start, int end, Campus location, Person *owner);
    ~Meeting();
    Meeting *getNext(){return next;}
    void addParticipant(Person *person);
    Participant *getParticipants(){return firstPart;}
    void printCoDriving();
};