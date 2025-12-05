#include <iostream>
#include "Scientist.h"
#include "Player.h"
#include "Board.h"
#include "Tile.h"
#include "TileEffects.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <random>


using namespace std;

vector<Scientist> scientists;

std::vector<Tile> fellowshipPath(52);
std::vector<Tile> directPath(52);

void clearConsole() 
{
    cout << "\033[2J\033[1;1H";
}

int main() 
{

    srand(static_cast<unsigned int>(time(0)));
    // Initialize the scientists 
    scientists = loadScientists("data/characters.txt");

    // set up the board and players
    Board board;
    Player p1, p2;

    //cool design to make it fun to introduce game
    cout << "============================\n";
    cout << "  WELCOME TO GENE RACE!\n";
    cout << "============================\n\n";
    //choose the scientist (Player 1)

    cout << "Player 1, please enter a name\nName: ";

    // Player 1 name
    string p1Name;
    cin >> p1Name;
    p1.setName(p1Name);

    cout << "Welcome " << p1.getName() << "!\n";
//make sure to always reference to player 1 as their chosen name
    cout << p1.getName() << ", please choose your Scientist:\n\n" << endl;



    for (int i = 0; i < 5; i++)
    {
        cout<< i + 1 << ". " << scientists[i].name
            <<" Experience: " << scientists[i].experience
            <<" Accuracy: " << scientists[i].accuracy
            <<" Efficiency:" << scientists[i].efficiency
            <<" Insight:" << scientists[i].insight
            <<"\n";
        //this basically will show the scientists and their stats through a for loop cycle

    }

    int choice;
    //Now we can only have one scientist so make while loop for errors or repeats
    // Player 1
    while (true) 
    {
        cout << "Enter choice (1-5): ";
        cin.clear(); // Clearing the buffer to prevent infinite looping of invalid character
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> choice;


        //basics is complete now this if is for errors mostly and when correct choice is made
        if (choice >= 1 && choice <= 5) //has to be avaible #
        {
            if(!scientists[choice -1].taken)
            {
                scientists[choice -1].taken = true;
                p1.setCharacter(scientists[choice - 1]);
                cout << p1.getName() << " has selected: "<< p1.getCharacter().name <<"\nGreat choice!\n\n";
                break;
            } 
            else 
            {
                cout <<"Sorry, that scientist is already taken.\n";
            } 
        } 
        else 
        {

            cout << "Sorry that choice is invalid, please try again.\n";
        }
    }

    // Deal with player 2

    cout << "Player 2, please enter a name\nName: ";

    // Player 2 name
    string p2Name;
    cin >> p2Name;
    p2.setName(p2Name);

    cout << "Welcome " << p2.getName() << "!\n";

    cout << p2.getName() << ", please choose your Scientist:\n\n" << endl;

    for (int i = 0; i < 5; i++)
    {
        if (scientists[i].taken == false)
        {
            cout<< i + 1 << ". " << scientists[i].name
                <<" Experience: " << scientists[i].experience
                <<" Accuracy: " << scientists[i].accuracy
                <<" Efficiency:" << scientists[i].efficiency
                <<" Insight:" << scientists[i].insight
                <<"\n";
        }

    }
    choice = 0;

    //Player 2 loop
    while (true) 
    {
        cout << "Enter choice (1-5): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> choice;

        if (choice >= 1 && choice <= 5)
        {
            if(!scientists[choice -1].taken)
            {
                scientists[choice -1].taken = true;
                p2.setCharacter(scientists[choice - 1]);
                cout << p2.getName() << " has selected: "<< p2.getCharacter().name <<"\nGreat choice!\n\n";
                break;
            } 
            else 
            {
                cout <<"Sorry, that scientist is already taken.\n";
            } 
        } 
        else 
        {

            cout << "Sorry that choice is invalid, please try again.\n";
        }
    }



    //Path Selection
    cout << p1.getName() << ", please chooose a path\n";

    int path = 0;

    while (true)
    {
        cout << "Enter choice (1-2): ";
        cin.clear(); // Clearing the buffer to prevent infinite looping of invalid character
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> path;

        if (path >= 1 && path <= 2)
        {
            p1.setPathType(path);
            cout << "You begin to wonder down the path...\n";
            break;
        } 
        else 
        {
            cout << "Please choose a real path.\n";
        }
    }

    cout << p2.getName() << ", please chooose a path\n";

    path = 0;

    while (true)
    {
        cout << "Enter choice (1-2): ";
        cin.clear(); // Clearing the buffer to prevent infinite looping of invalid character
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> path;

        if (path >= 1 && path <= 2)
        {
            p2.setPathType(path);
            cout << "You decend down the path...\n";
            break;
        } 
        else 
        {
            cout << "Please choose a real path.\n";
        }
    }

    // ========================== Rest of th Game ==================================

    // // Set the start and end tile types
    Board gameBoard;
   bool bothPlayersFinished = false;
    while (!bothPlayersFinished)
    {
        clearConsole();
        gameBoard.displayBoard();

        // Move players
        bool p1Finished = gameBoard.movePlayer(0);
        bool p2Finished = gameBoard.movePlayer(1);

        // Handle tiles for player 1
        char tileColor1 = gameBoard.getTileColor(0, gameBoard.getPlayerPosition(0));
        switch(tileColor1)
        {
            case 'G': handleGreenTile(p1); break;
            case 'B': handleBlueTile(p1); break;
            case 'P': handlePinkTile(p1); break;
            case 'T': handleBrownTile(p1); break;
            case 'R': handleRedTile(p1); break;
            case 'U': handlePurpleTile(p1); break; // fix: pass player reference
        }

        // Handle tiles for player 2
        char tileColor2 = gameBoard.getTileColor(1, gameBoard.getPlayerPosition(1));
        switch(tileColor2)
        {
            case 'G': handleGreenTile(p2); break;
            case 'B': handleBlueTile(p2); break;
            case 'P': handlePinkTile(p2); break;
            case 'T': handleBrownTile(p2); break;
            case 'R': handleRedTile(p2); break;
            case 'U': handlePurpleTile(p2); break; // fix: pass player reference
        }

        bothPlayersFinished = p1Finished && p2Finished;
    }

    //  Winner Announcement
    cout << "\n============================\n";
    cout << "        GAME OVER!\n";
    cout << "============================\n";

    if (p1.getDiscoveryPoints() > p2.getDiscoveryPoints())
    {
        cout << " Congratulations " << p1.getName() << "! You are the ultimate Gene Race champion! \n";
    }
    else if (p2.getDiscoveryPoints() > p1.getDiscoveryPoints())
    {
        cout << " Congratulations " << p2.getName() << "! You are the ultimate Gene Race champion! \n";
    }
    else
    {
        cout << " It's a tie! Both players are equally brilliant! \n";
    }

    return 0;
}