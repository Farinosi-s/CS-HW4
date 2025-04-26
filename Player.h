#pragma once
#include "Creature.h"
#include <vector>
#include <string>

using namespace std;

enum class ClassType {                               //Enum for the different player classes
    Warrior,
    Mage,
    Cleric,
    Rogue,
    Druid,
};

class InventorySlot {                           //Third class within a class, used for the inventory array, 3 by 3 grid. Visual would be cool if eventually added
public:
    string itemName = "";
    int quantity = 0;
};

class Player : public Creature {
private:
    ClassType type;                          //unique member for player, added here instead of in the creature class
    InventorySlot inventory[3][3];          //2D array for inventory that also uses Composition. 9 possible trophies, even though there's only 5 bosses currently
                                            //more could be added along with functionality to discard/sell trophies
public:
    Player(string name, int health, int maxHealth, int attack, int defense, vector<Abilities> abilities, ClassType type);           //Constructor with all the components
    void healPlayer(int amount);                                                                                                    //heal function, seperate from abilties
    ClassType getClassType() const; 
    void addItem(const string& itemName);               //adds items to inventory
    void displayInventory() const;                      //displays those items                                                                                                   
};