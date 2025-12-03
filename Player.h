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
Player()  {

name = "";
advisor = "";
pathType = "";
position = 0;
discoveryPoints = 20000;
accuracy = 0;
efficiency = 0;
insight = 0;

}
//Regin Help me with the getters and setters bro lmao
void setName(std::string n) {name=n;}
void setAdvisor(std::string a) {advisor=a;}

void setCharacter(Scientist s) {
    
    character =s;
    accuracy = s.accuracy;
    efficiency = s.efficiency;
    insight = s.insight;
    discoveryPoints = s.discoveryPoints;
// allows player to get stats of scientist that is picked automatically
}
void setPathType (std::string p) {pathType =p;}

void setPosition (int pos) {position = pos;}
void setDiscoveryPoints (int d) {discoveryPoints=d;}
void setAccuracy (int Acc) {accuracy = Acc;}
void setEfficiency (int e) {efficiency=e;}
void setInsight (int Ins)  {insight=Ins;}
//above are all the setters for the different categories

std::string getName() {return name;}
std::string getAdvisor()  {return advisor;}
Scientist getCharacter() {return character;}
std::string getPathType() {return pathType;}
int getPosition()  {return position;}
int getDiscoveryPoints() {return discoveryPoints;}
int getAccuracy()  {return accuracy;}
int getEfficiency() {return efficiency;}
int getInsight() {return insight;}
//above are all the getters for the different categories


};