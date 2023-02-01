#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROOM_STACK_SIZE 100

void showBaseCampOptions();
int getChoice();
void searchSurvivalGear();
void inspectTransformationSite();
void contactSupportTeam();
void secureContainmentRoom();
void engageCreature();
void takeCover();
void quit();
void showResearchOutpostOptions();
void goToLab();
void goToStorage();
void returnToBaseCamp();

int hasWeapon, isAlive;
int roomStack[MAX_ROOM_STACK_SIZE];
int roomStackTop = 0;

int main()
{
    int choice, currentRoom;
    char input[10];

    srand(time(NULL)); // Initialize random seed

    printf("Welcome to The Thing game!\n");
    printf("You are part of a research team in Antarctica\n");
    printf("Suddenly, things take a turn for the worse...\n");
    printf("One of your team members has transformed into a mysterious creature.\n");
    printf("You must make decisions to survive.\n");

    currentRoom = 1;
    hasWeapon = 0;
    isAlive = 1;

    while (isAlive)
    {
        switch (currentRoom)
        {
        case 1:
            showBaseCampOptions();
            choice = getChoice();
            roomStack[roomStackTop++] = currentRoom;
            currentRoom = choice;

            switch (choice)
            {
            case 1:
                searchSurvivalGear();
                currentRoom = 1;
                break;
            case 2:
                inspectTransformationSite();
                currentRoom = 2;
                break;
            case 3:
                contactSupportTeam();
                currentRoom = 1;
                break;
            case 4:
                secureContainmentRoom();
                isAlive = 0;
                break;
            case 5:
                engageCreature();
                currentRoom = 1;
                break;
            case 6:
                quit();
                isAlive = 0;
                break;
            default:
                printf("Invalid choice, please try again\n");
                currentRoom = roomStack[--roomStackTop];
                break;
            }
            break;
        case 2:
            showResearchOutpostOptions();
            choice = getChoice();

            roomStack[roomStackTop++] = currentRoom;
            currentRoom = choice;

            switch (choice)
            {
            case 1:
                goToLab();
                break;
            case 2:
                goToStorage();
                break;
            case 3:
                takeCover();
                currentRoom = 2;
                break;
            case 4:
                returnToBaseCamp();
                currentRoom = 1;
                break;
            default:
                printf("Invalid choice, please try again.\n");
                currentRoom = roomStack[--roomStackTop];
                break;
            }
            break;
        }
    }
    return 0;
}

void showBaseCampOptions()
{
    printf("\nBase Camp Options:\n");
    printf("1. Search for survival gear\n");
    printf("2. Inspect transformation site\n");
    printf("3. Contact support team\n");
    printf("4. Secure containment room\n");
    printf("5. Engage creature\n");
    printf("6. Quit\n");
    printf("\nEnter your choice: ");
}

int getChoice()
{
    int choice;
    scanf("%d", &choice);
    return choice;
}

void searchSurvivalGear()
{
    int found = rand() % 2;
    if (found)
    {
        printf("You have found some survival gear!\n");
        hasWeapon = 1;
    }
    else
    {
        printf("Sorry, no survival gear was found.\n");
    }
}

void inspectTransformationSite()
{
int discovered = rand() % 2;
if (discovered)
{
printf("You have discovered new information about the transformation!\n");
}
else
{
printf("Sorry, no new information was found.\n");
}
}

void contactSupportTeam()
{
int response = rand() % 2;
if (response)
{
printf("Support team has responded and is sending help!\n");
}
else
{
printf("No response from support team. You are on your own.\n");
}
}

void secureContainmentRoom()
{
printf("You have secured the containment room and are safe for now.\n");
printf("But the creature may still be out there...\n");
}

void engageCreature()
{
if (hasWeapon)
{
int success = rand() % 2;
if (success)
{
printf("You successfully engage the creature!\n");
printf("Congratulations, you have survived The Thing!\n");
isAlive = 0;
}
else
{
printf("Engaging the creature was a fatal mistake.\n");
printf("You have died. Game over.\n");
isAlive = 0;
}
}
else
{
printf("You need a weapon to engage the creature.\n");
printf("Try searching for survival gear first.\n");
}
}

void quit()
{
printf("You have chosen to quit the game.\n");
printf("Thanks for playing The Thing!\n");
}

void showResearchOutpostOptions()
{
printf("\nResearch Outpost Options:\n");
printf("1. Go to lab\n");
printf("2. Go to storage\n");
printf("3. Take cover\n");
printf("4. Return to base camp\n");
printf("\nEnter your choice: ");
}

void goToLab()
{
int found = rand() % 2;
if (found)
{
printf("You have found some useful information in the lab!\n");
}
else
{
printf("Sorry, the lab was empty.\n");
}
}

void goToStorage()
{
printf("You are now in the storage room.\n");
printf("You can search for weapons and other useful items.\n");
}

void returnToBaseCamp()
{
printf("You have returned to the base camp.\n");
}

void takeCover()
{
printf("You have taken cover from the creature.\n");
printf("Stay alert and be ready for any danger.\n");
}
