#include "blackjack.h"

using namespace std;
int main(){
	CardDeck deck; // creates object of cardDeck class
	int dealtCard;
	deck.createDeck(); //creates deck
	deck.shuffleDeck();
	deck.printDeck();
	for (int i = 0; i < 5; ++i){
	dealtCard = deck.passOut();
	if (dealtCard == 1){
			cout << "Dealt Card value is: A" << endl;
		}
		else if (dealtCard == 11){
			cout << "Dealt Card value is: J" << endl;
		}
		else if (dealtCard == 12){
			cout << "Dealt Card value is: Q" << endl;
		}
		else if (dealtCard == 13){
			cout << "Dealt Card value is: K" << endl;
		}
		else{
			cout << "Dealt Card value is: " << dealtCard << endl;
		}
	}
	return 0;
}