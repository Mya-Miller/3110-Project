#include <iostream>
#include "CardDeck.h"

using namespace std;

int main(){
  CardDeck deck; // creates object of cardDeck class
  int winning_number; //holds the number the player want to get to
  int bet; //holds the amount the user wants to bet
  bool end_game = false, bust = false;
  int choice;

  cout << "Enter in the number you would like to reach? ";
  cin >> winning_number;

  cout << "How much money would you like to bet? ";
  cin >> bet;

  deck.createDeck(); //creates deck
  deck.shuffleDeck(); //shuffles deck

  do{
    //Menu
    cout << "1. Hit\n";
    cout << "2. Stand\n";
    cout << "3. Display your hand\n";
    cout << "4. End Game\n";
    
    cout << "Enter in a choice";
    cin >> choice;

    int dealtCard; //holds the card the user receives from dealer;
    
    switch(choice){
      case 1:
        dealtCard = deck.passOut();
        //prints card value the user recived
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
        //value needs to be sent to where ever the users card is being held
        //check if their is a bust
        //if bust player loses and game ends
        //check if players hand == winning_number if so player wins game ends
        break;
      case 2:
        cout << "Turn skipped...\n";
        break;
      case 3:
        cout << "Display players hand here...\n";
        break;
      case 4:
        cout << "Game terminating...\n";
        end_game = true;
        break;  
    }
    
  }while(end_game && bust);

	return 0;
}
