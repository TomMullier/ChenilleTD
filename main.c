#include <stdio.h>
#include "ConsoleTools.h"
#include <time.h>
#include <stdlib.h>
#include <wincontypes.h>
#include <Windows.h>
#include <stdbool.h>
#include "move.h"

#define TAILLE_FEUILLE 30
#define LENGTH 3



int main() {
    // Init snake array
    COORD snake[LENGTH];
    COORD temp;
    for (short int i = 0; i < LENGTH; i++)
    {
        temp.X = 13 + i;
        temp.Y = 10;
        snake[i] = temp;
    }

    // Set console
    openConsole();
    setBackGroundColor(15);
    setWriteColor(1);
    char tab[TAILLE_FEUILLE][TAILLE_FEUILLE];
    for (int i = 0; i < TAILLE_FEUILLE; i++)
    {
        for (int j = 0; j < TAILLE_FEUILLE; j++)
        {
            tab[i][j] = ' ';
            printf("%c", tab[i][j]);
        }
        if (i != 29)
        {
            printf("\n");
        }
    }
    remplissage();
    for (int i = 0; i < LENGTH; i++) {
        int x = snake[i].X;
        int y = snake[i].Y;
        moveCursor(x, y);
        plotChar(i == 0 ? 'X' : '0');
    }
    Sleep(1000);

    for (int i = 0; i < 10; i++)
    {
        direction(snake);
    }

    closeConsole();
    return EXIT_SUCCESS;
}