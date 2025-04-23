#pragma once
#include <string>
#include <vector>
#include "Abilities.h"

using namespace std;

class Creature {
protected:
    string name;
    int health;
    int maxHealth;
    int attack;
    int defense;
    vector<Abilities> abilities;

public:
    Creature(string n, int hp, int atk, int def, vector<Abilities> a);
    virtual void displayStatus() const;
    void displayAbilities() const;
    void useAbility(int index, Creature& target);
    void takeDamage(int dmg);
    void heal(int amount);
    void modifyStat(string stat, int amount);
    bool isAlive() const;
    string getName() const;
    int getAbilityCount() const;
};
