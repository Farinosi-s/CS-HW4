#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

enum class AbilityType {                                            //Helped make a switch statement for different ability cases
    Damage,
    Heal,
    Buff,
    Debuff
};

class Effect {                                                      //Class that will be used in vectors to attach multiple objects to abilities
public:
    AbilityType type;
    int value;
    string statAffected;
};

class Creature;                                                     // Forward declaration for use function

class Abilities {
public:
    string name;                                                    
    vector<Effect> effects;                                         //Class effect vector with value type

    Abilities(string name, vector<Effect> effects)                  //Abilities constructor, Name and then all the different value types and their values
        : name(name), effects(effects) {}                           //Members initialized 

    void use(Creature& user, Creature& target) const;               //Use function, activated within the useAbility function in the Monster file

    static vector<Abilities> getAllAbilities();                     //Creates vector with all the abilities that can be accessed by index
};