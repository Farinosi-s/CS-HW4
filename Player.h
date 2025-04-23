#pragma once
#include "Creature.h"

enum class ClassType {
    Warrior,
    Mage,
    Cleric,
    Rogue
};

class Player : public Creature {
private:
    ClassType classType;
public:
    ClassType getClassType() const { return classType;}
    Player(string n, int hp, int atk, int def, vector<Abilities> a, ClassType c);
    void displayStatus() const override;
};