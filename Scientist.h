#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <string>


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

extern Scientist scientists[5];

#endif;