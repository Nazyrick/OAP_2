#include "Notebook.h"
#include <conio.h>
#include<iostream>
enum Choice {
	ADD = 1, DISPLAY, DELETE, FIND, EXIT
};

extern int objectCount;

int getIntInput() {
	return _getch() - '0';
}

int main() {
	Notebook* notebookArray = NULL;

	int index, n;
	char buffer[STRING_SIZE];
	enum Choice choice;

	do {
		printf_s("\n-------------------------------------------------------\n");
		printf_s(" %d - add; %d - display; %d - delete; %d - find; %d - exit \n", ADD, DISPLAY, DELETE, FIND, EXIT);
		printf_s("-------------------------------------------------------\n");
		n = getIntInput();

		switch (n)
		{
		case ADD:
			addToNotebook(&notebookArray);
			break;
		case DISPLAY:
			displayNotebook(notebookArray);
			break;
		case DELETE:
			if (objectCount) {
				printf_s("Enter index (1 - %d) or 0 to delete all: ", objectCount);
				do {
					index = getIntInput();
				} while (index < 0);
				deleteFromNotebook(&notebookArray, index);
			}
			else
				printf_s("\nNo items to delete\n");
			break;
		case FIND:
			if (objectCount) {
				printf_s("Enter surname: ");
				fgets(buffer, STRING_SIZE, stdin);
				findBySurname(notebookArray, buffer);
			}
			else
				printf("\nNotebook is empty\n");
			break;
		default: break;
		}

	} while (n != EXIT);

	if (!objectCount)
		free(notebookArray);

	return 0;
}