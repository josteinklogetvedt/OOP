#include "Meeting.h"

ostream& operator<<(ostream& os, Campus& city){
    os << loc.at(city);
    return os;
}

//Meeting
void Meeting::addParticipants(const Person* part){
    participants.insert(part);
}
set<const Meeting*> Meeting::meetings;

Meeting::Meeting(int d, int sTime, int eTime, Campus loc, string subj, const Person* lead)
    :day{d},startTime{sTime},endTime{eTime},location{loc},subject{subj},leader{lead}{
        addParticipants(lead);
        meetings.insert(this);
    }

Meeting::~Meeting(){
    meetings.erase(this);
}

vector<string> Meeting::getParticipantList(){
    vector<string> list;
    for (auto p : participants){
        list.push_back(p->getName());
    }
    return list;
}

ostream& operator<<(ostream& os, Meeting& meetup){
    os << meetup.getSubject() << " " << meetup.getLocation() << " " << meetup.getstartTime() << " " << meetup.getEndTime() 
    << " " << meetup.getLeader() << endl;
    vector<string> vec_participants{meetup.getParticipantList()};
    os << "Participants:" << endl;
    for (auto p : vec_participants){
        os << " " << p; 
    }
    return os;
}

vector<const Person*> Meeting::findPotentialCoDriving(){ 
    vector<const Person*> potCoDriving;
    for (auto meetingP : meetings){   //Går gjennom alle meetings utenom 'this' og sjekker betingelsene for ¨så gå gjennom participants og legger til person* hvis setet er ledig
        if (meetingP != this && meetingP->location == location && meetingP-> day == day && 
        abs(meetingP->startTime-startTime) <=1 && abs(meetingP->endTime - endTime) <= 1){
            
            for (auto partP : meetingP->participants){
                if (partP->hasAvailableSeats()){
                    potCoDriving.push_back(partP);
                }
            }
        }
    }
    return potCoDriving;
}