#pragma once
#include <string>
#include <vector>

using namespace std;

enum class AbilityType {
    Damage,
    Heal,
    Buff,
    Debuff
};

class Abilities {
private:
    string name;
    AbilityType type;
    int power;
    string stat;

public:
    Abilities(string n, AbilityType t, int p, string s = "");
    
    string getName() const;
    AbilityType getType() const;
    int getPower() const;
    string getStat() const;

    static vector<Abilities> getAllAbilities();
};