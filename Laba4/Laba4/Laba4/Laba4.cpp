#include "Notebook.h"
#include <string.h>
#include "Notebook.h"

int objectCount = 0;

bool notebookIsEmpty(const Notebook n[]) {
	if (!objectCount) {
		printf_s("\nNotebook is empty\n");
		return true;
	}
	return false;
}

void addToNotebook(Notebook** n) {
	objectCount++;
	*n = (Notebook*)realloc(*n, objectCount * sizeof(Notebook));

	if (*n == NULL) {
		printf_s("Memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	enterInfo(*n + (objectCount - 1));
}

void displayNotebook(const Notebook n[]) {
	if (notebookIsEmpty(n))
		return;

	for (int i = 0; i < objectCount; ++i)
		printInfo(&n[i]);
}

void deleteFromNotebook(Notebook* n[], unsigned int index) {
	if (notebookIsEmpty(*n))
		return;

	if (!index) {
		free(*n);
		objectCount = 0;
		*n = NULL;
		printf_s("\nAll items deleted\n");
		return;
	}

	for (int i = index - 1; i < objectCount - 1; ++i)
		*(*n + i) = *(*n + i + 1);

	objectCount--;
	*n = (Notebook*)realloc(*n, objectCount * sizeof(Notebook));
	printf_s("\nItem deleted\n");

	if (!objectCount)
		*n = NULL;
}

void findBySurname(const Notebook n[], const char surname[]) {
	if (notebookIsEmpty(n))
		return;

	for (int i = 0; i < objectCount; ++i)
		if (!_stricmp(n[i].surname, surname)) {
			printf_s("Found person\n");
			printInfo(&n[i]);
			return;
		}

	printf_s("\nNo such person\n");
}

void enterInfo(Notebook* n) {
	union FullName fio;
	char buff[STRING_SIZE];
	printf_s("Enter surname: ");
	fgets(fio.surname, STRING_SIZE, stdin);
	strcpy_s(n->surname, STRING_SIZE, fio.surname);
	printf_s("Enter name: ");
	fgets(fio.name, STRING_SIZE, stdin);
	strcpy_s(n->name, STRING_SIZE, fio.name);
	printf_s("Enter patronymic: ");
	fgets(fio.patronymic, STRING_SIZE, stdin);
	strcpy_s(n->patronymic, STRING_SIZE, fio.patronymic);

	printf_s("Enter day: ");
	fgets(buff, STRING_SIZE, stdin);
	n->dateOfBirth.day = strtoul(buff, NULL, 10);
	printf_s("Enter month: ");
	fgets(buff, STRING_SIZE, stdin);
	n->dateOfBirth.month = strtoul(buff, NULL, 10);
	printf_s("Enter year: ");
	fgets(buff, STRING_SIZE, stdin);
	n->dateOfBirth.year = strtoul(buff, NULL, 10);

	printf_s("Enter address: ");
	fgets(n->address, STRING_SIZE, stdin);
	printf_s("Enter phone number: ");
	fgets(n->phoneNumber, STRING_SIZE, stdin);
	printf_s("Enter occupation: ");
	fgets(n->occupation, STRING_SIZE, stdin);
	printf_s("Enter appointment: ");
	fgets(n->appointment, STRING_SIZE, stdin);
}

void printInfo(const Notebook* n) {
	printf_s("Surname: %s", n->surname);
	printf_s("Name: %s", n->name);
	printf_s("Patronymic: %s", n->patronymic);
	printf_s("Date of birth: %02d:%02d:%d\n", n->dateOfBirth.day, n->dateOfBirth.month, n->dateOfBirth.year);
	printf_s("Address: %s", n->address);
	printf_s("Phone number: %s", n->phoneNumber);
	printf_s("Occupation: %s", n->occupation);
	printf_s("Appointment: %s", n->appointment);
}