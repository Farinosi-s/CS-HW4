#pragma once
#include "Creature.h"

using namespace std;


class Monster : public Creature {
public:
    Monster(string name, int health, int maxHealth, int attack, int defense, vector<Abilities> abilities)
        : Creature(name, health, maxHealth, attack, defense, abilities) {}

    void takeTurn(Creature& target);
    static vector<Monster> getDefaultMonsters();
    static bool anyAlive(const vector<Monster>& monsters);
};