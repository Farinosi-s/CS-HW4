#include "Ally.h"
#include <iostream>
using namespace std;

Ally::Ally(const std::string& name, int health, int maxHealth, int attack, int defense, std::vector<Abilities> abilities)  //Constructor
    : Creature(name, health, maxHealth, attack, defense, abilities) {}                                                     //Initializes members list

void Ally::assist(Creature& player, Creature& enemy) {                                                                     //Ally version of taking a turn
    if (!abilities.empty()) {
        int randomIndex = rand() % abilities.size(); 
        Abilities chosenAbility = abilities[randomIndex];                                                                  //Random selection of abilities

        cout << name << " uses " << chosenAbility.name << "!\n";

        if (!chosenAbility.effects.empty()) {
            AbilityType type = chosenAbility.effects[0].type;

            if (type == AbilityType::Buff || type == AbilityType::Heal) {
                chosenAbility.use(player, *this);
            } else {
                chosenAbility.use(*this, enemy);
            }
        }
    }
}

Ally Ally::getDefaultAlly() {
    vector<Abilities> allyAbilities = {
        Abilities("Inspiring Tune", { {AbilityType::Buff, 5, "attack"} }),
        Abilities("Fresh Tea", { {AbilityType::Heal, 8, ""} }),
        Abilities("Pitchfork Jab", { {AbilityType::Damage, 8, ""} })
    };

    return Ally("Billy the Farmhand", 50, 50, 8, 3, allyAbilities);
}
