#include "BlackJack.h"



int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	
	cout << "Task 1:" << endl;
	//cout << suitToString(Suit::spades) << endl;
	//cout << rankToString(Rank::king) << endl;

	cout << "Task 2:" << endl;
	//Card card1{Suit::spades, Rank::two};
	//Card card2{Suit::diamons, Rank::queen};
	//cout << card1.toString() << endl;
	//cout << card2.toStringShort() << endl;
	
	cout << "Task 3:" << endl;
	//CardDeck deck{{{Suit::spades, Rank::two},{Suit::diamons, Rank::queen}}};  //Tester input constructor
	//deck.print();
	//deck.swap(0,1);		 
	//CardDeck deck_2;     //Tester default constructor
	//deck_2.shuffle();
	//deck_2.printShort();
	//Card card3 = deck_2.drawCard();
	//cout << card3.toString() << endl;
	//deck_2.printShort();

	cout << "Task 4:" << endl;
	BlackJack start;
	start.play();
	keep_window_open();
}


