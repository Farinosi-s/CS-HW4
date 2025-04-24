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
    cout << "\nChoose an enemy to fight:\n";
    for (size_t i = 0; i < enemies.size(); ++i) {
        cout << i + 1 << ". " << enemies[i].getName() << "\n";
    }
}

// Function to allow player to choose an enemy
Monster chooseEnemy(const vector<Monster>& enemies) {
    int choice;
    cout << "Enter enemy number: ";
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

    cout << "\nChoose your class:\n";
    cout << "1. Warrior\n";
    cout << "2. Mage\n";
    cout << "3. Cleric\n";
    cout << "4. Rogue\n";
    cout << "Enter choice: ";

    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            type = ClassType::Warrior;
            abilities = {
                allAbilities[0],  // Slash
                allAbilities[11], // Rage
                allAbilities[12], // Iron Skin
                allAbilities[6]   // Earthquake
            };
            break;
        case 2:
            type = ClassType::Mage;
            abilities = {
                allAbilities[1],  // Fireball
                allAbilities[2],  // Lightning Bolt
                allAbilities[9],  // Greater Heal
                allAbilities[4]   // Shadow Claw
            };
            break;
        case 3:
            type = ClassType::Cleric;
            abilities = {
                allAbilities[8],  // Heal
                allAbilities[10], // Regenerate
                allAbilities[13], // Battle Cry
                allAbilities[16]  // Curse
            };
            break;
        case 4:
        default:
            type = ClassType::Rogue;
            abilities = {
                allAbilities[5],  // Piercing Arrow
                allAbilities[15], // Weaken
                allAbilities[18], // Mind Drain
                allAbilities[19]  // Armor Break
            };
            break;
    }

    // Create and return a Player object
    return Player(playerName, 100, 10, 5, abilities, type);
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
    cout << "\nWhat is your name, brave warrior? ";
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

        cout << "\n " << playerName << " vs " << enemy.getName() << " begins!\n";
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
        cout << "\nWould you like to fight another monster or quit?\n";
        cout << "1. Fight another monster\n";
        cout << "2. Quit the game\n";
        int choice;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 2) {
            continueFighting = false;
            cout << "\nThanks for playing, " << playerName << "!\n";
        }
    }

    return 0;
}
