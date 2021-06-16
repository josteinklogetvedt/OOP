#pragma once
#include "std_lib_facilities.h"

const int months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool isLeapYear(int year);
int daysInMonth(int m, int y);

struct Date {
    int d; // day
    int m; // month
    int y; // year
    Date(int d,int m,int y)
        :d{d},m{m},y{y}{}
};

int dayNo(Date day);
Date stringToDate(string str);
bool checkDate(Date day);
string dateToString(const Date& day);

struct Event{
    string name;
    int id;
    Date when;
    Event(string name, int id, Date when)
        :name{name},id{id},when{when}{}
};

ostream & operator<<(std::ostream & out, const Event & rhs);
void printEvents(vector<Event *> &events);

class Calendar {
    private:
        string name; // name of calendar
        map<int, Event*> events; // map of events indexed by id
    public:
        Calendar(string name) : name(name) {}
        ~Calendar();
        void addEvent(int id, string name, int year, int month, int day);
        vector<Event*> getEvents(int year, int month, int day);
        vector<Date> busyDates(int threshold);
};