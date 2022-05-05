#include "blackjack.h"

using namespace std;
int main(){
	CardDeck deck; // creates object of cardDeck class
	int dealtCard;
	deck.createDeck(); //creates deck
	deck.shuffleDeck();
	deck.printDeck();
	
	vector<int> player1;
	vector<int> dealer;
	
	//gives player their initial hand
	for (int i = 0; i < 2; ++i){
	dealtCard = deck.passOut(); // gets card from top of deck
	deck.displayCard(dealtCard);
	player1.push_back(dealtCard); // gives it to player 1
	}
	
	for (int i = 0; i < 2; ++i){
	dealtCard = deck.passOut(); // gets card from top of deck
	deck.displayCard(dealtCard);
	dealer.push_back(dealtCard); // gives it to dealer
	}
	
	return 0;
}