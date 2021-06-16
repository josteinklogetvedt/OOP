#include "Meeting.h"
#include "GUI.h"

using namespace Graph_lib;

static const int padY{y_max()/50};  //Ikke constexpr fordi veridene avhenger av y_max() og x_max()
static const int fieldH{2*padY};
static const int btnH{2*padY};
static const int padX{x_max()/50};
static const int fieldPad{padX*2};
static const int fieldW{fieldPad};
static const int btnW{fieldW};

class MeetingWindow : public Window{
    private:
        Button quitBtn;
        Button personNewBtn;
        In_box personName;
        In_box personEmail;
        Vector_ref<Person> people;

        static void cb_quit(Address, Address pw);
        static void cb_new_person(Address, Address pw);
        void addPerson();
    public:
        MeetingWindow(Point xy, int w, int h, const string& title);
        void printPersons();
};

