#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <string>
#include <vector>


struct Scientist 
{

    std::string name;
    int experience;
    int accuracy;
    int efficiency;
    int insight;
    int discoveryPoints;

    bool taken;
};

// Function to read scientists from text
std::vector<Scientist> loadScientists(const std::string &filename); 

#endif