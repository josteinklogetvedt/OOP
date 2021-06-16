#include "BlackJack.h"

BlackJack::BlackJack(){  //Lager utgangsstilling med to kort til hver, vector<Card>
    deck.shuffle();
    Card card;
    for (int i=0; i<4; ++i){
        if (i%2==0){
            card = deck.drawCard();
            playerCards.push_back(card);
        }else{
            card = deck.drawCard();
            dealerCards.push_back(card);
        }
    }
}

void BlackJack::printToShort(int status){
    cout << "Player hand: ";
    for (int i=0; i<playerCards.size();++i){
        cout << playerCards[i].toStringShort() << " ";
    }
    if ((status==1) || (status==-1)){
        cout << "\nDealer hand: ";  
        for (int i=0; i<dealerCards.size();++i){
            cout << dealerCards[i].toStringShort() << " ";
        }
    }
    cout << endl;
}
void BlackJack::printDealerHand(){
    cout << "\nDealers one card: ";
    cout << dealerCards[0].toStringShort()<< endl;
}

vector<int> getValues(vector<Card> cards){
    int count1 =0;               
    vector<int> alterSums;              //Deler opp i alternative summer avhengig av essene
    int countAces = 0;
    for (int i=0; i<cards.size();++i){
        if ((cards[i].getRank() == Rank::king) || (cards[i].getRank()== Rank::queen) || (cards[i].getRank()==Rank::jack)){
            count1 += 10;
        }else if(cards[i].getRank()==Rank::ace){
            countAces += 1;
        }else{
            count1 += static_cast<int>(cards[i].getRank());
        }
    }
    //count1 teller opp som ess=1, mens temp teller først med 1 ess som 11 så 2 ess som 11 osv. Alt legges inn i en vector<int>.
    alterSums.push_back(count1+countAces); 
    for (int i=1; i<countAces+1; ++i){
        int temp = count1 + i*11 + countAces-i;
        if (temp > 21){
            break;
        }else{
            alterSums.push_back(temp);
        }
    } 
    return alterSums;        
}

vector<Card> BlackJack::getPlayerCards(){
    return playerCards;
}
vector<Card> BlackJack::getDealerCards(){
    return dealerCards;
}

int BlackJack::addDealer(){                   //Dealer trekker alle kort med én gang, holder på til én av verdiene er mellom 17 og 21
    int dValue =0;   
    Card card;
    vector<int> values {getValues(dealerCards)};
    bool temp = true;
    while (temp){
        if(values[0] >21){                      //values[0] er nødt til å være den minste verdien
            dValue = 0;
            break;
        }
        for (int i=values.size()-1; i>=0; i-=1){      //Sjekker om noen av alternativene er "stå"-kort
            if ((values[i]<=21) && (values[i]>=17)){
                dValue = values[i];
                temp = false;
                break;
            }
        }if (temp==false){
            break;
        }else{
            card = deck.drawCard();
            dealerCards.push_back(card);
            values = getValues(dealerCards);
        }   
    }
    return dValue;       
}

bool checkRealBlackJack(vector<Card> cards){
    int aces = 0;
    int tenCards = 0;
    for (int i=0; i<cards.size(); ++i){
        if (cards[i].getRank() == Rank::ace){
            aces +=1;
        }
        else if ((cards[i].getRank() == Rank::king) || (cards[i].getRank() == Rank::queen) || (cards[i].getRank() == Rank::jack)
        || (cards[i].getRank() == Rank::ten)){
            tenCards += 1;
        }
    }
    if ((aces >= 1) && (tenCards >= 1)){
        return true;
    }
    else{
        return false;
    }
}

int BlackJack::checkStatus(int valueDealer){    
    vector<int> playerValues {getValues(playerCards)};
    int status = 0;
    if ((valueDealer==0) && (playerValues[0]<=21)){
        status = 1;
    }
    else if (checkRealBlackJack(playerCards) && !(checkRealBlackJack(dealerCards))){
        status = 1;
    }
    else if (playerValues[0] > 21){
        status = -1;
    }
    if (status == 0){
        for (int i=playerValues.size()-1; i>=0; i-=1){
            if ((playerValues[i] > valueDealer) && (playerValues[i]<=21)){
                status = 1;
                break;
            }
        }
    }
    return status;
}

void BlackJack::play(){
    cout << endl;
    cout << "Welcome to BlackJack\n 0 = stand still\n 1 = get a card" << endl << "------------"<< endl;
             
    int valueDealer = addDealer();
    printDealerHand();
    int valuePlayer;                                   
    int status = checkStatus(valueDealer);         //-1=tapt, 0=forts. 1=vunnet.
    printToShort(0);                    //Skriver ikke ut dealer hands
    int answer;
    Card card;

    while (status==0){
        cout << "Do you want to stand(0) or get a card(1)? ";
        cin >> answer;
        if (answer == 1){
            card = deck.drawCard();
            playerCards.push_back(card);
        }else{
            card = deck.drawCard();                //Trekker vekk et kort fra bunken
        }
        status = checkStatus(valueDealer);
        printToShort(0);
    }
    if (status==1){
        cout << "You won! " << endl;         //Viser frem dealerens kort på slutten
        printToShort(status);
    }else{       
        cout << "You lost! " << endl;
        printToShort(status);
    }
}