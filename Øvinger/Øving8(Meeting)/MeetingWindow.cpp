#include "MeetingWindow.h"


MeetingWindow::MeetingWindow(Point xy, int w, int h, const string& title)
            :Window{xy, w, h, title}, 
            quitBtn{Point{x_max()-padX-btnW,padY},btnW,btnH, "Quit" ,cb_quit},
            personName{Point{fieldPad,padY}, fieldW, fieldH, "Name:"},
            personEmail{Point{fieldPad,2*padY+fieldH}, fieldW, fieldH, "Email:"},
            personNewBtn{Point{fieldPad,3*padY+2*fieldH},btnW,btnH,"Add", cb_new_person}
            {
                attach(quitBtn);
                attach(personName);
                attach(personEmail);
                attach(personNewBtn);
            }

void MeetingWindow::cb_quit(Address, Address pw){
    reference_to<MeetingWindow>(pw).hide(); 
}

void MeetingWindow::addPerson(){
    string name{personName.get_string()};
    string email{personEmail.get_string()};
    if ((name!="") && (email!="")){
        people.push_back(new Person{name,email});
    }
    personName.clear_value();
    personEmail.clear_value();
}

void MeetingWindow::cb_new_person(Address, Address pw){
    reference_to<MeetingWindow>(pw).addPerson();
}

void MeetingWindow::printPersons(){
    for (auto& p : people){
        cout << *p << endl;
    }
}