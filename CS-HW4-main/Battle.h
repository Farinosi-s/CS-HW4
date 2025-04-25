#pragma once
#include "Player.h"
#include "Monster.h"

class Battle {
private:
    Player& player;                                //References to the player and monster objects
    Monster& enemy;                                //That way, the objects are changed when changed in the battle class 
    
public:
    Battle(Player& player, Monster& enemy);        //the Battle constructor with the passed references
    void start();                                  //all the other standard functions within the battle file
    void displayStatus();
    void playerTurn();
    void enemyTurn();
    void waitForEnter();

};
