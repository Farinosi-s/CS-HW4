#include "Battle.h"
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

Battle::Battle(Player& player, Monster& enemy)                      //Constructor
    : player(player), enemy(enemy) {}                               //Member initializer list

void Battle::waitForEnter() {                                       //Have this in the main function, pausing element to create a sense of transition
    cout << "\n(Press Enter to continue...)\n";
    cin.ignore();
    cin.get();
}

void Battle::displayStatus() {                                      //function to call two other functions, pulls the stats and displays
    player.displayStatus();
    enemy.displayStatus();
}

void Battle::playerTurn() {                                         //Player input
    cout << "\nChoose your move:\n";
    player.displayAbilities();                                      //in the called function it adds one so the lists starts at 1 instead of 0
    int choice;
    cout << "Enter ability number: ";
    cin >> choice;
    player.useAbility(choice - 1, enemy);                           //the minus one is to match it back up with the actually vector list
}

void Battle::enemyTurn() {                                      
    int enemyChoice = rand() % enemy.getAbilityCount();             //random ability from the list of their abilities
    enemy.useAbility(enemyChoice, player);
}

void Battle::start() {                                                                          //Main battle loop
    cout << "\n" << player.getName() << " encounters a " << enemy.getName() << "!\n";           //Encounter message

    while (player.isAlive() && enemy.isAlive()) {                                               //Standard turn based combat
        displayStatus();
        playerTurn();
        waitForEnter();

        if (!enemy.isAlive()) {                                                                 //enemy dies
            cout << "\n" << enemy.getName() << " has been defeated!\n";
            break;
        }

        enemyTurn();
        waitForEnter();

        if (!player.isAlive()) {                                                                //player dies
            cout << "\n" << player.getName() << " has fallen... The light fades...\n";
            break;
        }
    }

    cout << "\nThe battle is over.\n";
}
