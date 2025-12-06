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

#include <chrono> // included for sleep function
#include <thread> // included for sleep function


using namespace std;

void clearConsole() 
{
    cout << "\033[2J\033[1;1H";
}

int main() 
{

    vector<Scientist> scientists;
    srand(static_cast<unsigned int>(time(0)));
    // Initialize the scientists 
    scientists = loadScientists("data/characters.txt");

    // set up the players
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

    // Apply path bonuses
    if (p1.getPathType() == 1) {
        // Fellowship Path
        p1.setDiscoveryPoints(p1.getDiscoveryPoints() - 5000);
        p1.setAccuracy(p1.getAccuracy() + 500);
        p1.setEfficiency(p1.getEfficiency() + 500);
        p1.setInsight(p1.getInsight() + 1000);

        cout << "\nYou chose Path 1 — The Fellowship Path!\n";
        cout << "-5000 DP, +500 Accuracy, +500 Efficiency, +1000 Insight.\n\n";
    }
    else {
        // Direct Path
        p1.setDiscoveryPoints(p1.getDiscoveryPoints() + 5000);
        p1.setAccuracy(p1.getAccuracy() + 200);
        p1.setEfficiency(p1.getEfficiency() + 200);
        p1.setInsight(p1.getInsight() + 200);

        cout << "\nYou chose Path 2 — The Direct Path!\n";
        cout << "+5000 DP, +200 to all traits.\n\n";
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

    // Apply path bonuses
    if (p2.getPathType() == 1) {
        // Fellowship Path
        p2.setDiscoveryPoints(p2.getDiscoveryPoints() - 5000);
        p2.setAccuracy(p2.getAccuracy() + 500);
        p2.setEfficiency(p2.getEfficiency() + 500);
        p2.setInsight(p2.getInsight() + 1000);

        cout << "\nYou chose Path 1 — The Fellowship Path!\n";
        cout << "-5000 DP, +500 Accuracy, +500 Efficiency, +1000 Insight.\n\n";
    }
    else {
        // Direct Path
        p2.setDiscoveryPoints(p2.getDiscoveryPoints() + 5000);
        p2.setAccuracy(p2.getAccuracy() + 200);
        p2.setEfficiency(p2.getEfficiency() + 200);
        p2.setInsight(p1.getInsight() + 200);

        cout << "\nYou chose Path 2 — The Direct Path!\n";
        cout << "+5000 DP, +200 to all traits.\n\n";
    }

    cout << "Path choice influences event eligibility and late-game bonuses, not board layout\n";

    // ========================== Rest of th Game ==================================

    vector<Event> events = loadEvents("data/random_events.txt");
    vector<Riddle> riddles = loadRiddlesWithAnswers("data/riddles.txt");


    // Seed RNG
    srand((unsigned int)time(0));
    Board gameBoard;
    bool bothPlayersFinished = false;
    while (!bothPlayersFinished)
    {
        clearConsole();
        gameBoard.displayBoard();

        // Player 1 turn
        cout << "\n--- " << p1.getName() << "'s turn ---\n";
        cout << "Press ENTER to spin the spinner...";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();


        // Spinner
        int roll1 = rand() % 6 + 1;
        cout << p1.getName() << " rolled a " << roll1 << "!\n";

        for (int i = 0; i < roll1; i++)
        {
            if (gameBoard.movePlayer(0))
            {
                break;
            }
        }
        

        // Handle tiles for player 1
        int pos1 = gameBoard.getPlayerPosition(0);
        char tileColor1 = gameBoard.getTileColor(0, pos1);
        switch(tileColor1)
        {
            case 'G': p1 = handleGreenTile(p1, events); break;
            case 'B': p1 = handleBlueTile(p1); break;
            case 'P': p1 = handlePinkTile(p1); break;
            case 'T': p1 = handleBrownTile(p1); break;
            case 'R': p1 = handleRedTile(p1); break;
            case 'U': p1 = handlePurpleTile(p1, riddles); break; 
            default: break;
        }

        this_thread::sleep_for(chrono::milliseconds(700));

        // Player 2 turn
        clearConsole();
        gameBoard.displayBoard();

        cout << "\n--- " << p2.getName() << "'s turn ---\n";
        cout << "Press ENTER to spin the spinner...";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        int roll2 = rand() % 6 + 1;
        cout << p2.getName() << " rolled a " << roll2 << "!\n";

        for (int i = 0; i < roll2; i++)
        {
            if (gameBoard.movePlayer(1))
            {
                break;
            }
        }

        // Handle tiles for player 2
        int pos2 = gameBoard.getPlayerPosition(1);
        char tileColor2 = gameBoard.getTileColor(1, pos2);
        switch(tileColor2)
        {
            case 'G': p2 = handleGreenTile(p2, events); break;
            case 'B': p2 = handleBlueTile(p2); break;
            case 'P': p2 = handlePinkTile(p2); break;
            case 'T': p2 = handleBrownTile(p2); break;
            case 'R': p2 = handleRedTile(p2); break;
            case 'U': p2 = handlePurpleTile(p2, riddles); break; 
        }

        this_thread::sleep_for(chrono::milliseconds(800));

        bool p1Finished = (gameBoard.getPlayerPosition(0) == 51);
        bool p2Finished = (gameBoard.getPlayerPosition(1) == 51);
        bothPlayersFinished = p1Finished && p2Finished;

        // Print interim DP totals
        cout << "\n--- Scores ---\n";
        cout << p1.getName() << ": " << p1.getDiscoveryPoints() << " DP\n";
        cout << p2.getName() << ": " << p2.getDiscoveryPoints() << " DP\n";

        // small delay so they can see the score
        this_thread::sleep_for(chrono::milliseconds(1000));
    }

    // Final scoring: convert traits -> DP as required
    auto finalize = [](Player pl) {
        int acc = pl.getCharacter().accuracy;
        int eff = pl.getCharacter().efficiency;
        int ins = pl.getCharacter().insight;
        int add = ((acc / 100) + (eff / 100) + (ins / 100)) * 1000;
        pl.setDiscoveryPoints(pl.getDiscoveryPoints() + add);
        return pl;
    };

    p1 = finalize(p1);
    p2 = finalize(p2);


    //  Winner Announcement
    cout << "\n============================ GAME OVER ==========================\n";
    cout << p1.getName() << " final DP: " << p1.getDiscoveryPoints() << "\n";
    cout << p2.getName() << " final DP: " << p2.getDiscoveryPoints() << "\n";

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