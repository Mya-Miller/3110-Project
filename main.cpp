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

  //linked list that holds the player's cards and dealers cards
  list<int> players_hand;
  list<int> dealers_hand;
  vector<int> Totals; //For both piles
  
  int bust_value; //holds the number the player want to get to
  int bet; //holds the amount the user wants to bet
  bool end_round = false, bust = false;
  int choice;

  cout << "Enter in the number you would like to reach? ";
  cin >> bust_value;
  h_hand.setBustValue(bust_value);

  cout << "How much money would you like to bet? $";
  cin >> bet;
  bet_sys.setBetAmount(bet);

  deck.createDeck(); //creates deck
  
  
  cout << endl;
  while(true) { //runs forever unless user wants to end the game 
    deck.shuffleDeck(); //shuffles deck
    
    //player gets two cards initially beginning of each round
    players_hand.push_back(deck.passOut());
    players_hand.push_back(deck.passOut());

    //Dealer gets two cards intially, but one card to only 
    int dealer_card = deck.passOut();
    dealers_hand.push_back(dealer_card);
    cout << "Dealer hand:\n";
    deck.displayCard(dealer_card);
    dealers_hand.push_back(deck.passOut());
    cout << "? "; //second card is NOT displayed
  
    do{
      //Displays User Cards
      int x;
      cout << "\nYour hand:\n"; 
      for (auto it = players_hand.begin(); it != players_hand.end(); ++it){
        x = *it;
        deck.displayCard(x);
      }
      cout << endl;
      
      //Menu
      cout << "\n1. Hit\n";
      cout << "2. Stand\n";
      cout << "3. Split Hard Hand\n";
      cout << "4. End Game\n";
      
      cout << "\nEnter in a choice: ";
      cin >> choice;
  
      int dealt_card; //holds the card the user receives from dealer;
      
      switch(choice){
        case 1:
          //gets users card
          dealt_card = deck.passOut();
          
          //prints card value the user recived
          cout << "\nYou recieved "; 
          deck.displayCard(dealt_card);
  
          //add card to players hand
          players_hand.push_back(dealt_card);
          
          //check if their is a bust
          //if bust player loses and game ends
          //check if players hand == winning_number if so player wins and see if they want to 
          break;
        case 2:
          cout << "Turn stand\n";
          end_round = true;
          break;
        case 3:
          //Hard Hand choice to split
          if(players_hand.size() != 2)  { //if player does not have two cards
            cout << "You need 2 cards to split" << endl;
            }
          else {
            auto i = players_hand.begin();
            auto j = players_hand.end();
            advance(i, 0); //gets second element 
            advance(j, 0); //gets the first element
            if(*i != *j) { //if values are not the same
              cout << "They are not the same value" << endl;
            }
            else {
              h_hand.setFirstHalf(*j);
              h_hand.setSecondHalf(*i);
              Totals[0] = h_hand.FirstHalf();
              Totals[1] = h_hand.SecondHalf();
            }
          }
          break;
        case 4:
          cout << "Game terminating...\n";
          return 0; //terminates the program
          break;  
      }
    
      //dealer getting card
      dealer_card = deck.passOut();
      dealers_hand.push_back(dealer_card);
      cout << "\nDealer recieved ";
      deck.displayCard(dealer_card);
      cout << endl;
      
    }while(end_round != true && bust != true); 
    //Dealer gets cards
    //If dealer bust, user wins and they get double their bet, otherwise
    //check the values of both player's and dealer's cards
    //If player wins, player gets double of the betted amount 
  }
	return 0;
}
