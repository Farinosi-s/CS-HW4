#include "Creature.h"
#include <iostream>
#include <algorithm>

Creature::Creature(std::string name, int health, int attack, int defense, std::vector<Abilities> abilities)
    : name(name), health(health), attack(attack), defense(defense), abilities(abilities) {}

std::string Creature::getName() const { return name; }

int Creature::getHealth() const { return health; }

int Creature::getAttack() const { return attack; }

int Creature::getDefense() const { return defense; }

bool Creature::isAlive() const { return health > 0; }

void Creature::takeDamage(int value) {
    int damageTaken = std::max(0, value - defense);
    health -= damageTaken;
    if (health < 0) health = 0;

    std::cout << name << " takes " << damageTaken << " damage!\n";
}

void Creature::increaseAttack(int value) {
    attack += value;
    std::cout << name << "'s attack increases by " << value << "!\n";
}

void Creature::decreaseAttack(int value) {
    attack -= value;
    if (attack < 0) attack = 0;
    std::cout << name << "'s attack decreases by " << value << "!\n";
}

void Creature::increaseDefense(int value) {
    defense += value;
    std::cout << name << "'s defense increases by " << value << "!\n";
}

void Creature::decreaseDefense(int value) {
    defense -= value;
    if (defense < 0) defense = 0;
    std::cout << name << "'s defense decreases by " << value << "!\n";
}

void Creature::displayStatus() const {
    std::cout << " " << name << " - HP: " << health
              << ", ATK: " << attack << ", DEF: " << defense << "\n";
}

void Creature::displayAbilities() const {
    for (size_t i = 0; i < abilities.size(); ++i) {
        std::cout << i + 1 << ". " << abilities[i].name << "\n";
    }
}

void Creature::useAbility(int index, Creature& target) {
    if (index >= 0 && index < static_cast<int>(abilities.size())) {
        std::cout << name << " uses " << abilities[index].name << "!\n";
        abilities[index].use(*this, target);
    } else {
        std::cout << name << " fumbles the action.\n";
    }
}

int Creature::getAbilityCount() const {
    return static_cast<int>(abilities.size());
}