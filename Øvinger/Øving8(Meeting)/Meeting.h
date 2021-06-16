#include "Classes.h"

enum class Campus{Alesund, Oslo, Gjovik};
const map<Campus,string> loc {
    {Campus::Alesund, "Alesund"},
    {Campus::Gjovik,"Gjovik"},
    {Campus::Oslo,"Oslo" }
};
ostream& operator<<(ostream& os, Campus& city); 

class Meeting{
    private:
        int day;
        int startTime;
        int endTime;
        Campus location;
        string subject;
        const Person* leader;
        set<const Person*> participants;
        static set<const Meeting*> meetings; 
    public:
        Meeting(int day, int startTime, int endTime, Campus location, string subject, const Person* leader);
        ~Meeting();
        int getDay() {return day;}
        int getstartTime() {return startTime;}
        int getEndTime() {return endTime;}
        Campus& getLocation() {return location;}
        string getSubject() {return subject;}
        const Person& getLeader() {return *leader;}
        void addParticipants(const Person* part);
        vector<string> getParticipantList();
        vector<const Person*> findPotentialCoDriving();
};
ostream& operator<<(ostream& os, Meeting& meetup);