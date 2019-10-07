#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#define FIELD_WIDTH 8
#define FIELD_HEIGHT 8
#define BLOCK_TYPE_MAX 7
enum {
	CELL_TYPE_NONE,
	CELL_TYPE_BLOCK_0,
	CELL_TYPE_BLOCK_1,
	CELL_TYPE_BLOCK_2,
	CELL_TYPE_BLOCK_3,
	CELL_TYPE_BLOCK_4,
	CELL_TYPE_BLOCK_5,
	CELL_TYPE_BLOCK_6,
	CELL_TYPE_MAX
	};

int cells[FIELD_HEIGHT][FIELD_WIDTH];
int selectedX, selectedY;

char cellAA[][2 + 1] = {
	"ÅE",//CELL_TYPE_BLOCK_0,
	"Åõ",//CELL_TYPE_BLOCK_1,
	"Å¢",//CELL_TYPE_BLOCK_1,
	"Å†",//CELL_TYPE_BLOCK_2,
	"Åú",//CELL_TYPE_BLOCK_3,
	"Å£",//CELL_TYPE_BLOCK_4,
	"Å°",//CELL_TYPE_BLOCK_5,
	"Åô",//CELL_TYPE_BLOCK_6,


};
int cursorX, cursorY;

int main() {
	srand((unsigned int)time(NULL));
	for (int y = 0; y < FIELD_HEIGHT; y++)
		for (int x = 0; x < FIELD_WIDTH; x++)
			cells[y][x] = CELL_TYPE_BLOCK_0 + rand() % BLOCK_TYPE_MAX;

	while (1) {
		system("cls");
		for (int y = 0; y < FIELD_HEIGHT; y++){
			for (int x = 0; x < FIELD_WIDTH; x++)
				if ((x == cursorX) && (y == cursorY))
					printf("Åù");
				else
					printf("%s",cellAA[cells[y][x]]);
			if (y == selectedY)
				printf("Å©");
			printf("\n");
		}
		for (int x = 0; x < FIELD_WIDTH; x++)
			printf("%s", (x == selectedX) ? "Å™" : "Å@");
		switch (_getch()) {

		case'w':cursorY--; break;
		case's':cursorY++; break;
		case'a':cursorX--; break;
		case'd':cursorX++; break;
		}

	}
}