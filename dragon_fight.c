#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
/* a program that simulates a fight with a dragon. You pick a character, you have moves, you take turns
and attack based on chance and you either win the fight or lose the fight*/
//global variables
//For the character classes and their moves
char fighter[10] = "Fighter";
char mage[10] = "Mage";
char thief[10] = "Thief";
char playerCharacter[10];
char fighterMoves[4][25] = {"Sword Strike", "Shield Bash", "Pommel Hit", "Sword and Shield Combo"};
char mageMoves[4][25] = {"Fireball", "Lightning Bolt", "Cold Blast", "Stormbringer"};
char thiefMoves[4][25] = {"Dagger Stab", "Arrow Strike", "Poisoned Blade", "Shadow Attack"};
char playerMoves[4][25];
char dragonMoves[4][25] = {"Dragon Claw", "Flames", "Tail Swipe", "Chomp"};
// Health of player and dragon
int playerHealth = 15;
int dragonHealth = 20;
char winner = 'N';
// Function prototypes
void chooseCharacter(); //fighter, mage, or thief
void playerMove();
void dragonMove();
void endGameText();
//Code
int main() {
    printf("Welcome to the Dragon Fight!\n");
    printf("You are a brave adventurer going to fight an evil dragon!\n");
    printf("But first, you must choose your character!");
    chooseCharacter();
    printf("You chose to be a %s\n", playerCharacter);
    printf("You come across the dragon's lair!\nHe doesn't notice you, for now.\n");
    while (winner = 'N') { 
        playerMove();
        printf("---------------\n");
        dragonMove();
        printf("---------------\n");
        printf("The dragon is at %d health\n", dragonHealth);
        printf("You are at %d health\n", playerHealth);
        printf("---------------\n");
        if (dragonHealth <= 0) {
            winner = 'P';
            printf("You are a dragonslayer!\n");
            break;
        } else if (playerHealth <= 0) {
            winner = 'D';
            printf("You are dragon food!\n");
            break;
        }
    }
    printf("The winner is %c\n", winner);
    printf("THank you for playing!\n");
    return 0;
}
void chooseCharacter() {
    int playerPick;
    printf("Do you want to be:\n1: Fighter\n2: Mage\n3: Thief\n");
    scanf("%d", &playerPick);
     while (playerPick != 1 || playerPick != 2 || playerPick != 3) {
        if (playerPick == 1 || playerPick == 2 || playerPick == 3) {
            break;
        }
        else {
            printf("Invalid pick, you dunce. Try again:\n");
            printf("Do you want to be:\n1: Fighter\n2: Mage\n3: Thief\n");
            scanf("%d", &playerPick);
        }
    }
    if (playerPick == 1) {
        strcpy(playerCharacter, fighter);
        for (int i = 0; i < 4; i++) {
            strcpy(playerMoves[i], fighterMoves[i]);
        }
    }
    else if (playerPick == 2) {
        strcpy(playerCharacter, mage);
        for (int i = 0; i < 4; i++) {
            strcpy(playerMoves[i], mageMoves[i]);
        }
    }
    else if (playerPick == 3) {
        strcpy(playerCharacter, thief);
        for (int i = 0; i < 4; i++) {
            strcpy(playerMoves[i], thiefMoves[i]);
        }
    }
}
void playerMove() {
    srand(time(0));
    int move;
    printf("What do you want to do?\n");
    for (int i = 0; i < 4; i++) {
        printf("%d : %s\n", i+1, playerMoves[i]);
    }
    scanf("%d", &move);
    while (move != 1 || move != 2 || move != 3 || move != 4) {
        if (move == 1 || move == 2 || move == 3 || move == 4) {
            break;
        }
        else {
            printf("Invalid pick, you dunce. Try again:\n");
            scanf("%d", &move);
        }
    }
    if (move == 1) {
        int attack = rand() % 15;
        if (attack > 7) {
            printf("Success!\n");
            dragonHealth = dragonHealth - 2;
        } else {
            printf("You missed!\n");
        }
    }
    else if (move == 2) {
       int attack = rand() % 17;
        if (attack > 8) {
            printf("Success!\n");
            dragonHealth = dragonHealth - 5;
        } else {
            printf("You missed!\n");
        }
    }
    else if (move == 3) {
        int attack = rand() % 19;
        if (attack > 9) {
            printf("Success!\n");
            dragonHealth = dragonHealth - 10;
        } else {
            printf("You missed!\n");
        }
    }
    else if (move == 4) {
        int attack = rand() % 21;
        if (attack > 10) {
            printf("Success!\n");
            dragonHealth = dragonHealth - 15;
        } else {
            printf("You missed!\n");
        }
    }
}
void dragonMove() {
    srand(time(0));
    printf("It is the dragon's turn!\n");
    int move = rand() % 4;
    printf("The dragon uses its %s attack!\n", dragonMoves[move]);
    if (dragonMoves[move] == dragonMoves[0]) {
        int attack = rand() % 10;
        if (attack > 5) {
            printf("It hits you!\n");
            playerHealth = playerHealth - 1;
        } else {
            printf("You dodge it!\n");
        }
    } else if (dragonMoves[move] == dragonMoves[1]) {
        int attack = rand() % 11;
        if (attack > 6) {
            printf("It hits you!\n");
            playerHealth = playerHealth - 2;
        } else {
            printf("You dodge it!\n");
        }
    } else if (dragonMoves[move] == dragonMoves[2]) {
        int attack = rand() % 12;
        if (attack > 6) {
            printf("It hits you!\n");
            playerHealth = playerHealth - 3;
        } else {
            printf("You dodge it!\n");
        }
    } else if (dragonMoves[move] == dragonMoves[3]) {
        int attack = rand() % 13;
        if (attack > 6) {
            printf("It hits you!\n");
            playerHealth = playerHealth - 4;
        } else {
            printf("You dodge it!\n");
        }
    }
}
