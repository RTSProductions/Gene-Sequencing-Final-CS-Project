// TileEffects.h
#ifndef TILE_EFFECTS_H
#define TILE_EFFECTS_H

#include "Player.h"
#include <string>
#include <vector>

using namespace std;

struct Event 
{
    string description;
    int pathType;
    string requiredScientist;
    int points;
};

struct Riddle 
{
    string question;
    string answer;
};

// Tile handlers: take Player by value, return Player by value
Player handleBlueTile(Player p);
Player handlePinkTile(Player p);
Player handleRedTile(Player p);
Player handleBrownTile(Player p);
Player handlePurpleTile(Player p, vector<Riddle> riddles);
Player handleGreenTile(Player p, vector<Event> events);

// Loaders
vector<Event> loadEvents(string filename);
vector<Riddle> loadRiddlesWithAnswers(string filename);

// Helper functions for DNA tasks
string generateRandomDNA(int length);
double strandSimilarity(string strand1, string strand2);
int bestStrandMatch(string input_strand, string target_strand);
void identifyMutations(string input_strand, string target_strand);
void transcribeDNAtoRNA(string strand);

#endif