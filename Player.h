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

        //discoverypoints getters/setters
        int getDiscoveryPoints() const {return discoveryPoints;}
        void setDiscoveryPoints(int dp) { discoveryPoints = dp; }
       //AccuracyGetters/setters
        int getAccuracy() const { return accuracy; }
        void setAccuracy(int value) { accuracy = value; }

        // Efficiencygetters/setters
        int getEfficiency() const { return efficiency; }
        void setEfficiency(int value) { efficiency = value; }

        // Insightgetters/setters
        int getInsight() const { return insight; }
        void setInsight(int value) { insight = value; }

};

#endif