#include <iostream>
#include <vector>
#include <iterator>
#include <list>

#include "CardDeck.h"
#include "HardHand.h"
#include "BettingSystem.h"

using namespace std;

int main(){
  CardDeck deck; // creates object of cardDeck class
  HardHand h_hand;
  bettingSystem bet_sys;

  //linked list that holds the players cards and dealers cards
  list<int> players_hand;
  list<int> dealers_hand;
  
  int bust_value; //holds the number the player want to get to
  int bet; //holds the amount the user wants to bet
  bool end_game = false, bust = false;
  int choice;

  cout << "Enter in the number you would like to reach? ";
  cin >> bust_value;
  h_hand.setBustValue(bust_value);

  cout << "How much money would you like to bet? $";
  cin >> bet;
  bet_sys.setBetAmount(bet);

  deck.createDeck(); //creates deck
  deck.shuffleDeck(); //shuffles deck
  
  cout << endl;
  
  do{
    //Menu
    cout << "1. Hit\n";
    cout << "2. Stand\n";
    cout << "3. Display your hand\n";
    cout << "4. End Game\n";
    
    cout << "\nEnter in a choice ";
    cin >> choice;

    int dealt_card; //holds the card the user receives from dealer;
    
    switch(choice){
      case 1:
        //gets users card
        dealt_card = deck.passOut();
        
        //prints card value the user recived
        deck.displayCard(dealt_card);

        //add card to players hand
        players_hand.push_back(dealt_card);
        
        //check if their is a bust
        //if bust player loses and game ends
        //check if players hand == winning_number if so player wins and see if they want to 
        break;
      case 2:
        cout << "Turn skipped...\n";
        break;
      case 3:
        int x;
        for (auto it = players_hand.begin(); it != players_hand.end(); ++it){
          x = *it;
          deck.displayHand(x);
        }
        cout << endl;
        break;
      case 4:
        cout << "Game terminating...\n";
        end_game = true;
        break;  
    }

    cout << endl;
  }while(end_game != true && bust != true); 

	return 0;
}
