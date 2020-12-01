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
        plotChar('@');
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

    /*while (snake.length < LENGTH_MAX) {

        Sleep(500);
    }*/

    Sleep(100000000000);
    closeConsole();
    return EXIT_SUCCESS;
}

void moveTo(Snake* snake, COORD head) {
    COORD to_erase;
    to_erase.X = snake->coordinates[snake->length - 1].X;
    to_erase.Y = snake->coordinates[snake->length - 1].Y;
    for (int i = snake->length - 1; i >= 0; i--) {
        snake->coordinates[i] = (i != 0) ? snake->coordinates[i - 1] : head;
    }
    // Remove the snake queue
    moveCursor(to_erase.X, to_erase.Y);
    plotChar(' ');
    // Update the snake head
    moveCursor(snake->coordinates[0].X, snake->coordinates[0].Y);
    plotChar('X');
    moveCursor(snake->coordinates[1].X, snake->coordinates[1].Y);
    plotChar('0');
}

void logSnake(COORD a[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d: %d;%d\n", i, a[i].X, a[i].Y);
    }
}