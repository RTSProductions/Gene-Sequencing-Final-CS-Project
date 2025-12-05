#include "Player.h"
#include <string>

// Getters
Scientist Player::getCharacter() const
{
    return character;
}

std::string Player::getName() const
{
    return name;
}

// Setters
void Player::setCharacter(Scientist chara)
{
    character = chara;
}
void Player::setName(std::string n)
{
    name = n;
}