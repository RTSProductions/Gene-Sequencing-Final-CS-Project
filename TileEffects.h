// TileEffects.h
#ifndef TILE_EFFECTS_H
#define TILE_EFFECTS_H

#include "Player.h"
#include <string>

using namespace std;

// DNA-based special tiles
void handleBlueTile(Player &p);   // DNA similarity (equal length)
void handlePinkTile(Player &p);   // DNA similarity (unequal length)
void handleRedTile(Player &p);    // Mutation identification
void handleBrownTile(Player &p);  // DNA → RNA transcription
void handlePurpleTile(Player &p); // Riddle challenge
void handleGreenTile(Player &p); //half chance at a event or nothing

// Helper functions for DNA tasks
string generateRandomDNA(int length);
double strandSimilarity(string strand1, string strand2);
int bestStrandMatch(string input_strand, string target_strand);
void identifyMutations(string input_strand, string target_strand);
void transcribeDNAtoRNA(string strand);

#endif