#include "blackjack.h"

using namespace std;

void CardDeck::createDeck(){
	int i;
	int j;
	// puts card values in deck
	for (i = 0; i < 4 ; ++i){
		for (j = 0; j < 13; ++j){
			deck[j + (i*13)] = cards[j];
		}
	}
	
}
	
void CardDeck::shuffleDeck(){
	srand(time(NULL)); // seeds random generator
	random_shuffle(deck.begin(), deck.end()); // shuffles deck
}
	
int CardDeck::passOut(){
	int value = deck.back(); // gets value at end of vector
	deck.pop_back(); // removes last value from stack
	return value;
}

void CardDeck::displayCard(int dealtCard){
	if (dealtCard == 1){
		cout << "You received A" << endl;
	}
	else if (dealtCard == 11){
		cout << "You received J" << endl;
	}
	else if (dealtCard == 12){
		cout << "You received Q" << endl;
	}
	else if (dealtCard == 13){
		cout << "You received K" << endl;
	}
	else{
		cout << "You received " << dealtCard << endl;
	}
}
	
void CardDeck::printDeck(){
	for (int i = 0; i < 52; ++i){
		if (deck[i] == 1){
			cout << "Card #" << i + 1 << ": A" << endl;
		}
		else if (deck[i] == 11){
			cout << "Card #" << i + 1 << ": J" << endl;
		}
		else if (deck[i] == 12){
			cout << "Card #" << i + 1 << ": Q" << endl;
		}
		else if (deck[i] == 13){
			cout << "Card #" << i + 1 << ": K" << endl;
		}
		else{
			cout << "Card #" << i + 1 << ": " << deck[i] << endl;
		}
	}
}