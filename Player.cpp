#include "Player.h"

using namespace std;

// Constructor: Initializes a Player object with given attributes and class type
Player::Player(string name, int health, int maxHealth, int attack, int defense, vector<Abilities> abilities, ClassType type)
    : Creature(name, health, maxHealth, attack, defense, abilities), type(type) {}

// Returns the player's class type
ClassType Player::getClassType() const {
    return type;
}

void Player::healPlayer(int amount) {
    heal(amount); 
    std::cout << getName() << " is restored after a long night's rest...\n";
}