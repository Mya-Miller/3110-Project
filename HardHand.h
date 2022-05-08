#pragma once
#include <vector>

using namespace std;

class HardHand {
private:
	vector<int> firstHalf; //Total Value first half
	vector<int> secondHalf; //Total Value second half
  int bustValue; 
public:
  void setBustValue(int);
  int getBustValue();
  void setFirstHalf(int);
  void setSecondHalf(int);
  vector<int> getFirstHalf();
  vector<int> getSecondHalf();
  int FirstHalf(); //User will either hit or stand with their first pile
  int SecondHalf(); //User will either hit or stand with their second pile
	bool isBusted(); //Check if both variables above bust or not
	bool isBustValue(); // if either the variables add up to 21
	void showBothValues(); //Inform User total values of both
};
