#include "ScoreBoard.h"
#include "CardDeck.h"

using namespace std;

// This function will display the whole hand
void ScoreBoard::DisplayHand(int Hand[], const int CardCount)
{

    for (int i = 0; i < CardCount; i++) {
        const int NewCard = Hand[i];
        displayCard(NewCard);
        cout << " ";
    }
    cout << endl;
}

// This function will display hand of either player or dealer
int ScoreBoard::ScoreHand(int Hand[], const int CardCount)
{
    int AceCount = 0;
    int Score = 0;
    for (int i = 0; i < CardCount; i++) {
        const int NewCard = Hand[i];
        const int Value = (NewCard % 13);
        if (Value == 0) {
            AceCount++;
            Score++;
        }
        else if (Value < 9) {
            Score = Score + (Value + 1);
        }
        else {
            Score = Score + 10;
        }
    }
    while (AceCount > 0 && Score < 12) {
        AceCount--;
        Score = Score + 10;
    }
    return Score;
}

// This function will display the score of both dealer and player
void ScoreBoard::DisplayResult(int DealerHand[], const int DealerCardCount, int PlayerHand[], const int PlayerCardCount)
{
    cout << "Dealer Score = " << ScoreHand(DealerHand, DealerCardCount) << endl;
    DisplayHand(DealerHand, DealerCardCount);
    cout << "\nPlayer Score = " << ScoreHand(PlayerHand, PlayerCardCount) << endl;
    DisplayHand(PlayerHand, PlayerCardCount);
    cout << endl;
}

// This function will determine who is the winner
void ScoreBoard::Winner(int DealerHand[], const int DealerCardCount, int PlayerHand[], const int PlayerCardCount)
{
    int Win = 0;
    int PlayerScore = ScoreHand(PlayerHand, PlayerCardCount);
    int DealerScore = ScoreHand(DealerHand, DealerCardCount);
    DisplayHand(DealerHand, DealerCardCount);
    DisplayHand(PlayerHand, PlayerCardCount);
    if (PlayerScore < 22) && (PlayerScore > DealerScore) ||
       (DealerScore > 21) && (PlayerScore < 22)
    {
        cout << "Player Win!" << endl;
        Win++;
    }
    else if (PlayerScore == DealerScore)
    {
        cout << "Round Draw!" << endl;
    }
    else
    {
        cout << "Dealer Win!" << endl;
    }
    return Win;
}

int NumOfWins(int DealerHand[], const int DealerCardCount, int PlayerHand[], const int PlayerCardCount)
{
    Win = Winner(DealerHand, DealerCardCount, PlayerHand, PlayerCardCount);
    cout << "Number of Wins is: " << win << endl;
}





