#include "Abilities.h"

Abilities::Abilities(string n, AbilityType t, int p, string s)
    : name(n), type(t), power(p), stat(s) {}

string Abilities::getName() const { return name; }
AbilityType Abilities::getType() const { return type; }
int Abilities::getPower() const { return power; }
string Abilities::getStat() const { return stat; }

vector<Abilities> Abilities::getAllAbilities() {
    return {
        // Damage Abilities
        Abilities("Slash", AbilityType::Damage, 15),
        Abilities("Fireball", AbilityType::Damage, 20),
        Abilities("Lightning Bolt", AbilityType::Damage, 25),
        Abilities("Icicle Spear", AbilityType::Damage, 18),
        Abilities("Shadow Claw", AbilityType::Damage, 22),
        Abilities("Piercing Arrow", AbilityType::Damage, 19),
        Abilities("Earthquake", AbilityType::Damage, 30),
        Abilities("Meteor Punch", AbilityType::Damage, 28),
        
        // Healing Abilities
        Abilities("Heal", AbilityType::Heal, 20),
        Abilities("Greater Heal", AbilityType::Heal, 35),
        Abilities("Regenerate", AbilityType::Heal, 25),
        
        // Buffs
        Abilities("Rage", AbilityType::Buff, 5, "attack"),
        Abilities("Iron Skin", AbilityType::Buff, 7, "defense"),
        Abilities("Battle Cry", AbilityType::Buff, 6, "attack"),
        Abilities("Fortify", AbilityType::Buff, 6, "defense"),
        
        // Debuffs
        Abilities("Weaken", AbilityType::Debuff, 5, "attack"),
        Abilities("Curse", AbilityType::Debuff, 7, "defense"),
        Abilities("Mind Drain", AbilityType::Debuff, 6, "attack"),
        Abilities("Armor Break", AbilityType::Debuff, 8, "defense"),
        
        // Mixed
        Abilities("Vampiric Touch", AbilityType::Damage, 15)  // Could also implement drain later
    };
}