#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include "Abilities.h"
#include "Monster.h"
#include "Player.h"

using namespace std;

void pause(int ms = 1000) {
    this_thread::sleep_for(chrono::milliseconds(ms));
}

void waitForEnter() {
    cout << "\n(Press Enter to continue...)\n";
    cin.ignore();
    cin.get();
}

// Function to display available enemies
void displayEnemies(const vector<Monster>& enemies) {
    cout << "\nThe guild's Hunt board displays jobs for the following enemies:\n";
    for (int i = 0; i < enemies.size(); ++i) {
        cout << i + 1 << ". " << enemies[i].getName() << "\n";
    }
}

// Function to allow player to choose an enemy
Monster chooseEnemy(const vector<Monster>& enemies) {
    int choice;
    cout << "Choose your target's number: ";
    cin >> choice;

    if (choice < 1 || choice > enemies.size()) {
        cout << "Invalid choice, picking the first enemy.\n";
        choice = 1;
    }

    return enemies[choice - 1];
}

// Function to choose the player's class
Player chooseClass(const string& playerName) {
    vector<Abilities> allAbilities = Abilities::getAllAbilities(); // Assuming you have a function to get all abilities
    vector<Abilities> abilities;
    ClassType type;

    cout << "\nYou come across a chest of imbued weapons. Which calls to you?:\n";
    cout << "1. Greataxe (Warrior)\n";
    cout << "2. Arcane Tome (Mage)\n";
    cout << "3. Holy Symbol (Cleric)\n";
    cout << "4. Pair of Daggers (Rogue)\n";
    cout << "5. Oaken Staff (Druid)\n";
    cout << "Enter the item's number: ";

    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            type = ClassType::Warrior;
            abilities = {
                allAbilities[1],  // Slash
                allAbilities[2],  // Rage
                allAbilities[3],  // Intimidating Shout
                allAbilities[4]   // Rending Blow
            };
            break;
        case 2:
            type = ClassType::Mage;
            abilities = {
                allAbilities[5],  // Fireball
                allAbilities[6],  // Mage Armor
                allAbilities[7],  // Health Potion
                allAbilities[8]   // Monologue
            };
            break;
        case 3:
            type = ClassType::Cleric;
            abilities = {
                allAbilities[9],  // Greater Heal
                allAbilities[10], // Necrotic Touch
                allAbilities[11], // Divine Plea
                allAbilities[12]  // Radiant Bolt
            };
            break;
        case 4:
            type = ClassType::Rogue;
            abilities = {
                allAbilities[13], // Piercing Arrow
                allAbilities[14], // Stealth
                allAbilities[15], // Mind Games
                allAbilities[16]  // Sneak Attack
            };
        case 5:
        default:
            type = ClassType::Druid;
            abilities = {
                allAbilities[17], // Nature's Grasp
                allAbilities[18], // Thorn Whip
                allAbilities[19], // Shapeshift
                allAbilities[20], // Enrage
            };
        break;
    }

    // Create and return a Player object
    return Player(playerName, 100, 5, 5, abilities, type);
}

int main() {
    srand(time(0));

    cout << "A distant world lies on the edge of light and darkness...\n";
    pause();
    cout << "Creatures clash under the crimson sky...\n";
    pause();
    cout << "\nBut one hero rises...\n";
    pause();

    string playerName;
    cout << "\nWhat is your name, brave adventurer? ";
    getline(cin, playerName);

    cout << "\nWelcome, " << playerName << ". Your journey begins now...\n";
    pause(1500);

    // Initialize available enemies
    vector<Monster> enemies = Monster::getDefaultMonsters(); // Assuming you have a default set of enemies

    // Initialize player class
    Player player = chooseClass(playerName);

    bool continueFighting = true;
    while (continueFighting) {
        displayEnemies(enemies);

        // Let the player choose an enemy to fight
        Monster enemy = chooseEnemy(enemies);

        cout << "\n " << playerName << " encounters a" << enemy.getName() << "!\n";
        waitForEnter();

        // Battle loop
        while (player.isAlive() && enemy.isAlive()) {
            player.displayStatus();
            enemy.displayStatus();

            cout << "\nChoose your move:\n";
            player.displayAbilities();
            int choice;
            cout << "Enter ability number: ";
            cin >> choice;

            player.useAbility(choice - 1, enemy);
            waitForEnter();

            if (!enemy.isAlive()) {
                cout << "\n " << enemy.getName() << " has been defeated!\n";
                break;
            }

            int enemyChoice = rand() % enemy.getAbilityCount();
            enemy.useAbility(enemyChoice, player);
            waitForEnter();

            if (!player.isAlive()) {
                cout << "\n " << player.getName() << " has fallen... The light fades...\n";
                break;
            }
        }

        cout << "\nThe battle is over.\n";

        // Ask if the player wants to fight another monster or quit
        cout << "\nHow would you like to proceed?\n";
        cout << "1. Press the attack, continue fighting!\n";
        cout << "2. Return to camp and heal before setting out again\n";
        cout << "3. Quit the game\n";
        int choice;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 3) {
            continueFighting = false;
            cout << "\n" << playerName << "retires from adventuring!\n";
        }
        if (choice == 2) {
            player.healPlayer(100);
        }
    }

    return 0;
}
