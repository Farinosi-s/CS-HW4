#include "Monster.h"
#include <cstdlib>
#include <iostream>

using namespace std;

void Monster::takeTurn(Creature& target) {
    if (!isAlive()) return;
    int choice = rand() % abilities.size();
    cout << "\n " << name << " uses " << abilities[choice].name << "!\n";
    useAbility(choice, target);
}

vector<Monster> Monster::getDefaultMonsters() {
    return {
        Monster("Mind Flayer", 100, 5, 10, {
            Abilities("Mind Grasp", {{AbilityType::Damage, 18, ""},{AbilityType::Debuff, 3, "defense"}}),
            Abilities("Disorient", {{AbilityType::Debuff, 4, "attack"},{AbilityType::Debuff, 4, "defense"}}),
            Abilities("Illithid Pulse", {{AbilityType::Damage, 16, ""},{AbilityType::Buff, 3, "attack"}}),
            Abilities("Psionic Blast", {{AbilityType::Damage, 18, ""}}),
            Abilities("Cerebral Burn", {{AbilityType::Damage, 12, ""}, {AbilityType::Heal, 6, ""}})
        }),

        Monster("Red Wizard of Thay", 95, 9, 2, {
            Abilities("Dark Ritual", {{AbilityType::Buff, 4, "attack"},{AbilityType::Buff, 4, "defense"}}),
            Abilities("Necrotic Touch", {{AbilityType::Damage, 10, ""},{AbilityType::Heal, 5, ""}}),
            Abilities("Arcane Chains", {{AbilityType::Damage, 5, ""},{AbilityType::Debuff, 3, "attack"}, {AbilityType::Debuff, 3, "defense"}}),
            Abilities("Hellfire Sike", {{AbilityType::Damage, 20, ""}}),
            Abilities("Blood Pact", {{AbilityType::Heal, -5, ""},{AbilityType::Buff, 10, "defense"}})
        }),

        Monster("Young Red Dragon", 120, 10, 8, {
            Abilities("Flame Breath", {{AbilityType::Damage, 23, ""},{AbilityType::Debuff, 1, "defense"}}),
            Abilities("Sky Roar", {{AbilityType::Buff, 8, "attack"}}),
            Abilities("Tail Smash", {{AbilityType::Damage, 16, ""},{AbilityType::Debuff, 3, "defense"}}),
            Abilities("Wing Buffet", {{AbilityType::Damage, 18, ""},{AbilityType::Debuff, 3, "attack"}}),
            Abilities("Ancient Magic", {{AbilityType::Heal, 10, ""},{AbilityType::Buff, 3, "defense"}})
        }),
    };
}


bool Monster::anyAlive(const vector<Monster>& monsters) {
    for (const auto& m : monsters)
        if (m.isAlive()) return true;
    return false;
}