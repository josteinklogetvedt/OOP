#include "intermezzo.h"


//3a)   Tipper den først skriver ut 4,4,4 også 4,3,5
//3b)   Stemte ikke. Skriver ut 4,4,4 også 5,5,5. ANtageligvis fordi alle pekerne peker på samme objektet, så når 
//      objektet blir endret på på slutten fra c* vil også a* og b* få endret verdi.
using namespace std;
void dummyTest() {
    Dummy a;
    *a.num = 4;
    Dummy b{a};
    Dummy c;
    c = a;
    cout << "a: " << *a.num << endl;
    cout << "b: " << *b.num << endl;
    cout << "c: " << *c.num << endl;
    *b.num = 3;
    *c.num = 5;
    cout << "a: " << *a.num << endl;
    cout << "b: " << *b.num << endl;
    cout << "c: " << *c.num << endl;

    std::cin.get();  // For å hindre at programmet avslutter med en gang
}

Dummy::Dummy(const Dummy& d)
    :num{new int{*d.num}}{}

Dummy& Dummy::operator=(const Dummy& d){
    delete num;
    int* temp = new int{*d.num};
    num = temp;
    return *this;
}