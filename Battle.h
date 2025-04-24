#pragma once
#include "Player.h"
#include "Monster.h"

class Battle {
public:
    Battle(Player& player, Monster& enemy);
    void start();

private:
    Player& player;
    Monster& enemy;

    void displayStatus();
    void playerTurn();
    void enemyTurn();
    void waitForEnter();
};
