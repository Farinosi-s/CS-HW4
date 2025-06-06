#pragma once
#include "Player.h"
#include "Monster.h"
#include "Ally.h"

class Battle {
private:
    Player& player;                                //References to the player, monster, and Ally objects
    Monster& enemy;                                //That way, the objects are changed when changed in the battle class 
    Ally* ally;    

public:
    Battle(Player& player, Monster& enemy, Ally* ally = nullptr);        //the Battle constructor with the passed references
    void start();                                                        //all the other standard functions within the battle file
    void displayStatus();
    void playerTurn();
    void enemyTurn();
    void waitForEnter();
    void allyTurn();
};
