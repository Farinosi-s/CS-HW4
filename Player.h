#pragma once
#include "Creature.h"
#include <vector>
#include <string>

using namespace std;

enum class ClassType {
    Warrior,
    Mage,
    Cleric,
    Rogue,
    Druid,
};

class Player : public Creature {
private:
    ClassType type;

public:
    Player(string name, int health, int maxHealth, int attack, int defense, vector<Abilities> abilities, ClassType type);
    void healPlayer(int amount);
    ClassType getClassType() const;
};