#pragma once

class HardHand {
private:
	int firstHalf; //Total Value first half
	int secondHalf; //Total Value second half
  int bustValue; 
public:
  void setBustValue(int);
  int getBustValue();
	bool isBusted(); //Check if both variables above bust or not
	bool isBustValue(); // if either the variables add up to 21
	void showBothValues(); //Inform User total values of both
};
