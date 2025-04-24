#include "Battle.h"
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

Battle::Battle(Player& player, Monster& enemy) : player(player), enemy(enemy) {}

void Battle::waitForEnter() {
    cout << "\n(Press Enter to continue...)\n";
    cin.ignore();
    cin.get();
}

void Battle::displayStatus() {
    player.displayStatus();
    enemy.displayStatus();
}

void Battle::playerTurn() {
    cout << "\nChoose your move:\n";
    player.displayAbilities();
    int choice;
    cout << "Enter ability number: ";
    cin >> choice;
    player.useAbility(choice - 1, enemy);
}

void Battle::enemyTurn() {
    int enemyChoice = rand() % enemy.getAbilityCount();
    enemy.useAbility(enemyChoice, player);
}

void Battle::start() {
    cout << "\n" << player.getName() << " encounters a " << enemy.getName() << "!\n";
    waitForEnter();

    while (player.isAlive() && enemy.isAlive()) {
        displayStatus();
        playerTurn();
        waitForEnter();

        if (!enemy.isAlive()) {
            cout << "\n" << enemy.getName() << " has been defeated!\n";
            break;
        }

        enemyTurn();
        waitForEnter();

        if (!player.isAlive()) {
            cout << "\n" << player.getName() << " has fallen... The light fades...\n";
            break;
        }
    }

    cout << "\nThe battle is over.\n";
}
