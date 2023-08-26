#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void choice_for_menu(double a, double b, char d);
void choice_for_main_menu(int choice);
void menu();
void read();

void main_menu() {
	int choice;
	do {
		cout << "1 - добавить новое действие " << endl
			<< "2 - посмотреть все действия " << endl
			<< "3 - выход" << endl;
		cin >> choice;
		choice_for_main_menu(choice);
	} while (choice != 3);
}

void choice_for_main_menu(int choice) {
	switch (choice) {
	case 1:
		menu();
		break;
	case 2:
		read();
		break;
	case 3:
		cout << "выход... " << endl;
		break;
	default:
		cout << "Выбрана неверная цифра!" << endl;
	}
}

void menu() {
	double a, b, result;
	char d;
	cout << "Введите первое число: " << endl;
	cin >> a;
	cout << "Введите действие: " << endl;
	cin >> d;
	cout << "Введите второе число" << endl;
	cin >> b;
	choice_for_menu(a, b, d);
}


void choice_for_menu(double a, double b, char d) {
	ofstream f;
	double result;
	switch (d) {
	case '+':
		result = a + b;
		cout << a << " + " << b << " = " << result << endl;
		f.open("dia.txt", ofstream::app);
		if (!f.is_open()) {
			cout << "Ошибка открытия файла " << endl;
		}
		else {
			f << a << " + " << b << " = " << endl;
		}
		f.close();
		f.open("result.txt", ofstream::app);
		if (!f.is_open()) {
			cout << "Ошибка открытия файла " << endl;
		}
		else {
			f << result << endl;
		}
		f.close();
		break;
	case '-':
		result = a - b;
		cout << a << " - " << b << " = " << result << endl;
		f.open("dia.txt", ofstream::app);
		if (!f.is_open()) {
			cout << "Ошибка открытия файла " << endl;
		}
		else {
			f << a << " - " << b << " = " << endl;
		}
		f.close();
		f.open("result.txt", ofstream::app);
		if (!f.is_open()) {
			cout << "Ошибка открытия файла " << endl;
		}
		else {
			f << result << endl;
		}
		f.close();
		break;
	case '/':
		result = a / b;
		cout << a << " / " << b << " = " << result << endl;
		f.open("dia.txt", ofstream::app);
		if (!f.is_open()) {
			cout << "Ошибка открытия файла " << endl;
		}
		else {
			f << a << " / " << b << " = " << endl;
		}
		f.close();
		f.open("result.txt", ofstream::app);
		if (!f.is_open()) {
			cout << "Ошибка открытия файла " << endl;
		}
		else {
			f << result << endl;
		}
		f.close();
		break;
	case '*':
		result = a * b;
		cout << a << " * " << b << " = " << result << endl;
		f.open("dia.txt", ofstream::app);
		if (!f.is_open()) {
			cout << "Ошибка открытия файла " << endl;
		}
		else {
			f << a << " * " << b << " = " << endl;
		}
		f.close();
		f.open("result.txt", ofstream::app);
		if (!f.is_open()) {
			cout << "Ошибка открытия файла " << endl;
		}
		else {
			f << result << endl;
		}
		f.close();
		break;
		cout << "неверное действие!" << endl;
	default:
		cout << "неверное действие!" << endl;
	}
}

void read() {
	ifstream fin;
	cout << "Действия: " << endl;
	fin.open("dia.txt");
	if (!fin.is_open()) {
		cout << "файл не найден " << endl;
		return;
	}
	else {
		char ch;
		while (fin.get(ch)) {
			cout << ch;
		}
	}
	fin.close();

	cout << "Результаты: " << endl;
	fin.open("result.txt");
	if (!fin.is_open()) {
		cout << "файл не найден " << endl;
		return;
	}
	else {
		char ch;
		while (fin.get(ch)) {
			cout << ch;
		}
	}
	fin.close();
}

int main()
{
	setlocale(LC_ALL, "ru");
	main_menu();
	
}
