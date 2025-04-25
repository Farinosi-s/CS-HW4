#pragma once
#include <string>
#include <vector>
#include "Abilities.h"

using namespace std;

class Creature {                    //All of the base creature stats. These are inherited by Monster and Player
protected:
    string name;
    int health;
    int maxHealth;
    int attack;
    int defense;
    vector<Abilities> abilities;

public:
    Creature(string name, int health, int maxHealth, int attack, int defense, vector<Abilities> abilities);        //Constructor with all the components

    string getName() const;                                                     //Get functions and checking if alive bool
    int getHealth() const;
    int getMaxHealth() const;
    int getAttack() const;
    int getDefense() const;
    bool isAlive() const;

    void takeDamage(int value);                                                 //All the functions that edit the creature from what the abilities do
    void heal(int value);
    void increaseAttack(int value);
    void decreaseAttack(int value);
    void increaseDefense(int value);
    void decreaseDefense(int value);

    void displayStatus() const;                                                 //Next two are displays
    void displayAbilities() const;
    void useAbility(int index, Creature& target);                               //Long explanation in .cpp file

    int getAbilityCount() const;
};