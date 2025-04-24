#pragma once
#include <string>
#include <vector>
#include "Abilities.h"

class Creature {
protected:
    std::string name;
    int health;
    int attack;
    int defense;
    std::vector<Abilities> abilities;

public:
    Creature(std::string name, int health, int attack, int defense, std::vector<Abilities> abilities);

    std::string getName() const;
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