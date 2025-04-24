#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

enum class AbilityType {
    Damage,
    Heal,
    Buff,
    Debuff
};

struct Effect {
    AbilityType type;
    int value;
    string statAffected;
};

class Creature; // Forward declaration

class Abilities {
public:
    string name;
    vector<Effect> effects;

    Abilities(string name, vector<Effect> effects)
        : name(name), effects(effects) {}

    void use(Creature& user, Creature& target) const;

    static vector<Abilities> getAllAbilities();
};