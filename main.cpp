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

// Pause for dramatic effect
void pause(int ms = 1000) {
    this_thread::sleep_for(chrono::milliseconds(ms));
}

// Prompt for enter
void waitForEnter() {
    cout << "\n(Press Enter to continue...)\n";
    cin.ignore();
    cin.get();
}

// Class selection logic moved OUTSIDE main
Player chooseClass(const string& playerName) {
    vector<Abilities> all = Abilities::getAllAbilities();
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
                all[0],  // Slash
                all[11], // Rage
                all[12], // Iron Skin
                all[6]   // Earthquake
            };
            break;
        case 2:
            type = ClassType::Mage;
            abilities = {
                all[1],  // Fireball
                all[2],  // Lightning Bolt
                all[9],  // Greater Heal
                all[4]   // Shadow Claw
            };
            break;
        case 3:
            type = ClassType::Cleric;
            abilities = {
                all[8],  // Heal
                all[10], // Regenerate
                all[13], // Battle Cry
                all[16]  // Curse
            };
            break;
        case 4:
        default:
            type = ClassType::Rogue;
            abilities = {
                all[5],  // Piercing Arrow
                all[15], // Weaken
                all[18], // Mind Drain
                all[19]  // Armor Break
            };
            break;
    }

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

    // Get the player class and abilities
    Player player = chooseClass(playerName);

    // Set enemy abilities manually
    vector<Abilities> enemyAbilities = {
        Abilities("Poison Fang", AbilityType::Damage, 12),
        Abilities("Dark Claw", AbilityType::Damage, 18),
        Abilities("Scare", AbilityType::Debuff, 4, "attack")
    };

    Monster enemy("Nightfang", 80, 8, 4, enemyAbilities);

    cout << "\n" << playerName << " vs " << enemy.getName() << " begins!\n";
    waitForEnter();

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
            cout << "\n" << enemy.getName() << " has been defeated!\n";
            break;
        }

        int enemyChoice = rand() % enemy.getAbilityCount();
        enemy.useAbility(enemyChoice, player);
        waitForEnter();

        if (!player.isAlive()) {
            cout << "\n" << player.getName() << " has fallen... The light fades...\n";
        }
    }

    cout << "\n🏁 The battle is over.\n";
    cout << "Thanks for playing, " << playerName << "!\n";
    return 0;
}