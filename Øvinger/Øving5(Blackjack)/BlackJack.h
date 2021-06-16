#include "CardDeck.h"

class BlackJack{
    private:
        vector<Card> playerCards;
        vector<Card> dealerCards;
        CardDeck deck;
    public:
        BlackJack();
        void printToShort(int status);
        void printDealerHand();
        vector<Card> getPlayerCards();
        vector<Card> getDealerCards();
        int addDealer();                //Dealer trekker alle kort med én gang, holder på til han må stå på 17, eller er over 21 og har tapt.
        int checkStatus(int valueDealer);          //1==vunnet, 0= forts. -1 == tapt
        void play();
};

bool checkRealBlackJack(vector<Card> cards);   //True = realBlackJack
vector<int> getValues(vector<Card> cards);