#pragma once
#include <string>
#include <vector>
#include "Abilities.h"

using namespace std;

class Creature {
protected:
    string name;
    int health;
    int attack;
    int defense;
    vector<Abilities> abilities;

public:
    Creature(string name, int health, int attack, int defense, vector<Abilities> abilities);

    string getName() const;
    int getHealth() const;
    int getAttack() const;
    int getDefense() const;
    bool isAlive() const;

    void takeDamage(int value);
    void increaseAttack(int value);
    void decreaseAttack(int value);
    void increaseDefense(int value);
    void decreaseDefense(int value);

    void displayStatus() const;
    void displayAbilities() const;
    void useAbility(int index, Creature& target);

    int getAbilityCount() const;
};