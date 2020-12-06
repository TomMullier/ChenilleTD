#include <stdio.h>
#include "ConsoleTools.h"
#include <time.h>
#include <stdlib.h>
#include <wincontypes.h>
#include <Windows.h>
#include <stdbool.h>
#include "move.h"
#include <locale.h>

// Console size
#define TAILLE_FEUILLE_X 30
#define TAILLE_FEUILLE_Y 30
// Snake size

#define LENGTH_MAX 15
// Snake speed
#define SPEEDSNAKE 10

char tab[TAILLE_FEUILLE_X][TAILLE_FEUILLE_Y];

int main() {
    setlocale(LC_ALL, "fr-FR");
    //Menu Chnage Difficulty
    int choice;
    int choice2;
    do
    {
        system("cls");
        printf("================================\n");
        printf("==LONGUEUR INITIALE DU SERPENT==\n");
        printf("================================\n");
        printf("\n");
        printf("1. 5  Caractères\n");
        printf("2. 7  Caractères\n");
        printf("3. 9  Caractères\n");
        printf("4. 11 Caractères\n");
        printf("5. 13 Caractères\n");
        printf("6. 15 Caractères\n");
        printf("\n");
        printf("Choix : ");
        scanf_s("%d", &choice);
        switch (choice)
        {
        case 1:
            #define LENGTH_MIN 5
            break;
        case 2:
            #define LENGTH_MIN 7
            break;
        case 3:
            #define LENGTH_MIN 9
            break;
        case 4:
            #define LENGTH_MIN 11
            break;
        case 5:
            #define LENGTH_MIN 13
            break;
        case 6:
            #define LENGTH_MIN 15
            break;
        default:
            printf("Vous avez entré un mauvais nombre... Veuillez recommencer");
            Sleep(1000);
            break;
        }
        
    } while (choice<1 || choice>6);

    do
    {
        system("cls");
        printf("================================\n");
        printf("===NOMBRE DE POMMES A TROUVER===\n");
        printf("================================\n");
        printf("\n");
        printf("1. 5  Pommes\n");
        printf("2. 7  Pommes\n");
        printf("3. 9  Pommes\n");
        printf("4. 11 Pommes\n");
        printf("5. 13 Pommes\n");
        printf("6. 15 Pommes\n");
        printf("\n");
        printf("Choix : ");
        scanf_s("%d", &choice2);
        switch (choice2)
        {
        case 1:
            #define LENGTH_MAX (LENGTH_MIN+5)
            break;
        case 2:
            #define LENGTH_MAX (LENGTH_MIN+7)
            break;
        case 3:
            #define LENGTH_MAX (LENGTH_MIN+9)
            break;
        case 4:
            #define LENGTH_MAX (LENGTH_MIN+11)
            break;
        case 5:
            #define LENGTH_MAX (LENGTH_MIN+13)
            break;
        case 6:
            #define LENGTH_MAX (LENGTH_MIN+15)
            break;
        default:
            printf("Vous avez entré un mauvais nombre... Veuillez recommencer");
            Sleep(1000);
            break;
        }
    } while (choice2 < 1 || choice2>6);
    system("cls");
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD numberRead;

    // Init snake
    Snake snake;
    snake.direction = 'O';
    snake.length = LENGTH_MIN;
    // Init snake coordinates
    for (short int i = 0; i < snake.length; i++) {
        COORD temp;
        temp.X = 13 + i;
        temp.Y = 10;
        snake.coordinates[i] = temp;
    }

    // Set console
    openConsole();
    setBackGroundColor(15);
    hideCursor();
    setWriteColor(1);
    for (int i = 0; i < TAILLE_FEUILLE_X; i++) {
        for (int j = 0; j < TAILLE_FEUILLE_Y; j++) {
            tab[i][j] = ' ';
            printf("%c", tab[i][j]);
        }
        if (i != 29) printf("\n");
    }
    // Set '@'
    int applenb = LENGTH_MAX - LENGTH_MIN;
    for (int i = 0; i < applenb; i++) {
        moveCursor(rangedRand(0, 30), rangedRand(0, 30));
        setWriteColor(4);
        plotChar('@');
        setWriteColor(1);
    }
    moveCursor(29, 29);
    printf(" ");
    // Show snake
    for (int i = 0; i < snake.length; i++) {
        int x = snake.coordinates[i].X;
        int y = snake.coordinates[i].Y;
        moveCursor(x, y);
        plotChar(i == 0 ? 'X' : '0');
    }
    Sleep(1000);

    int keep_direction = rangedRand(1, 10);
    while (snake.length < LENGTH_MAX) {
        if (keep_direction == 0) {
            // Change direction
            snake.direction = getRandomDirection(snake.direction);
            keep_direction = rangedRand(1, 10);
        }
        // Get new coordinates
        COORD destination = getDestination(snake.coordinates[0], snake.direction);
        if (destination.X != TAILLE_FEUILLE_X && destination.Y != TAILLE_FEUILLE_Y && destination.X >= 0 && destination.Y >= 0) {
            char dest_char;
            bool increase_length = false;
            ReadConsoleOutputCharacter(hOut, &dest_char, 1, destination, &numberRead);
            if (dest_char == '@') {
                snake.length++;
                increase_length = true;
            } else increase_length = false;
            // Move snake
            moveTo(&snake, destination, !increase_length);
            keep_direction--;
        } else keep_direction = 0; // Forcing a change of destination
        moveCursor(40, 15);
        setBackGroundColor(0);
        setWriteColor(15);
        hideCursor();
        printf("Il vous reste %2d pomme(s) à manger !", applenb - (snake.length - LENGTH_MIN));
        setWriteColor(1);
        setBackGroundColor(15);
        Sleep(SPEEDSNAKE);
    }
    moveCursor(40, 17);
    setBackGroundColor(0);
    setWriteColor(2);
    printf("Félicitations ! Vous avez gagné... juste mon respect :)");
    setWriteColor(1);
    setBackGroundColor(15);
    Sleep(100000);
    closeConsole();
    return EXIT_SUCCESS;
}
