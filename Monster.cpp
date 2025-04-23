#include <iostream>
#include "Monster.h"

Monster::Monster(string n, int hp, int atk, int def, vector<Abilities> a)
    : Creature(n, hp, atk, def, a) {}

void Monster::displayStatus() const {
    cout << name << " [Monster] HP: " << health << "/" << maxHealth
         << " | ATK: " << attack << " | DEF: " << defense << endl;
}