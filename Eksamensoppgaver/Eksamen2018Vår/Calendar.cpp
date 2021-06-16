#include "Calendar.h"

bool isLeapYear(int year){
    if (year % 4==0){
        if (year % 100 == 0 && year % 400 != 0){
            return false;
        }else{return true;}
    }
    return false;
}

 int daysInMonth(int m, int y){ //m(1-12)
    if (m==2){   //Februar
        if (isLeapYear(y)){
            return months[m-1] + 1;
        }
    }
    return months[m-1];
 }

 int dayNo(Date day){
    int numberOfDays=0;
    for (int i=1; i< day.m; ++i){
        numberOfDays += daysInMonth(i, day.y);
    }
    return numberOfDays+day.d;
 }

Date stringToDate(string str){  //På formatet "YYYY‐MM‐DD"
        int day = stoi(str.substr(8,2));
        int month = stoi(str.substr(5,2));
        int year = stoi(str.substr(0,4));
        Date date{day,month,year};
        return date;
}

bool checkDate(Date day){
    if (day.m>0 && day.m<13){
        if (day.d>0 && day.d<=daysInMonth(day.m, day.y)){
            return true;
        }
    }
    return false;
}

string dateToString(const Date& day){
    if (!checkDate(day)){
        return "INVALID DATE";
    }
    string d = to_string(day.d);
    string m = to_string(day.m);
    string y = to_string(day.y);
    if (d.size()<2){d = "0"+d;}
    if (m.size()<2){m = "0"+m;}
    for (int i=1; i<4; ++i){
        if (y.size()==i){
            y = "0" + y;
        }
    }
    return y + "-" + m + "-" + d;
}

ostream & operator<<(std::ostream & out, const Event & rhs){
    out << rhs.id << " : " << rhs.name << " @ " << dateToString(rhs.when);
    return out;
}

void printEvents(vector<Event*> &events){
    for (auto p : events){
        cout << *p << endl;
    }
    cout << events.size() << " events" << endl;
}

void Calendar::addEvent(int id, string name, int year, int month, int day){
    Date date{day, month, year};
    if (checkDate(date) && events.find(id)==events.end()){
        events[id] = new Event{name, id, date};
    }else{throw "exception";}
}

Calendar::~Calendar(){
    for (auto p : events){
        delete p.second
    }
}

vector<Event*> Calendar::getEvents(int year, int month, int day){
    vector<Event*> eventsAtDate;
    for (auto p : events){
        if (p.second -> when.d == day && p.second -> when.m == month && p.second -> when.y == year){
            eventsAtDate.push_back(p.second);
        }
    }
    return eventsAtDate;
}

vector<Date> Calendar::busyDates(int threshold){
    map<Date, int> dateFreq;
    for (auto p : events){
        dateFreq[p.second->when]++;
    }
    vector<Date> datesOverThreshold;
    for (auto p: dateFreq){
        if (p.second >= threshold){
            datesOverThreshold.push_back(p.first);
        }
    }
    return datesOverThreshold;    
}