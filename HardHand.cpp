#include "HardHand.h"
#include "CardDeck.h"

void HardHand::setBustValue(int value){
  bustValue = value;
}

int HardHand::getBustValue(){
  return bustValue;
}

void HardHand::setFirstHalf(int value){
  firstHalf.push_back(value);
}

void HardHand::setSecondHalf(int value){
  secondHalf.push_back(value);
}

vector<int> HardHand::getFirstHalf() {
  return firstHalf;
}
vector<int> HardHand::getSecondHalf() {
  return secondHalf;
}
int HardHand::FirstHalf() {
  vector<int> Hand = HardHand::getFirstHalf();
  CardDeck deck; int total = 0;
  bool end_round = false, bust = false;
  int choice; int dealt_card;
  do{
    cout << "Your first pile has: ";
    for(int i = 0; i < Hand.size(); i++) {
      cout << Hand[i];
    }
    //Menu
    cout << "\n1. Hit\n";
    cout << "2. Stand\n";
    cout << "\nEnter in a choice: ";
    cin >> choice;
    switch(choice) {
      case 1:
        //gets users card
        dealt_card = deck.passOut();
          
        //prints card value the user recived
        cout << "\nYou recieved "; 
        deck.displayCard(dealt_card);
  
        //add card to players hand
        Hand.push_back(dealt_card);
          
        //check if their is a bust
        for(int i = 0; i < Hand.size(); i++) {
          total += Hand[i];
        }
        //if bust player loses and game ends
        if(total > HardHand::getBustValue()) {
          cout << "Your first pile got busted" << endl;
        }
        //check if players hand == winning_number if so player wins and see if they want to
      else if(total == HardHand::getBustValue()) {
        end_round = true;
      }
      cout << "Total: " << total << endl;
    }
  }while(end_round != true && bust != true);
  return total;
}

int HardHand::SecondHalf() {
  vector<int> Hand = HardHand::getSecondHalf();
  CardDeck deck; int total = 0;
  bool end_round = false, bust = false;
  int choice; int dealt_card;
  do{
    cout << "Your first pile has: ";
    for(int i = 0; i < Hand.size(); i++) {
      cout << Hand[i];
    }
    //Menu
    cout << "\n1. Hit\n";
    cout << "2. Stand\n";
    cout << "\nEnter in a choice: ";
    cin >> choice;
    switch(choice) {
      case 1:
        //gets users card
        dealt_card = deck.passOut();
          
        //prints card value the user recived
        cout << "\nYou recieved "; 
        deck.displayCard(dealt_card);
  
        //add card to players hand
        Hand.push_back(dealt_card);
          
        //check if their is a bust
        for(int i = 0; i < Hand.size(); i++) {
          total += Hand[i];
        }
        //if bust player loses and game ends
        if(total > HardHand::getBustValue()) {
          cout << "Your first pile got busted" << endl;
        }
        //check if players hand == winning_number if so player wins and see if they want to
      else if(total == HardHand::getBustValue()) {
        end_round = true;
      }
      cout << "Total: " << total << endl;
    }
  }while(end_round != true && bust != true);
  return total;
}
