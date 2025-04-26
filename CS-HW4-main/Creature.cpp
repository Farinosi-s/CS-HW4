#include "Creature.h"
#include "Abilities.h"
#include <iostream>
#include <algorithm>

using namespace std;

Creature::Creature(string name, int health, int maxHealth, int attack, int defense, vector<Abilities> abilities)        //Constructor, vector explained in abilities class
    : name(name), health(health), maxHealth(maxHealth), attack(attack), defense(defense), abilities(abilities) {}       //Member initializer list

string Creature::getName() const { return name; }                                                                       //All the get functions returning their stats

int Creature::getHealth() const { return health; }

int Creature::getMaxHealth() const { return maxHealth; }

int Creature::getAttack() const { return attack; }

int Creature::getDefense() const { return defense; }

bool Creature::isAlive() const { return health > 0; }

void Creature::takeDamage(int value) {                                                              //Taking damage function. Looks at defense and applies
    double reduction = (defense* .01);                                                              //reduction at 1% per point of defense. Then applies and
    double damageTaken = value *= (1 - reduction);                                                  //converts value back to an int for dmg readout
    health -= damageTaken;
    if (health < 0) health = 0;

    cout << name << " takes " << static_cast<int>(damageTaken) << " damage!\n";
}

void Creature::heal(int value) {                                                                    //Standard heal funciton. Looks to make sure not healing over max HP
    int heal = value;
    health += heal;
    if (health > maxHealth) health = maxHealth;

    cout << name << " recieves " << value << " points of healing!\n";
}

void Creature::increaseAttack(int value) {                                                          //Next four just increase the stat as they're intended.
    attack += value;                                                                                //More on this in the abilities files
    cout << name << "'s attack increases by " << value << "!\n";
}

void Creature::decreaseAttack(int value) {
    attack -= value;
    cout << name << "'s attack decreases by " << value << "!\n";
}

void Creature::increaseDefense(int value) {
    defense += value;
    cout << name << "'s defense increases by " << value << "!\n";
    if (defense >= 51){
        defense = 50;
        cout << name << " has achieved peak hardiness.. further results not guaranteed!";
    }
}

void Creature::decreaseDefense(int value) {
    defense -= value;
    cout << name << "'s defense decreases by " << value << "!\n";
}

void Creature::displayStatus() const {                                                          //stat display fucntion
    cout << " " << name << " - HP: " << health
              << ", ATK: " << attack << ", DEF: " << defense << "\n";
}

void Creature::displayAbilities() const {                                                       //displays abilities for player to choose from
    for (int i = 0; i < abilities.size(); ++i) {                                                //Shows them at starting at 1 instead of 0. Fixes on the choice side
        cout << i + 1 << ". " << abilities[i].name << "\n";
    }
}

void Creature::useAbility(int index, Creature& target) {                              //Passes int number for ability number and creature target, can be player or enemy
    if (index >= 0 && index<static_cast<int>(abilities.size())) {                     //size pulls the number of elements in a vector, checks that choice is in range
        cout << name << " uses " << abilities[index].name << "!\n";                   //Written output for the player to confirm what's happening
        abilities[index].use(*this, target);                                          //use is from the abilities files. "*this" refers to the object calling the function
    } else {                                                                          //ie. player.useAbility(choice - 1, enemy), passing in those values to this function
        cout << name << " fumbles the action.\n";                                     //this* will be the the player, choice - 1 is the ability index, and enemy is the 
    }                                                                                 //creature object that is the target being referenced with the Creature& target.
}                                                                                     //This works because use is set up like -> Abilities::use(Creature& user, Creature& target)
                                                                                      //it's user, then target. in that order. Refering to the object because it expects those arguements
int Creature::getAbilityCount() const {                                               //Which is necessary, because otherwise it would edit a copy instead of the actual objects
    return static_cast<int>(abilities.size());
}                                                       //gets number of abilities. Weird quirk that you have to static cast .size because it's an "unsigned int"