#include <iostream>
#include "Scientist.h"
#include "Player.h"
#include "Board.h"
#include "Tile.h"

using namespace std;

extern Scientist scientists[5];

int main() {
// set up the board and players
    Board board;
    Player p1, p2;

//cool design to make it fun to introduce game
    cout << "============================\n";
    cout << "  WELCOME TO GENE RACE!\n";
    cout << "============================\n\n";
//choose the scientist (Player 1)

cout << "Player 1, please choose your Scientist:\n\n" << endl;

for (int i =0; i<5; i++){

cout<< i +1 << ". " << scientists[i].name
    <<" Experience: " << scientists[i].experience
    <<" Accuracy: " << scientists[i].accuracy
    <<" Efficiency:" << scientists[i].efficiency
    <<" Insight:" << scientists[i].insight
    <<"\n";
//this basically will show the scientists and their stats 
//through a for-loop cycle

}

int choice1;
//Now we can only have one scientist so make while loop for
//errors or repeats
while (true) {

    cout << "Enter choice (1-5):";
    cin >> choice1;

    //basics is complete now this if is for errors mostly and 
    //when correct choice is made
    if (choice1 >= 1 && choice1 <= 5) //has to be avaible #
    {
        if(!scientists[choice1 -1].taken){
            scientists[choice1 -1].taken = true;
            p1.setCharacter(scientists[choice1 - 1]);
            p1.setName("Player 1");
            break;
        } else {
            cout <<"Sorry, that scientist is already taken.\n";
        } 
    } else {

            cout << "Sorry that choice is invalid, please try again.\n";
     }
    }
     cout << "Player 1 has selected: "<< p1.getCharacter().name<<"\n Great choice!\n\n";

//I still need to make system that allows player to enter their name
//Player Two's turn is after this to put in info
        
cout << "Player 2, choose your Scientist:\n\n";

for (int i = 0; i<5; i++)
{
   cout << i + 1 << ". "<< scientists[i].name
    <<" Experience: " << scientists[i].experience
    <<" Accuracy: " << scientists[i].accuracy
    <<" Efficiency:" << scientists[i].efficiency
    <<" Insight:" << scientists[i].insight;

    if(scientists[i].taken) cout << "Sorry that Scientist was already taken\n Please Select Again.";

    cout << "\n";

}
 int choice2;
//I just copied first player code and switched it to work for player two
//Still just need to fix up the player names and make player able to input them
while (true) {

    cout << "Enter choice (1-5):";
    cin >> choice2;

    //basics is complete now this if is for errors mostly and 
    //when correct choice is made
    if (choice2 >= 1 && choice2 <= 5) //has to be avaible #
    {
        if(!scientists[choice2 -1].taken){
            scientists[choice2 -1].taken = true;
            p2.setCharacter(scientists[choice2 - 1]);
            p2.setName("Player 2");
            break;
        } else {
            cout <<"Sorry, that scientist is already taken.\n";
        } 
    } else {

            cout << "Sorry that choice is invalid, please try again.\n";
     }
    }
     cout << "Player 2 has selected: "<< p2.getCharacter().name<<"\n Great choice!\n\n";

    

//Here is where the game will actually start

cout<<"\n========== GAME START ==========\n";








