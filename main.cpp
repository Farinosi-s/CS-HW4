/*
Homework 4
--------------
Name: Stephen Farinosi
Date: 04/24/25
Section: CS 121-02
--------------
This program is a text RPG adventure game where the player takes on various boss enemies, each with unique abilities. 
The player gets to choose from five different classes which each have their own set of four abilities. The player then
chooses which boss they'd like to fight. There is an ally in the game, but they are only offered as an option after the first 
loop in the game. After the selections, turn based combat commences like final fantasy or pokemon. The player can choose which
ability to use, the boss and ally's are chosen at random. There is a readout to the player explaining how much damage, healing,
and/or which stats have changed. After all parties have gone, there is a readout of the current stats for the player and boss. 
This continues until one or the other is dead. After which, the player receives a boss specific drop and the current inventory is
displayed. The game then ask the player if they want to continue with or without healing, continue with an Ally, or end the game. 

As far as the coding goes, the Player, Monster, and Ally classes are all derived from the Creature class, which inherits from the Abilities class. 
The Battle class inherents from the Monster, Ally, and Player classes, and handles the main combat loop. Added after the main started getting busy.
The main RPG loop is still in the main.cpp, including the selecting of the player class. The other required elements include a 2D array used
to represent the inventory of the player. Within it is one of the three composition classes, "InventorySlot", in the player file. The other
two being the Effects class within Abilities, and then the abilities class which gets put inside a vector in the creature class. The only conent 
used outside of of what we have been using in class was mostly vector stuff, which the teacher said was fine to use. It was fun getting to 
learn more about classes, vectors, and how they worked for this assignment. It was very instructive practice. Thanks for playing our game!


Written with Dacota Fabisinski-Hale.
--------------
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "Abilities.h"
#include "Monster.h"
#include "Player.h"
#include "Battle.h"

using namespace std;
                                                                    //function prototypes
void delay(int ms = 4000);                                          //default delay set to 4000
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
    cout << "entire fields are found burnt to a crisp, and there are claws marks that rip through stone. The people are desperate. The Council of Elders has issued a call: \n";
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
    Ally* ally = nullptr;

    Player player = chooseClass(playerName);                                    // Initializes player and let them choose their class
    delay(1000);

    bool continueFighting = true;                                               // Main loop for until the player chooses to fully exit
    while (continueFighting) {
        displayEnemies(enemies);

        Monster enemy = chooseEnemy(enemies);                                   // Lets the player choose an enemy to fight, initializing an enemy object of monster class
        waitForEnter();

        Battle battle(player, enemy, ally);                                           // Calls the Battle class and passes in the player and enemy object
        battle.start();
        cout << "\n ";
        player.displayInventory();

        cout << "\nHow would you like to proceed?\n";                          // After battle, asks player if they want to continue or quit
        cout << "1. Press the attack, continue fighting!\n";
        cout << "2. Return to camp and heal before setting out again\n";
        cout << "3. Heal and return with an ally to assist you in battle!\n";
        cout << "4. Quit the game\n";
        int choice;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 4) {                                                     //quit option
            continueFighting = false;
            cout << "\n" << playerName << " has retired from the adventuring life...\n";
        }
        if (choice == 3) {                                                     //Option to heal + get an Ally. Dragons are tough
            player.healPlayer(100);
            if (ally) delete ally;                                             //So there's only one Ally
            ally = new Ally(Ally::getDefaultAlly());
        }     
        if (choice == 2) {                                                     //full heal before continuing
            player.healPlayer(100);
        }
    }

    return 0;
}

void delay(int ms) {
    usleep(ms * 700);                        // Used to create tension in dramatic elements
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
            break;                                                                  //Input is valid, move on to switch statements
        } else {
            cin.clear();                                                            //Clear error
            cin.ignore(1000, '\n');                                                 //Discard invalid input
            cout << "Invalid input. Please enter a number between 1 and 5.\n";
        }
    }

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
