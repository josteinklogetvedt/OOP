#include "Card.h"

//Opg. 3
class CardDeck{
    private:
        vector<Card> cards;
    public:
        CardDeck();
        //CardDeck(vector<Card> deckOfCards);
        void swap(int a, int b);              //swap må settes i public for at den skal kunne nås etterpå
        void print();
        void printShort();
        void shuffle();
        Card drawCard();
};
