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
        Monster("Nightfang", 80, 8, 4, {
            Abilities("Dark Claw", {
                {AbilityType::Damage, 18, ""},
                {AbilityType::Debuff, 3, "defense"}
            }),
            Abilities("Shadow Howl", {
                {AbilityType::Debuff, 4, "attack"}
            }),
            Abilities("Night Slash", {
                {AbilityType::Damage, 22, ""}
            })
        }),

        Monster("Bonegnasher", 70, 9, 2, {
            Abilities("Piercing Roar", {
                {AbilityType::Damage, 15, ""},
                {AbilityType::Debuff, 2, "attack"}
            }),
            Abilities("Bone Crush", {
                {AbilityType::Damage, 20, ""}
            }),
            Abilities("Gnaw", {
                {AbilityType::Damage, 12, ""},
                {AbilityType::Buff, 2, "attack"}
            })
        }),

        Monster("Ash Serpent", 65, 10, 3, {
            Abilities("Fire Breath", {
                {AbilityType::Damage, 22, ""},
                {AbilityType::Debuff, 1, "defense"}
            }),
            Abilities("Coil", {
                {AbilityType::Buff, 3, "defense"}
            }),
            Abilities("Tail Swipe", {
                {AbilityType::Damage, 16, ""}
            })
        })
    };
}


bool Monster::anyAlive(const vector<Monster>& monsters) {
    for (const auto& m : monsters)
        if (m.isAlive()) return true;
    return false;
}