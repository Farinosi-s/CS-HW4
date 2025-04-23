#include <iostream>
#include "Player.h"

Player::Player(string n, int hp, int atk, int def, vector<Abilities> a, ClassType c)
    : Creature(n, hp, atk, def, a), classType(c) {}

void Player::displayStatus() const {
    cout << name << " [Player] HP: " << health << "/" << maxHealth
         << " | ATK: " << attack << " | DEF: " << defense << endl;
}