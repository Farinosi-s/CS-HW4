#include "Monster.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Monster::Monster(string name, int health, int maxHealth, int attack, int defense, vector<Abilities> abilities, string dropId)      //Constructor
    :Creature(name, health, maxHealth, attack, defense, abilities), dropId(dropId) {}                                                //Members Initializer List

void Monster::takeTurn(Creature& target) {                                                              //Monster turn function, uses random ability selection
    if (!isAlive()) return;
    int choice = rand() % abilities.size();
    cout << "\n " << name << " uses " << abilities[choice].name << "!\n";
    useAbility(choice, target);
}

vector<Monster> Monster::getDefaultMonsters() {                                                        //Creates a vector with monster objects of the below monsters
    return {
        Monster("Displacer Beast", 60, 60, 5, 5, {
            Abilities("Blur", {{AbilityType::Buff, 5, "defense"}}),
            Abilities("Shred", {{AbilityType::Damage, 8, ""},{AbilityType::Debuff, 3, "defense"}}),
            Abilities("Ferocious Bite", {{AbilityType::Damage, 8, ""},{AbilityType::Debuff, 3, "attack"}}),
            Abilities("Brutal Slash", {{AbilityType::Damage, 13, ""}}),
            Abilities("Beastial Wrath", {{AbilityType::Buff, 3, "attack"}, {AbilityType::Heal, 6, ""}})
        },"Pelt of the Displacer Beast"),
        Monster("Goblin Chieftain", 80, 80, 4, 5, {
            Abilities("Club", {{AbilityType::Damage, 8, ""}}),
            Abilities("Cunning Trap", {{AbilityType::Damage, 5, ""},{AbilityType::Debuff, 4, "defense"}}),
            Abilities("Bugbear Bodyguards", {{AbilityType::Damage, 8, ""},{AbilityType::Buff, 3, "attack"},{AbilityType::Heal, 5, ""}}),
            Abilities("Call the Worgs", {{AbilityType::Damage, 8, ""},{AbilityType::Buff, 5, "attack"}}),
            Abilities("War Drums", {{AbilityType::Buff, 5, "attack"}, {AbilityType::Heal, 15, ""}})
        },"Goblin Chieftain Mask"),
        Monster("Mind Flayer", 90, 90, 5, 10, {
            Abilities("Mind Grasp", {{AbilityType::Damage, 18, ""},{AbilityType::Debuff, 3, "defense"}}),
            Abilities("Disorient", {{AbilityType::Debuff, 4, "attack"},{AbilityType::Debuff, 4, "defense"}}),
            Abilities("Illithid Pulse", {{AbilityType::Damage, 16, ""},{AbilityType::Buff, 3, "attack"}}),
            Abilities("Psionic Blast", {{AbilityType::Damage, 18, ""}}),
            Abilities("Cerebral Burn", {{AbilityType::Damage, 12, ""}, {AbilityType::Heal, 6, ""}})
        },"Tentacle of the Mind Flayer"),

        Monster("Red Wizard of Thay", 95, 95, 9, 2, {
            Abilities("Dark Ritual", {{AbilityType::Buff, 4, "attack"},{AbilityType::Buff, 4, "defense"}}),
            Abilities("Necrotic Touch", {{AbilityType::Damage, 10, ""},{AbilityType::Heal, 5, ""}}),
            Abilities("Arcane Chains", {{AbilityType::Damage, 5, ""},{AbilityType::Debuff, 3, "attack"}, {AbilityType::Debuff, 3, "defense"}}),
            Abilities("Hellfire Sike", {{AbilityType::Damage, 20, ""}}),
            Abilities("Blood Pact", {{AbilityType::Heal, -5, ""},{AbilityType::Buff, 10, "defense"}})
        },"Dark Wizard Cloak"),

        Monster("Young Red Dragon", 120, 120, 10, 8, {
            Abilities("Flame Breath", {{AbilityType::Damage, 23, ""},{AbilityType::Debuff, 1, "defense"}}),
            Abilities("Sky Roar", {{AbilityType::Buff, 8, "attack"}}),
            Abilities("Tail Smash", {{AbilityType::Damage, 16, ""},{AbilityType::Debuff, 3, "defense"}}),
            Abilities("Wing Buffet", {{AbilityType::Damage, 18, ""},{AbilityType::Debuff, 3, "attack"}}),
            Abilities("Ancient Magic", {{AbilityType::Heal, 15, ""},{AbilityType::Buff, 3, "defense"}})
        },"Red Dragon Fang"),
    };
}


bool Monster::anyAlive(const vector<Monster>& monsters) {                                            //Originally I made it so that you could fight multiple
    for (const auto& m : monsters)                                                                   //monsters at once. Deleted that functionality, but left the bool check
        if (m.isAlive()) return true;                                                                //that looks at the whole list of monsters in case I wanted to add it back
    return false;
}