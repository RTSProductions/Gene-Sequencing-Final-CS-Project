#include "Player.h"
#include <string>

// Getters
Scientist Player::getCharacter()
{
    return character;
}

std::string Player::getName()
{
    return name;
}

// Setters
void Player::setCharacter(Scientist chara)
{
    character = chara;
    accuracy = chara.accuracy;
    efficiency = chara.efficiency;
    insight = chara.insight;
}
void Player::setName(std::string n)
{
    name = n;
}

void Player::setPathType(int type) 
{
    pathType = type;
}