typedef struct SNAKE Snake;
struct SNAKE {
	char direction;
	int length;
	COORD coordinates[];
};

void logSnake(COORD a[], int size);
void moveTo(Snake* snake, COORD head);
char getRandomDirection(char last_direction);
COORD getDestination(COORD position, char direction);

void logSnake(COORD a[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d: %d;%d\n", i, a[i].X, a[i].Y);
	}
}


void moveTo(Snake* snake, COORD head) {
    hideCursor();
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

// Choose a random direction between (N)orth, (E)ast, (S)outh and (W)est
// Doesn't return the 'last_direction'
// Doesn't return the opposite of 'last_direction' to avoid backwards
// Example : getRandomDirection('N') doesn't return 'N' or 'S'
char getRandomDirection(char last_direction) {
    char r;
    char opposite;
    int nb = rangedRand(0, 4);
    switch (nb) {
    case 0:
        r = 'N';
        opposite = 'S';
        break;
    case 1:
        r = 'E';
        opposite = 'W';
        break;
    case 2:
        r = 'S';
        opposite = 'N';
        break;
    case 3:
        r = 'W';
        opposite = 'E';
        break;
    default:
        r = 'N';
        opposite = 'S';
        break;
    }
    if (r == last_direction || opposite == last_direction) r = getRandomDirection(last_direction);
    return r;
}

// Calcul the next coordinates with the chosen direction and the current position
COORD getDestination(COORD position, char direction) {
    COORD destination;
    hideCursor();
    switch (direction) {
    case 'N':
        destination.X = position.X;
        destination.Y = position.Y + 1;
        break;
    case 'E':
        destination.X = position.X + 1;
        destination.Y = position.Y;
        break;
    case 'S':
        destination.X = position.X;
        destination.Y = position.Y - 1;
        break;
    case 'W':
        destination.X = position.X - 1;
        destination.Y = position.Y;
        break;
    default:
        destination.X = position.X;
        destination.Y = position.Y + 1;
        break;
    }
    return destination;
}