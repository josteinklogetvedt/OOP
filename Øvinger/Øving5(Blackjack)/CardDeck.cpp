#include "CardDeck.h"

//Opg. 3
//CardDeck::CardDeck(vector<Card> deckOfCards){ //Constructor med input, trenger man to constructører?
//    cards = deckOfCards;
//}

CardDeck::CardDeck(){       //Default constructor, lager en helt ny kortstokk. Trenger man å definere operatoren ++ for Rank og Suit?
    Suit suit{Suit::clubs};
    Rank rank{Rank::two};
    Card card {suit,rank};
    for (int i=0; i<4;++i){
        for (int j=0; j<13; ++j){
            card = {suit,rank};
            cards.push_back(card);
            ++rank;
        }
    ++suit;
    }
}

void CardDeck::swap(int a, int b){
    Card temp = cards[a];
    cards[a] = cards[b];
    cards[b] = temp;    
}

void CardDeck::print(){
    for (int i=0; i<cards.size(); ++i){
        cout << cards[i].toString() << endl;
    }
}

void CardDeck::printShort(){
    for (int i=0; i<cards.size();++i){
        cout << cards[i].toStringShort() << endl;
    }
}

//Bruker swap 100 ganger på tilfeldige indekser
void CardDeck::shuffle(){
    int a = 0;
    int b = 0;
    int amountOfCards = 52;
    for (int n=0; n<100; ++n){
        a = rand()%(amountOfCards);
        b = rand()%(amountOfCards);
        swap(a,b);      //Får man feilmelding hvis a=b?
    }
}

Card CardDeck::drawCard(){
    Card card;
    card = cards[cards.size()-1];
    cards.erase (cards.begin()+cards.size()-1);   //Hvorfor må man ha med cards.begin()? Får feilmelding uten.
    return card;
}