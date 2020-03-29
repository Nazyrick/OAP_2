// Скопировать из файла F1 в файл F2 все строки, в которых есть слова,
// совпадающие с первым словом.
// Определить количество согласных букв в последней строке файла F2.

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	/*ifstream in("f1.txt");
	ofstream out("f2.txt");
	string line, firstWord, word ;
	while (getline(in, line))
	{
		stringstream ss(line);
		bool hasEquals = false;
		ss >> firstWord;
		while (ss >> word)
		{
			if (word == firstWord)
			{
				hasEquals = true;
				break;
			}
		}
		if (hasEquals) out << line << endl;
	}
	string consonants("bcdfghjklmnpqrstvwxz");
	int consCount = 0;
	for (auto it = line.begin(); it != line.end(); it++)
		if (consonants.find(*it) != string::npos)
			consCount++;
	cout << "Количество согласных букв: " << consCount;
	in.close();
	out.close();
	return 0;*/
	

	char a[255];
	char simvol;
	int j = 0;
	cout << "Введите стороку" << endl;
	cin >> a ;
	ofstream out("number2.txt");
	out << a;
	out.close();
	ifstream in("number2.txt");
	in >> a;
	in.close();
	cout << "Введите искомый символ: ";
	cin >> simvol;
	for (int i = 0; a[i] != '\0'; i++)
	{
		if (a[i] == simvol)
		{
			j++;
		}
	}
	cout << "Символ " << simvol << " встречается " << j << " раз." << endl;
	
	return 0;
	
}

