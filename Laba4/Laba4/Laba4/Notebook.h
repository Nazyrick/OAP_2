#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STRING_SIZE 20

struct Date {
	unsigned int day : 5;
	unsigned int month : 4;
	unsigned int year : 23;
};

union FullName
{
	char surname[STRING_SIZE];
	char name[STRING_SIZE];
	char patronymic[STRING_SIZE];
};

typedef struct {
	char surname[STRING_SIZE];
	char name[STRING_SIZE];
	char patronymic[STRING_SIZE];
	struct Date dateOfBirth;
	char address[STRING_SIZE];
	char phoneNumber[STRING_SIZE];
	char occupation[STRING_SIZE];
	char appointment[STRING_SIZE];
} Notebook;

bool notebookIsEmpty(const Notebook n[]);
void addToNotebook(Notebook** n);
void displayNotebook(const Notebook n[]);
void deleteFromNotebook(Notebook* n[], unsigned int index);
void findBySurname(const Notebook n[], const char surname[]);
void enterInfo(Notebook* n);
void printInfo(const Notebook* n);