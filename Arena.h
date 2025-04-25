#ifndef ARENA_H
#define ARENA_H

#include <iostream>
#include <vector>
#include <utility>
#include "Monster.h"

const int ARENA_ROWS = 10;
const int ARENA_COLS = 10;

class Arena {
private:
    char grid[ARENA_ROWS][ARENA_COLS]; //2D array for arena

    int playerX, playerY;
    std::vector<std::pair<Monster, std::pair<int, int>>> monsters;

    //Damage effect tracking:
    bool showPlayerDamage;
    int playerDamageAmount;

    bool showMonsterDamage;
    int monsterDamageAmount;
    int monsterX, monsterY;

public:
    Arena();

    void clear();
    void placePlayer(int x, int y);
    void placeMonster(const Monster& m, int x, int y);

    void showDamageToPlayer(int amount);
    void showDamageToMonster(int amount);
    void clearDamageEffects();

    void display();
    bool isInBounds(int x, int y);
};

#endif // ARENA_H