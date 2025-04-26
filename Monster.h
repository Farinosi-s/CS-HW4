#pragma once
#include "Creature.h"
#include <string>

using namespace std;


class Monster : public Creature {  
private:
    string dropId;                                                                        //Monster Class
public:
    Monster(string name, int health, int maxHealth, int attack, int defense, vector<Abilities> abilities, string dropId);      //Constructor with all the components
    void takeTurn(Creature& target);                                                                            //Monster's version of take turn so it'll have random abilities
    static vector<Monster> getDefaultMonsters();                                                          //Vector of all the monsters
    static bool anyAlive(const vector<Monster>& monsters);
    string getDropId() const { return dropId; }                                                //gets the item for the player after killing the monster
};