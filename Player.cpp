#include "Player.h"

using namespace std;

Player::Player(string name, int health, int maxHealth, int attack, int defense, vector<Abilities> abilities, ClassType type)    //Constructor
    : Creature(name, health, maxHealth, attack, defense, abilities), type(type) {}                                              //Members intializer list

// Returns the player's class type
ClassType Player::getClassType() const {
    return type;
}

void Player::healPlayer(int amount) {
    heal(amount); 
    std::cout << getName() << " is restored after a long night's rest...\n";
}