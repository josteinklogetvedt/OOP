#include "Card.h"

//Opg. 1
string suitToString(Suit suit){
    map<Suit,string> allSuits;
    allSuits.insert(make_pair(Suit::clubs,"Clubs"));
    allSuits.insert(make_pair(Suit::diamons,"Diamons"));
    allSuits.insert(make_pair(Suit::hearts,"Hearts"));
    allSuits.insert(make_pair(Suit::spades,"Spades"));
    return allSuits[suit];
}
string rankToString(Rank rank){
    map<Rank,string> allRanks;   //initilizer liste for map 
    allRanks.insert(make_pair(Rank::two,"Two"));
    allRanks.insert(make_pair(Rank::three,"Three"));
    allRanks.insert(make_pair(Rank::four,"Four"));
    allRanks.insert(make_pair(Rank::five,"Five"));
    allRanks.insert(make_pair(Rank::six,"Six"));
    allRanks.insert(make_pair(Rank::seven,"Seven"));
    allRanks.insert(make_pair(Rank::eight,"Eight"));
    allRanks.insert(make_pair(Rank::nine,"Nine"));
    allRanks.insert(make_pair(Rank::ten,"Ten"));
    allRanks.insert(make_pair(Rank::jack,"Jack"));
    allRanks.insert(make_pair(Rank::queen,"Queen"));
    allRanks.insert(make_pair(Rank::king,"King"));
    allRanks.insert(make_pair(Rank::ace,"Ace"));
    return allRanks[rank];
}
//1e) Det er lettere å jobbe med symboler enn tall. 
//    Og en til...?

//Opg. 2
Card::Card()  //Default constructor, hvorfor må man ha de parantesene på slutten?
    :s{Suit::clubs},r{Rank::two}
{
}                                
Card::Card(Suit suit, Rank rank)  //Usikker på om det er vits i med to konstruktører, én som tar input og en defualt.
    :s{suit},r{rank}
{    
}
Suit Card::getSuit(){
    return s;
}
Rank Card::getRank(){
    return r;
}
string Card::toString(){
    return rankToString(r) + " of " + suitToString(s);
}
string Card::toStringShort(){
    string valueRank = to_string(static_cast<int>(r));
    char shortSuit = suitToString(s)[0];     //Hvorfor kan man ikke skrive suitToString(s)[0]?
    return shortSuit + valueRank; 
}

//Opg. 3
Suit operator++(Suit& s){    //Lager ++ operator for å lage en default constructor som lager en ny kortstokk
    if (s == Suit::spades){
        s = Suit::clubs;
    }else{
        s = Suit(int(s)+1);    
    }
    return s;
}

Rank operator++(Rank& r){
    if (r == Rank::ace){
        r = Rank::two;
    }else{
        r = Rank(int(r)+1);    
    }
    return r;
}