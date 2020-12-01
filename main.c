#include <stdio.h>
#include "ConsoleTools.h"
#include <time.h>
#include <stdlib.h>
#include <wincontypes.h>
#include <Windows.h>
#include <stdbool.h>
#include "move.h"

// Console size
#define TAILLE_FEUILLE_X 30
#define TAILLE_FEUILLE_Y 30
// Taille de la chenille
#define LENGTH_MIN 5
#define LENGTH_MAX 15

char tab[TAILLE_FEUILLE_X][TAILLE_FEUILLE_Y];

int main() {
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
    for (int i = 0; i < 9; i++) {
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

    COORD to;
    to.X = 13;
    to.Y = 11;
    moveTo(&snake, to);

    int keep_direction = rangedRand(1, 5);
    for (int i = 0; i < 40; i++) {
        if (keep_direction == 0) {
            // Change direction
            snake.direction = getRandomDirection(snake.direction);
            keep_direction = rangedRand(1, 5);
        }
        // Get new coordinates
        COORD destination = getDestination(snake.coordinates[0], snake.direction);
        if (destination.X != TAILLE_FEUILLE_X && destination.Y != TAILLE_FEUILLE_Y) {
            // Move snake
            moveTo(&snake, destination);
            keep_direction--;
        } else keep_direction = 0; // Forcing a change of destination
        Sleep(100);
    }

    Sleep(100000000000);
    closeConsole();
    return EXIT_SUCCESS;
}
