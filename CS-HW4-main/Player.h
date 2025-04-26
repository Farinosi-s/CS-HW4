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

class Player : public Creature {
private:
    ClassType type;     //unique member for player, added here instead of in the creature class
    int inventory[5][2]; // 5 possible trophies, [][0] = item ID, [][1] = quantity                        

public:
    Player(string name, int health, int maxHealth, int attack, int defense, vector<Abilities> abilities, ClassType type);           //Constructor with all the components
    void healPlayer(int amount);                                                                                                    //heal function, seperate from abilties
    ClassType getClassType() const;    
    void addItem(int itemId);                                                                                             //get function
};