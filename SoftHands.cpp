#include "SoftHands.h"
using namespace std;

//adds up cards
void softHand::checkCard(int dealtCard){
  int num;
	if (dealtCard == 1){
    cout << endl << "Would you like ace to be 1 or 11: ";
    cin >> num;
    total += num;
	}
	else if (dealtCard == 11){
    total += 10;
	}
	else if (dealtCard == 12){
    total += 10;
	}
	else if (dealtCard == 13){
    total += 10;
	}
	else{
    total += dealtCard;
	}
}

int softHand::getTotal()
{
  return total;
}
