#include "std_lib_facilities.h"

//Opg. 1
enum class Suit {clubs=1, diamons, hearts, spades};
enum class Rank {two=2, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace};
string suitToString(Suit suit);
string rankToString(Rank rank);


//Opg. 2
class Card{
    private:
        Suit s; 
        Rank r;
    public:
        Card();
        Card(Suit suit, Rank rank);
        Suit getSuit();
        Rank getRank();
        string toString();
        string toStringShort();
};

//Opg. 3
Suit operator++(Suit& s);
Rank operator++(Rank& r);
