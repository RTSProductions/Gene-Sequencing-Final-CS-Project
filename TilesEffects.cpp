#include "TileEffects.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;
//random DNA sequence
string generateRandomDNA(int length) {
    string dna = "";
    string bases = "ATCG";
    for (int i = 0; i < length; i++) {
        int index = rand() % 4; // 0-3
        dna += bases[index];
    }
    return dna;
}
//Equal length similarity
int bestStrandMatch(string input_strand, string target_strand) {
    int bestIndex = 0;
    double bestScore = -1;
    for (int i = 0; i <= input_strand.length() - target_strand.length(); i++) {
        string sub = input_strand.substr(i, target_strand.length());
        double score = strandSimilarity(sub, target_strand);
        if (score > bestScore) {
            bestScore = score;
            bestIndex = i;
        }
    }
    return bestIndex;
}

//Mutation ID

void identifyMutations(string input_strand, string target_strand) {
    int start = bestStrandMatch(input_strand, target_strand);
    cout << "Mutations detected (position: type):\n";

    int i = 0, j = start;
    while (i < target_strand.length() || j < input_strand.length()) {
        if (i >= target_strand.length()) {
            // Extra bases in input -> deletion in target
            cout << j << ": deletion of " << input_strand[j] << endl;
            j++;
        } 
        else if (j >= input_strand.length()) {
            // Extra bases in target -> insertion
            cout << i << ": insertion of " << target_strand[i] << endl;
            i++;
        }
        else if (input_strand[j] != target_strand[i]) {
            // Bases differ -> substitution
            cout << i << ": substitution " << input_strand[j] << " -> " << target_strand[i] << endl;
            i++; j++;
        }
        else {
            // Bases match -> no mutation
            i++; j++;
        }
    }
}

//transcribe DNA to RNA

void transcribeDNAtoRNA(string strand) {
    string rna = "";
    for (int i = 0; i < strand.length(); i++) {
        if (strand[i] == 'T') rna += 'U';
        else rna += strand[i];
    }
    cout << "DNA: " << strand << "\nRNA: " << rna << endl;
}

//ALL THE ACTUAL TILES BELOW
// before looking more into tiles i already put green tiles in main.cpp, im probably just going to keep it there

//Blue Tiles(Equal Length Comparision)
void handleBlueTile(Player &p) {
    cout << "\n Hey! A Blue Tile, Compare DNA sequences (equal length)\n";
    string dna1 = generateRandomDNA(10);
    string dna2 = generateRandomDNA(10);
    cout << "DNA 1: " << dna1 << "\nDNA 2: " << dna2 << endl;
    double score = strandSimilarity(dna1, dna2);
    cout << "Similarity score: " << score << endl;
    p.setDiscoveryPoints(p.getDiscoveryPoints() + int(score * 100)); // reward proportional to similarity
}

//Pink Tiles (Unequal Length Comparision)

void handlePinkTile(Player &p) {
    cout << "\n Hey! A Pink Tile, Compare DNA sequences (unequal length)\n";
    string dna1 = generateRandomDNA(12);
    string dna2 = generateRandomDNA(8);
    int bestIndex = bestStrandMatch(dna1, dna2);
    cout << "DNA1: " << dna1 << "\nDNA2: " << dna2 << "\nBest alignment starts at index " << bestIndex << endl;
    p.setDiscoveryPoints(p.getDiscoveryPoints() + 100); // reward flat points
}


//Red Tiles (mutation)

void handleRedTile(Player &p) {
    cout << "\n Hey! A Red Tile, Identify mutations\n";
    string dna1 = generateRandomDNA(10);
    string dna2 = generateRandomDNA(10);
    cout << "DNA 1: " << dna1 << "\nDNA 2: " << dna2 << endl;
    identifyMutations(dna1, dna2);
    p.setDiscoveryPoints(p.getDiscoveryPoints() + 150);
}

//Brown Tiles (DNA to RNA)
void handleBrownTile(Player &p) {
    cout << "Hey! A Brown Tile, Transcribe DNA to RNA\n";
    string dna = generateRandomDNA(10);
    transcribeDNAtoRNA(dna);
    p.setDiscoveryPoints(p.getDiscoveryPoints() + 120);
}

// Purple tile (riddles)

string riddles[10] = {
    "I speak without a mouth and hear without ears. What am I?",
    "The more of me you take, the more you leave behind. What am I?",
    "I have cities but no houses, forests but no trees, and water but no fish. What am I?",
    "What has keys but can't open locks?",
    "What can travel around the world while staying in a corner?",
    "What has hands but cannot clap?",
    "What has to be broken before you can use it?",
    "I’m tall when I’m young, and I’m short when I’m old. What am I?",
    "What gets wetter as it dries?",
    "What has a head and a tail but no body?"
};

// Function to trigger a purple tile
void handlePurpleTile(Player &p) {
    srand(time(0));
    int r = rand() % 10;
    cout << "Purple Tile! Solve this riddle to gain 500 points:\n";
    cout << riddles[r] << endl;

    string answer;
    cout << "Your answer: ";
    cin.ignore();
    getline(cin, answer);

    cout << "Correct! You earn 500 points!\n";
    p.setDiscoveryPoints(p.getDiscoveryPoints() + 500); 
}

struct Event{
    std::string description;
    int pathType;
    std::string requiredScientist;
    int points;




};

std::vector<Event> events = {

    {"A critical DNA sample is contaminated", 1, "", -500},
    {"Your risky direct assignments pays off", 0, "", 500},
    {"A tip from Dr.Bio-Script helps your script run 50% faster", 1, "Dr. Bio-Script", 800},
    {"You discovere an overlooked, archived tissue sample from a key lion", 0, "", 600},
    {"You help a co-worker debug their sequence alingment code", 1, "", 700},

    //Just save this for me to put more random events, i still need to make it to where certain ones will only happen if you have the advisor/doctor you selected






};

void handleGreenTile(Player player) {
    //50% chance event occurs
    if (rand() % 2 == 0){

    int index = rand() % events.size(); // picking a random event
    Event e = events[index];

    //check if the player qualifies for the event
    bool scientist0k = (e.requiredScientist == "" || e.requiredScientist == player.getCharacter().name);

    if (scientist0k){

        player.setDiscoveryPoints(player.getDiscoveryPoints() + e.points);
        std::cout<< "Event has been triggered!"<<e.description
                <<"Points Change: " << e.points
                <<"Total Discovery Points:"<<player.getDiscoveryPoints() << "\n";

    }else{

        std::cout << "Nothing special happened on this tile.\n";
    }
    }else{
        std::cout << "Nothing special happened on this tile.\n";
    }
}
