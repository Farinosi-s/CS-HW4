#include "Player.h"

using namespace std;

Player::Player(string name, int health, int maxHealth, int attack, int defense, vector<Abilities> abilities, ClassType type)    //Constructor
    : Creature(name, health, maxHealth, attack, defense, abilities), type(type) {
        for (int i = 0; i < 5; ++i) {
            inventory[i][0] = i;
            inventory[i][1] = 0;
        }
    }                                              //Members intializer list

// Returns the player's class type
ClassType Player::getClassType() const {
    return type;
}

void Player::healPlayer(int amount) {
    heal(amount); 
    std::cout << getName() << " is restored after a long night's rest...\n";
}

void Player::addItem(int itemId) {
    if (itemId >= 0 && itemId < 5) {
        inventory[itemId][1] += 1;
        std::cout << "\nTrophy acquired! Item ID " << itemId << " added to inventory.\n";
    }
}
