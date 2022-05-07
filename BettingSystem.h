#pragma once

class bettingSystem{
private:
  int betAmount; 
  
public:
  void setBetAmount(int);
  int getBetAmount();
  void addToBet(int);
  void subtractFromBet(int);
  void printFinalAmount();
};
