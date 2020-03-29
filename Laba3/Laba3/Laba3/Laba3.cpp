#include <iostream>
#include <fstream> 
#include <string>
#include <sstream>
using namespace std;

# define size 255  

void enter_new();
void out();

struct Country {
	char name_of_country[50];
	char capital_of_the_country[50];
	int how_many_people;
	int area;
	char surname_of_president[50];

};
struct Country list_of_country[size];
int choiсe; int current_size = 0;
int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Введите : " << endl;
	cout << "1 - для создания записи" << endl;
	cout << "2 - для вывода записи" << endl;
	cout << "3 - для выхода" << endl;
	cin >> choiсe;
	do {
		switch (choiсe)
		{
		case 1: enter_new();  break;
		case 2:  out();  break;
		}
	} while (choiсe != 3);
}
	void enter_new()
{
		cout << "Введите информацию : " << endl;
		cout << "Страна : " << endl; cin>> list_of_country[current_size].name_of_country;
		cout << "Столица : " << endl; cin >> list_of_country[current_size].capital_of_the_country;
		cout << "Численность населения : " << endl; cin >> list_of_country[current_size].how_many_people;
		cout << "Площадь : " << endl; cin >> list_of_country[current_size].area;
		cout << "Фамилия президента : " << endl; cin >> list_of_country[current_size].capital_of_the_country;
		ofstream out("number.txt");
		out << list_of_country[current_size].name_of_country;
		out << list_of_country[current_size].capital_of_the_country;
		out << list_of_country[current_size].how_many_people;
		out << list_of_country[current_size].area;
		out << list_of_country[current_size].capital_of_the_country;
		out.close();
}
	void out()
	{

	};

