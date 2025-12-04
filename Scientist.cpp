#include "Scientist.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

std::vector<Scientist> loadScientists(const std::string& filename) 
{
    std::vector<Scientist> scientists;
    std::ifstream inFile(filename);

    if (!inFile) 
    {
        std::cerr << "Error opening file.\n";
        return scientists; // return empty vector if file fails
    }

    std::string line;
    while (std::getline(inFile, line)) 
    {
        std::stringstream ss(line);
        std::string temp;
        Scientist s;

        // Read name
        std::getline(ss, temp, ',');
        s.name = temp;

        // Read experience
        std::getline(ss, temp, ',');
        s.experience = std::stoi(temp);

        // Read accuracy
        std::getline(ss, temp, ',');
        s.accuracy = std::stoi(temp);

        // Read efficiency
        std::getline(ss, temp, ',');
        s.efficiency = std::stoi(temp);

        // Read insight
        std::getline(ss, temp, ',');
        s.insight = std::stoi(temp);

        // Read Discovery
        std::getline(ss, temp, ',');
        s.discoveryPoints = std::stoi(temp);

        scientists.push_back(s); // Add to the vector
    }

    return scientists;
}