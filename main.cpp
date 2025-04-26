/*
Homework 4
--------------
Name: Stephen Farinosi
Date: 04/24/25
Section: CS 121-02
--------------
This program is a text RPG adventure game where the player takes on various boss enemies, each with unique abilities. 
The player gets to choose from five different classes which each have their own set of four abilities. Both the Player
and Monster classes are derived from the Creature class, which inherits from the Abilities class. --- Need to finish later


Written with Dacota Fabisinski-Hale.
--------------
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <unistd.h>
#include "Abilities.h"
#include "Monster.h"
#include "Player.h"
#include "Battle.h"

using namespace std;
                                                                    //function prototypes
void delay(int ms = 4000);                                          //default pause set to 4000
void waitForEnter();
void displayEnemies(const vector<Monster>& enemies);
Monster chooseEnemy(const vector<Monster>& enemies);
Player chooseClass(const string& playerName);


int main() {
    srand(time(0));                                                                                                         //For the random ability selection in monster
    cout << "\n";                                                                                                           //Text opener for the game
    cout << "\nThe sun sinks behind the Roshan Mountains, draping the village of Alethvar in shadows and fear...\n";
    delay();
    cout << "For weeks now, monsters not seen in a generation have stalked the edges of civilization— reports of eerie howls that echo through the night, \n";
    delay();
    cout << "entire fields are found burnt to a crisp, and there are claw marks that rip through stone. The people are desperate. The Council of Elders has issued a call: \n";
    delay();
    cout << "brave souls willing to hunt the nightmares will be rewarded with coin, fame… and perhaps answers...\n";
    delay();
    cout << "\nIn a smoky tavern lit by flickering lanterns, you rise from your seat. You are no common traveler— you are a trained adventurer, \n";
    delay();
    cout << "forged by battle and bound by purpose.\n";
    delay();

    string playerName;                                                                                                      
    cout << "\nWhat is your name, brave adventurer? ";
    getline(cin, playerName);                                                   //Gets player's Name

    cout << "\nWelcome, " << playerName << ". Your journey begins now...\n";
    delay(1500);

    vector<Monster> enemies = Monster::getDefaultMonsters();                    // Initializes available enemies

    Player player = chooseClass(playerName);                                    // Initializes player and let them choose their class
    delay(1000);

    bool continueFighting = true;                                               // Main loop for until the player chooses to fully exit
    while (continueFighting) {
        displayEnemies(enemies);

        Monster enemy = chooseEnemy(enemies);                                   // Lets the player choose an enemy to fight, initializing an enemy object of monster class
        waitForEnter();

        Battle battle(player, enemy);                                           // Calls the Battle class and passes in the player and enemy object
        battle.start();

        if (enemy.getHealth() <= 0) { //Added for inventory
            cout << "\nYou have defeated the " << enemy.getName() << "!\n";
            player.addItem(enemy.getDropId());
        }
        
        cout << "\nHow would you like to proceed?\n";                          // After battle, asks player if they want to continue or quit
        cout << "1. Press the attack, continue fighting!\n";
        cout << "2. Return to camp and heal before setting out again\n";
        cout << "3. Quit the game\n";
        int choice;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 3) {                                                     //quit option
            continueFighting = false;
            cout << "\n" << playerName << " has retired from the adventuring life...\n";
        }
        if (choice == 2) {                                                     //full heal before continuing
            player.healPlayer(100);
        }
    }

    return 0;
}

void delay(int ms) {
    usleep(ms * 1000);                        // Used to create tension in dramatic elements
}

void waitForEnter() {                                                       // Alternate pausing element, creates a sense of transition
    cout << "\n(Press Enter to continue...)\n";
    cin.ignore();
    cin.get();
}

void displayEnemies(const vector<Monster>& enemies) {                       // Function to display available enemies
    cout << "\nWhich quarry will you choose hunt?:\n";
    for (int i = 0; i < enemies.size(); ++i) {
        cout << i + 1 << ". " << enemies[i].getName() << "\n";
    }
}

Monster chooseEnemy(const vector<Monster>& enemies) {                       // Function to allow player to choose an enemy
    int choice;
    cout << "Choose your target's number: ";
    cin >> choice;

    if (!(cin >> choice) || choice < 1 || choice > enemies.size()) {                            //need to make it so that this is any choice that isn't a number between expected values
        cin.clear();              
        cin.ignore(1000, '\n');  
        cout << "Invalid choice, picking the first enemy.\n";
        choice = 1;
    }

    return enemies[choice - 1];
}

Player chooseClass(const string& playerName) {                              // Function to choose the player's class
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

    while (true) {
        cout << "Enter the item's number: ";
        if (cin >> choice && choice >= 1 && choice <= 5) {
            break; //Input is valid, move on to switch statements
        } else {
            cin.clear();              //Clear error
            cin.ignore(1000, '\n');   //Discard invalid input
            cout << "Invalid input. Please enter a number between 1 and 5.\n";
        }
    }
    
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

    return Player(playerName, 100, 100, 5, 5, abilities, type);             // Creates and returns a Player object after class selection
}
