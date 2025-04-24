#include "Player.h"

using namespace std;

// Constructor: Initializes a Player object with given attributes and class type
Player::Player(string name, int health, int attack, int defense, vector<Abilities> abilities, ClassType type)
    : Creature(name, health, attack, defense, abilities), type(type) {}

// Returns the player's class type
ClassType Player::getClassType() const {
    return type;
}