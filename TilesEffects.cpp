#include "TileEffects.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <limits>
#include <thread>
#include <chrono>

using namespace std;

void clearAnswerInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
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
Player handleBlueTile(Player p) {
    cout << "\n Hey! A Blue Tile, Compare DNA sequences (equal length)\n";
    string dna1 = generateRandomDNA(10);
    string dna2 = generateRandomDNA(10);
    cout << "DNA 1: " << dna1 << "\nDNA 2: " << dna2 << endl;
    double score = strandSimilarity(dna1, dna2);
    cout << "Similarity score: " << score << endl;
    p.setDiscoveryPoints(p.getDiscoveryPoints() + int(score * 100)); // reward proportional to similarity
    return p;
}

//Pink Tiles (Unequal Length Comparision)

Player handlePinkTile(Player p) {
    cout << "\n Hey! A Pink Tile, Compare DNA sequences (unequal length)\n";
    string dna1 = generateRandomDNA(12);
    string dna2 = generateRandomDNA(8);
    int bestIndex = bestStrandMatch(dna1, dna2);
    cout << "DNA1: " << dna1 << "\nDNA2: " << dna2 << "\nBest alignment starts at index " << bestIndex << endl;
    p.setDiscoveryPoints(p.getDiscoveryPoints() + 100); // reward flat points
    return p;
}


//Red Tiles (mutation)

Player handleRedTile(Player p) {
    cout << "\n Hey! A Red Tile, Identify mutations\n";
    string dna1 = generateRandomDNA(10);
    string dna2 = generateRandomDNA(10);
    cout << "DNA 1: " << dna1 << "\nDNA 2: " << dna2 << endl;
    identifyMutations(dna1, dna2);
    p.setDiscoveryPoints(p.getDiscoveryPoints() + 150);
    return p;
}

//Brown Tiles (DNA to RNA)
Player handleBrownTile(Player p) {
    cout << "Hey! A Brown Tile, Transcribe DNA to RNA\n";
    string dna = generateRandomDNA(10);
    transcribeDNAtoRNA(dna);
    p.setDiscoveryPoints(p.getDiscoveryPoints() + 120);
    return p;
}

// Purple tile (riddles)

// Utility function to lowercase a string
string toLower(string str) {
    for (int i = 0; i < str.size(); i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}

// Remove articles "a", "an", "the" from start of string
string removeArticles(string str) {
    string lowered = toLower(str);

    if (lowered.rfind("a ", 0) == 0) 
    {
        str = str.substr(2);
    }
    else if (lowered.rfind("an ", 0) == 0) 
    {
        str = str.substr(3);
    }
    else if (lowered.rfind("the ", 0) == 0) 
    {
        str = str.substr(4);
    }

    // Trim leading spaces
    while (!str.empty() && str[0] == ' ') str = str.substr(1);

    return str;
}

// Load riddles and answers from file
vector<Riddle> loadRiddlesWithAnswers(string filename) {
    vector<Riddle> riddles;
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Warning: could not open riddles file: " << filename << endl;
        return riddles;
    }

    string line;
    while (getline(inFile, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string question, answer;
        if (getline(ss, question, '|') && getline(ss, answer, '|')) {
            Riddle r;
            r.question = question;
            r.answer = answer;
            riddles.push_back(r);
        }
    }

    return riddles;
}

// string riddles[10] = {
//     "I speak without a mouth and hear without ears. What am I?",
//     "The more of me you take, the more you leave behind. What am I?",
//     "I have cities but no houses, forests but no trees, and water but no fish. What am I?",
//     "What has keys but can't open locks?",
//     "What can travel around the world while staying in a corner?",
//     "What has hands but cannot clap?",
//     "What has to be broken before you can use it?",
//     "I’m tall when I’m young, and I’m short when I’m old. What am I?",
//     "What gets wetter as it dries?",
//     "What has a head and a tail but no body?"
// };

// Function to trigger a purple tile
Player handlePurpleTile(Player p, vector<Riddle> riddles) {
    if (riddles.size() == 0) {
        cout << "No riddles available.\n";
        return p;
    }

    // Pick a random riddle
    int idx = rand() % (int)riddles.size();
    Riddle r = riddles[idx];

    cout << "\nPurple Tile — riddle time!\n" << r.question << endl;
    cout << "Your answer: \n";

    string answer;
    clearAnswerInput();
    getline(cin, answer);

    if (answer.size() > 0) {
        // Normalize answers: lowercase and remove articles
        string correctAnswer = removeArticles(toLower(r.answer));
        string givenAnswer = removeArticles(toLower(answer));

        if (correctAnswer == givenAnswer) {
            cout << "Correct! +500 DP!\n";
            p.setDiscoveryPoints(p.getDiscoveryPoints() + 500);
        } else {
            cout << "Wrong! The correct answer was: " << r.answer << endl;
            p.setDiscoveryPoints(p.getDiscoveryPoints() - 200);
        }
    } else {
        cout << "No answer — no points.\n";
    }

    cout << p.getName() << " now has " << p.getDiscoveryPoints() << " DP\n";
    return p;
}


// std::vector<Event> events = {

//     {"A critical DNA sample is contaminated", 1, "", -500},
//     {"Your risky direct assignments pays off", 0, "", 500},
//     {"A tip from Dr.Bio-Script helps your script run 50% faster", 1, "Dr. Bio-Script", 800},
//     {"You discovere an overlooked, archived tissue sample from a key lion", 0, "", 600},
//     {"You help a co-worker debug their sequence alingment code", 1, "", 700},

//     //Just save this for me to put more random events, i still need to make it to where certain ones will only happen if you have the advisor/doctor you selected






// };

Player handleGreenTile(Player p, vector<Event> events) 
{
    if (events.size() == 0 || rand() % 2 == 0) {
        cout << "Nothing happened.\n";
        return p;
    }

    Event e = events[rand() % events.size()];
    bool qualifies = true;

    // Check scientist requirement
    if (!e.requiredScientist.empty() &&
        e.requiredScientist != p.getCharacter().name) 
    {
        qualifies = false;
    }

    // Check path requirement
    if (e.pathType != -1 &&
        e.pathType != (p.getPathType() - 1)) 
    {
        qualifies = false;
    }

    if (qualifies) {
        p.setDiscoveryPoints(p.getDiscoveryPoints() + e.points);
        cout << "Event: " << e.description << " (DP " << e.points << ")\n";
    } 
    else {
        cout << "Event occurred, but you did not qualify.\n";
    }

    return p;
}


double strandSimilarity(string strand1, string strand2) 
{
    if (strand1.length() != strand2.length()) 
    {
        return 0.0; // Unequal lengths → no similarity
    }

    int matches = 0;
    for (int i = 0; i < strand1.length(); i++) 
    {
        if (strand1[i] == strand2[i]) 
        {
            matches++;
        }
    }

    return double(matches) / strand1.length();
}


vector<Event> loadEvents(string filename) 
{
    
    vector<Event> events;
    ifstream inFile(filename);
    if (!inFile) 
    { 
        cerr << "Warning: could not open events file: " << filename << endl; 
        return events; 
    }
    
    string line;
    while (getline(inFile, line)) 
    {
        if (line.size() < 2) 
        {
            continue;
        }
        stringstream ss(line); 
        Event e; 
        string token;
        getline(ss, token, ','); 
        e.description = token;
        getline(ss, token, ','); 
        e.pathType = stoi(token);
        getline(ss, token, ','); 
        e.requiredScientist = token;
        getline(ss, token, ','); 
        e.points = stoi(token);
        events.push_back(e);
    }
    return events;
}


