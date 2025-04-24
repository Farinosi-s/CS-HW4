#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include "Abilities.h"
#include "Monster.h"
#include "Player.h"
#include "Battle.h"

using namespace std;

void pause(int ms = 4000) {
    this_thread::sleep_for(chrono::milliseconds(ms));
}

void waitForEnter() {
    cout << "\n(Press Enter to continue...)\n";
    cin.ignore();
    cin.get();
}

// Function to display available enemies
void displayEnemies(const vector<Monster>& enemies) {
    cout << "\nWhich quarry will you hunt next?:\n";
    for (int i = 0; i < enemies.size(); ++i) {
        cout << i + 1 << ". " << enemies[i].getName() << "\n";
    }
}

// Function to allow player to choose an enemy
Monster chooseEnemy(const vector<Monster>& enemies) {
    int choice;
    cout << "Choose your target's number: ";
    cin >> choice;

    if (choice < 1 || choice > enemies.size()) {                        //need to make it so that this is any choice that isn't a number between expected values
        cout << "Invalid choice, picking the first enemy.\n";
        choice = 1;
    }

    return enemies[choice - 1];
}

// Function to choose the player's class
Player chooseClass(const string& playerName) {
    vector<Abilities> allAbilities = Abilities::getAllAbilities(); 
    vector<Abilities> abilities;
    ClassType type;

    cout << "\nWhich weapon is readied for battle?: \n";
    cout << "1. Greataxe (Warrior)\n";
    cout << "2. Arcane Tome (Mage)\n";
    cout << "3. Holy Symbol (Cleric)\n";
    cout << "4. Pair of Daggers (Rogue)\n";
    cout << "5. Oaken Staff (Druid)\n";
    cout << "Enter the item's number: ";

    int choice;
    cin >> choice;                                      //right now, all invalid choices break the game. Might want to fix

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
            break;
        case 5:
        default:
            type = ClassType::Druid;
            abilities = {
                allAbilities[17], // Nature's Bounty
                allAbilities[18], // Thorn Whip
                allAbilities[19], // Shapeshift
                allAbilities[20], // Wild Strike
            };
        break;
    }

    // Create and return a Player object
    return Player(playerName, 100, 100, 5, 5, abilities, type);
}

int main() {
    srand(time(0));
    cout << "\n";
    cout << "\nThe sun sinks behind the Bloodspire Mountains, draping the village of Bramblehearth in shadows and fear...\n";
    pause();
    cout << "For weeks now, beasts not seen in a generation have stalked the edges of civilization—howling things with too many eyes, \n";
    pause();
    cout << "scales that gleam like armor, and claws that tear through stone. The people are desperate. The Council of Elders has issued a call: \n";
    pause();
    cout << "brave souls willing to hunt the nightmares will be rewarded with coin, fame… and perhaps answers...\n";
    pause();
    cout << "\nIn a smoky tavern lit by flickering lanterns, you rise from your seat. You are no common traveler—you are a trained adventurer, \n";
    pause();
    cout << "forged by battle and bound by purpose.\n";
    pause();

    string playerName;
    cout << "\nWhat is your name, brave adventurer? ";
    getline(cin, playerName);

    cout << "\nWelcome, " << playerName << ". Your journey begins now...\n";
    pause(1500);

    // Initialize available enemies
    vector<Monster> enemies = Monster::getDefaultMonsters();

    // Initialize player class
    Player player = chooseClass(playerName);

    bool continueFighting = true;
    while (continueFighting) {
        displayEnemies(enemies);

        // Let the player choose an enemy to fight
        Monster enemy = chooseEnemy(enemies);
        waitForEnter();

        // Battle loop
        Battle battle(player, enemy);
        battle.start();
        

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
            cout << "\n" << playerName << "has retired from the adventuring life...\n";
        }
        if (choice == 2) {
            player.healPlayer(100);
        }
    }

    return 0;
}
