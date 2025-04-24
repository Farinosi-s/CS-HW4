#include "Abilities.h"
#include "Creature.h"

using namespace std;

void Abilities::use(Creature& user, Creature& target) const {
    for (const auto& e : effects) {
        switch (e.type) {
            case AbilityType::Damage:
                if (e.value < 0) user.takeDamage(e.value);  // heal if negative
                else target.takeDamage(e.value);
                break;
            case AbilityType::Buff:
                if (e.statAffected == "attack") user.increaseAttack(e.value);
                else if (e.statAffected == "defense") user.increaseDefense(e.value);
                break;
            case AbilityType::Debuff:
                if (e.statAffected == "attack") target.decreaseAttack(e.value);
                else if (e.statAffected == "defense") target.decreaseDefense(e.value);
                break;
        }
    }
}

vector<Abilities> Abilities::getAllAbilities() {
    return {
        Abilities("Slash", {{AbilityType::Damage, 15, ""}}),
        Abilities("Rage", {{AbilityType::Buff, 5, "attack"}}),
        Abilities("Iron Skin", {{AbilityType::Buff, 5, "defense"}}),
        Abilities("Earthquake", {{AbilityType::Damage, 20, ""}}),
        Abilities("Fireball", {{AbilityType::Damage, 25, ""}, {AbilityType::Debuff, 3, "defense"}}),
        Abilities("Lightning Bolt", {{AbilityType::Damage, 30, ""}}),
        Abilities("Greater Heal", {{AbilityType::Damage, -25, ""}}),
        Abilities("Shadow Claw", {{AbilityType::Damage, 22, ""}}),
        Abilities("Heal", {{AbilityType::Damage, -15, ""}}),
        Abilities("Regenerate", {{AbilityType::Buff, 3, "defense"}}),
        Abilities("Battle Cry", {{AbilityType::Buff, 5, "attack"}}),
        Abilities("Curse", {{AbilityType::Debuff, 5, "attack"}}),
        Abilities("Piercing Arrow", {{AbilityType::Damage, 20, ""}}),
        Abilities("Weaken", {{AbilityType::Debuff, 4, "attack"}}),
        Abilities("Mind Drain", {{AbilityType::Damage, 18, ""}, {AbilityType::Buff, 3, "attack"}}),
        Abilities("Armor Break", {{AbilityType::Debuff, 5, "defense"}}),
        Abilities("Armor Break", {{AbilityType::Debuff, 5, "defense"}}),
        Abilities("Armor Break", {{AbilityType::Debuff, 5, "defense"}}),
        Abilities("Armor Break", {{AbilityType::Debuff, 5, "defense"}}),
        Abilities("Armor Break", {{AbilityType::Debuff, 5, "defense"}}),
        Abilities("Armor Break", {{AbilityType::Debuff, 5, "defense"}}),
        Abilities("Armor Break", {{AbilityType::Debuff, 5, "defense"}}),
        Abilities("Armor Break", {{AbilityType::Debuff, 5, "defense"}}),
        Abilities("Armor Break", {{AbilityType::Debuff, 5, "defense"}}),
        Abilities("Armor Break", {{AbilityType::Debuff, 5, "defense"}}),

    };
}