#include "Abilities.h"
#include "Creature.h"

using namespace std;


void Abilities::use(Creature& user, Creature& target) const {
    for (const auto& e : effects) {
        switch (e.type) {
            case AbilityType::Damage: {
                int userAttack = user.getAttack() * .02; 
                int scaledDamage = static_cast<int>(e.value * (userAttack + 1)); 
                target.takeDamage(scaledDamage);
                break;
            }
            case AbilityType::Heal:
                user.heal(e.value);
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
        Abilities("Unused", {{AbilityType::Damage, 80, ""}}),       
        Abilities("Slash", {{AbilityType::Damage, 20, ""}}),
        Abilities("Rage", {{AbilityType::Buff, 5, "attack"}, {AbilityType::Buff, 5, "defense"}}),
        Abilities("Intimidating Shout", {{AbilityType::Debuff, 8, "attack"}}),
        Abilities("Rending Blow", {{AbilityType::Damage, 10, ""}, {AbilityType::Debuff, 6, "defense"}}),
        Abilities("Fireball", {{AbilityType::Damage, 20, ""}, {AbilityType::Debuff, 3, "defense"}}),
        Abilities("Mage Armor", {{AbilityType::Buff, 8, "defense"}}),
        Abilities("Health Potion", {{AbilityType::Heal, 15, ""}}),
        Abilities("Monologue", {{AbilityType::Buff, 8, "attack"}}),
        Abilities("Greater Heal", {{AbilityType::Heal, 25, ""}}),
        Abilities("Necrotic Touch", {{AbilityType::Damage, 10, ""}, {AbilityType::Heal, 10, ""}}),
        Abilities("Divine Plea", {{AbilityType::Buff, 5, "attack"}, {AbilityType::Heal, 10, ""}}),
        Abilities("Radiant Bolt", {{AbilityType::Damage, 15, ""}, {AbilityType::Debuff, 3, "defense"}}),
        Abilities("Piercing Arrow", {{AbilityType::Damage, 15, ""}, {AbilityType::Debuff, 5, "defense"}}),
        Abilities("Stealth", {{AbilityType::Buff, 3, "defense"}, {AbilityType::Buff, 5, "attack"}}),
        Abilities("Mind Games", {{AbilityType::Debuff, 5, "defense"}, {AbilityType::Buff, 5, "attack"}}),
        Abilities("Sneak Attack", {{AbilityType::Damage, 25, ""}}),
        Abilities("Nature's Grasp", {{AbilityType::Debuff, 8, "defense"}}),
        Abilities("Thorn Whip", {{AbilityType::Damage, 10, ""}, {AbilityType::Debuff, 5, "attack"}}),
        Abilities("Shapeshift", {{AbilityType::Buff, 4, "attack"}, {AbilityType::Buff, 6, "defense"}}),
        Abilities("Wild Strike", {{AbilityType::Damage, 20, ""}, {AbilityType::Debuff, 3, "attack"}}),
    };
}