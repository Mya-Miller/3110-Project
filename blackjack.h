#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>


using namespace std;
class CardDeck{
	private:
	int cards[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
	vector<int> deck = vector<int>(52);

	public:
	void createDeck();
	void shuffleDeck();
	int passOut();
	void displayCard(int);
	void printDeck();
};