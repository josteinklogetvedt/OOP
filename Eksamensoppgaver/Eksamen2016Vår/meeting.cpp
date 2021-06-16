#include "meeting.h"

Meeting::Meeting(int day, int start, int end, Campus location, Person *owner)
    :day{day},start{start},end{end},location{location},owner{owner}{
        allMeetings = this;
    }

void Meeting::addParticipant(Person *person){
    Participant* ptr = firstPart;
    if (ptr == nullptr){
        firstPart = new Participant{person};
        return;
    }
    while (true){
        if (ptr->getNext()==nullptr){
            ptr->setNext(new Participant{person});
            break;
        }else{
            ptr = ptr->getNext();
        }
    }
}

void Meeting::printCoDriving(){
    Meeting* p = allMeetings;
    while(p != nullptr){
        if (location==p->location && day == p->day && abs(start - p->start)<=1 &&  abs(end - p->end)<=1){
            cout << "Possible co‐driving for meeting in " <<  Campus::AAL <<  " on day " << day << " from " << start << " to " << end << " by " << owner->getMail() << endl;
            Participant* part = p->getParticipants();
            while (part!=nullptr){
                cout << part ->getWho()->getMail() << endl;
                part = part->getNext();
            }
            p = p->getNext();
        }    
    }
}
 
Meeting::~Meeting(){
    Participant* p = firstPart;
    while (p != nullptr){
        Participant* next = p->getNext();
        delete p;
        p = next;
    }
}