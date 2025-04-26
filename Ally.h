#pragma once
#include "Creature.h"
#include "Abilities.h"
#include <string>
#include <vector>

class Ally : public Creature {
public:
    Ally(const std::string& name, int health, int maxHealth, int attack, int defense, const std::vector<Abilities> abilities);   //constructor 

    void assist(Creature& player, Creature& enemy);  // Can either heal the player or attack the enemy
    static Ally getDefaultAlly();                    // Creates the Ally
};
