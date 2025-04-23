#pragma once
#include "Creature.h"

class Monster : public Creature {
public:
    Monster(string n, int hp, int atk, int def, vector<Abilities> a);
    void displayStatus() const override;
};