#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Scientist.h"

class Player
{
    private:
        std::string name;
        std::string advisor; //Can make a no advisor option for the other path chosen
        Scientist character; // most info already in scientist class
        std::string pathType;
        int position;
        int discoveryPoints;
        int accuracy;
        int efficiency;
        int insight;

    public:

        //just a default constuctor
        Player()  
        {
            name = "";
            advisor = "";
            pathType = "";
            position = 0;
            discoveryPoints = 20000;
            accuracy = 0;
            efficiency = 0;
            insight = 0;
        }

        // Getters
        Scientist getCharacter() const;
        std::string getName() const;

        // Setters
        void setCharacter(Scientist character);
        void setName(std::string name);


};

#endif