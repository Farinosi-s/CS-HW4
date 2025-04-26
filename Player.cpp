#include "Player.h"

using namespace std;

Player::Player(string name, int health, int maxHealth, int attack, int defense, vector<Abilities> abilities, ClassType type)    //Constructor
    : Creature(name, health, maxHealth, attack, defense, abilities), type(type) { }                //Members intializer list



ClassType Player::getClassType() const {                    // Returns the player's class type
    return type;
}

void Player::healPlayer(int amount) {
    heal(amount); 
    std::cout << getName() << " is restored after a long night's rest...\n";
}

void Player::addItem(const string& itemName) {                                              //First part checks if item already exists
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (inventory[i][j].itemName == itemName) {
                inventory[i][j].quantity++;
                cout << "You received another " << itemName << "! Now you have x" << inventory[i][j].quantity << ".\n";
                return;
            }
        }
    }

    for (int i = 0; i < 3; ++i) {                                                           //Otherwise, it find first empty slot and puts it there
        for (int j = 0; j < 3; ++j) {
            if (inventory[i][j].itemName.empty()) {
                inventory[i][j].itemName = itemName;
                inventory[i][j].quantity = 1;
                cout << "You received: " << itemName << "! It has been added to your inventory.\n";
                return;
            }
        }
    }
    cout << "Your inventory is full! You cannot pick up " << itemName << ".\n";             //added for later functionality with more bosses. Will be a sell mechanic
}

void Player::displayInventory() const {                                                     //As the name suggests, displays inventory. Called after boss kill
    cout << "\n== Inventory ==\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (!inventory[i][j].itemName.empty()) {
                cout << "[" << inventory[i][j].itemName << " x" << inventory[i][j].quantity << "]";
            } else {
                cout << "";
            }
        }
        cout << "\n";
    }
    cout << "\n";
}