#pragma once
#include "Creature.h"

using namespace std;


class Monster : public Creature {                                                                               //Monster Class
public:
    Monster(string name, int health, int maxHealth, int attack, int defense, vector<Abilities> abilities, int dropId, string dropName);      //Constructor with all the components
    void takeTurn(Creature& target);                                                                            //Monster's version of take turn so it'll have random abilities
    static vector<Monster> getDefaultMonsters();                                                                //Vector of all the monsters
    static bool anyAlive(const vector<Monster>& monsters);                                                      //Not used, previous multi-monster functionality
    int getDropId() const;
    string getDropName() const;
};