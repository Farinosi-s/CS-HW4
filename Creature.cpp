#include <iostream>
#include <algorithm>
#include "Creature.h"

Creature::Creature(string n, int hp, int atk, int def, vector<Abilities> a)
    : name(n), health(hp), maxHealth(hp), attack(atk), defense(def), abilities(a) {}

void Creature::displayStatus() const {
    cout << name << " HP: " << health << "/" << maxHealth
         << " | ATK: " << attack << " | DEF: " << defense << endl;
}

void Creature::displayAbilities() const {
    for (size_t i = 0; i < abilities.size(); i++) {
        cout << i + 1 << ". " << abilities[i].getName();
        switch (abilities[i].getType()) {
            case AbilityType::Damage:
                cout << " (DMG: " << abilities[i].getPower() << ")";
                break;
            case AbilityType::Heal:
                cout << " (Heal: " << abilities[i].getPower() << ")";
                break;
            case AbilityType::Buff:
            case AbilityType::Debuff:
                cout << " (" << abilities[i].getStat()
                     << (abilities[i].getType() == AbilityType::Buff ? " +" : " -")
                     << abilities[i].getPower() << ")";
                break;
        }
        cout << endl;
    }
}

void Creature::useAbility(int index, Creature& target) {
    if (index < 0 || index >= abilities.size()) {
        cout << name << " messed up and takes 5 damage!\n";
        takeDamage(5);
        return;
    }

    Abilities a = abilities[index];
    cout << name << " used " << a.getName() << "!\n";

    switch (a.getType()) {
        case AbilityType::Damage: {
            int raw = a.getPower() + attack;
            int mitigated = max(1, raw - target.defense);
            target.takeDamage(mitigated);
            cout << target.getName() << " took " << mitigated << " damage!\n";
            break;
        }
        case AbilityType::Heal:
            heal(a.getPower());
            cout << name << " healed for " << a.getPower() << " HP!\n";
            break;

        case AbilityType::Buff:
            modifyStat(a.getStat(), a.getPower());
            cout << name << "'s " << a.getStat() << " increased by " << a.getPower() << "!\n";
            break;

        case AbilityType::Debuff:
            target.modifyStat(a.getStat(), -a.getPower());
            cout << target.getName() << "'s " << a.getStat() << " decreased by " << a.getPower() << "!\n";
            break;
    }
}

void Creature::takeDamage(int dmg) {
    health -= dmg;
    if (health < 0) health = 0;
}

void Creature::heal(int amount) {
    health += amount;
    if (health > maxHealth) health = maxHealth;
}

void Creature::modifyStat(string stat, int amount) {
    if (stat == "attack") attack += amount;
    else if (stat == "defense") defense += amount;
}

bool Creature::isAlive() const {
    return health > 0;
}

string Creature::getName() const {
    return name;
}

int Creature::getAbilityCount() const {
    return abilities.size();
}