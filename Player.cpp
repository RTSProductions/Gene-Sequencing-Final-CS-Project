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
void Player::setCharacter(Scientist character)
{
    this->character = character;
}
void Player::setName(std::string name)
{
    this->name = name;
}