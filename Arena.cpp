#include "Arena.h"

Arena::Arena()
    : playerX(-1), playerY(-1),
      showPlayerDamage(false), showMonsterDamage(false),
      playerDamageAmount(0), monsterDamageAmount(0),
      monsterX(-1), monsterY(-1) {
    clear();
}

void Arena::clear() {
    for (int i = 0; i < ARENA_ROWS; ++i)
        for (int j = 0; j < ARENA_COLS; ++j)
            grid[i][j] = '.';
    monsters.clear();
    playerX = playerY = -1;
    showPlayerDamage = showMonsterDamage = false;
}

void Arena::placePlayer(int x, int y) {
    if (isInBounds(x, y)) {
        playerX = x;
        playerY = y;
        grid[y][x] = 'P';
    }
}

void Arena::placeMonster(const Monster& m, int x, int y) {
    if (isInBounds(x, y)) {
        monsters.push_back({ m, {x, y} });
        monsterX = x;
        monsterY = y;
        grid[y][x] = 'M';
    }
}

void Arena::showDamageToPlayer(int amount) {
    showPlayerDamage = true;
    playerDamageAmount = amount;
}

void Arena::showDamageToMonster(int amount) {
    showMonsterDamage = true;
    monsterDamageAmount = amount;
}

void Arena::clearDamageEffects() {
    showPlayerDamage = false;
    showMonsterDamage = false;
}

void Arena::display() {
    std::cout << "\nArena:\n";
    for (int i = 0; i < ARENA_ROWS; ++i) {
        for (int j = 0; j < ARENA_COLS; ++j) {
            if (j == playerX && i == playerY && showPlayerDamage) {
                std::cout << "P(" << playerDamageAmount << ") ";
            } else if (j == monsterX && i == monsterY && showMonsterDamage) {
                std::cout << "M(" << monsterDamageAmount << ") ";
            } else {
                std::cout << grid[i][j] << "  ";
            }
        }
        std::cout << '\n';
    }
}

bool Arena::isInBounds(int x, int y) {
    return x >= 0 && x < ARENA_COLS && y >= 0 && y < ARENA_ROWS;
}
