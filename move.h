typedef struct SNAKE Snake;
struct SNAKE {
	char direction;
	int length;
	COORD coordinates[];
};

void logSnake(COORD a[], int size);
void moveTo(Snake* snake, COORD head);
/*
void direction(COORD* snake);
void goUp(COORD* snake);
void goDown(COORD* snake);
void goRight(COORD* snake);
void goLeft(COORD* snake);

// Random Fruits
void remplissage() {
	for (int i = 0; i < 9; i++)
	{
		moveCursor(rangedRand(0, 30), rangedRand(0, 30));
		plotChar('@');
	}
	moveCursor(29, 29);
	printf(" ");
}

void updateSnake(COORD* snake, COORD head) {
	COORD to_erase;
	to_erase.X = snake[LENGTH - 1].X;
	to_erase.Y = snake[LENGTH - 1].Y;
	for (int i = LENGTH - 1; i >= 0; i--) {
		snake[i] = (i != 0) ? snake[i - 1] : head;
	}
	// Remove the snake queue
	moveCursor(to_erase.X, to_erase.Y);
	plotChar(' ');
	// Update snake into the console
	for (int i = LENGTH - 1; i >= 0; i--) {
		int x = snake[i].X;
		int y = snake[i].Y;
		moveCursor(x, y);
		plotChar(i == 0 ? 'X' : '0');
	}
}

void direction(COORD* snake) {
	int tempnumber = rangedRand(1, 5);
	switch (tempnumber)
	{
	case 1:
		goUp(snake);
		break;
	case 2:
		goRight(snake);
		break;
	case 3:
		goDown(snake);
		break;
	case 4:
		goLeft(snake);
		break;
	default:
		direction(snake);
		break;
	}
}

void goUp(COORD* snake) {
	COORD new_head;
	new_head.X = snake[0].X;
	new_head.Y = snake[0].Y - 1;
	updateSnake(snake, new_head);
	Sleep(500);
	hideCursor();
}
void goRight(COORD* snake) {
	COORD new_head;
	new_head.X = snake[0].X + 1;
	new_head.Y = snake[0].Y;
	updateSnake(snake, new_head);
	Sleep(500);
	hideCursor();
}
void goDown(COORD* snake) {
	COORD new_head;
	new_head.X = snake[0].X;
	new_head.Y = snake[0].Y + 1;
	updateSnake(snake, new_head);
	Sleep(500);
	hideCursor();
}
void goLeft(COORD* snake) {
	COORD new_head;
	new_head.X = snake[0].X - 1;
	new_head.Y = snake[0].Y;
	updateSnake(snake, new_head);
	Sleep(500);
	hideCursor();
	
}*/