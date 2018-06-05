#pragma once
#include "stdafx.h"
#include <stdio.h>
#include <fstream>
#include <istream>
#include <iostream>
#include <string>
#include "HelpUtils.h"
using namespace std;

// ввод числа в диапозоне
int input_number(int min, int max, string message)
{
	int n;
	bool flag = true;
	do
	{
		if (!flag)
			cout << "Число вне диапозона!!\n";
		else
			flag = !flag;
		cout << message;
		while ((!(cin >> n)) || cin.get() != '\n')
		{
			cout << "Неправильный ввод !!  Повторите ввод!\n";
			cin.clear();  // восстанавливает поток если он в ошибочном сосотянии
			cin.sync();   // очищает поток от имеющихся символов
			cout << message;
			getchar();
			getchar();
		}
	} while ((n < min) || (n > max));
	return n;
}

// ввод информации
string input_information(string messge)
{
	string a;
	cout << messge;
	cin >> a;
	return a;
}

// проверка символа на корректность в числе
bool correct_symbol(char c)
{
	switch (c)
	{
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case '0':
		return true;
	default:
		return false;
	}
}

// проверка номера на корректность 
bool correct_number(string s) {
	bool is_correct = true;
	for (int i = 0; ((i < s.length()) && (is_correct)); i++) {
		is_correct = correct_symbol(s[i]);
	}
	is_correct *= (s.length() < 9);
	return is_correct;
}

double inumber_to_double(double min, double max, string message)
{
	double n;
	bool flag = true;
	do
	{
		if (!flag)
			cout << "Число вне диапозона!!\n";
		else
			flag = !flag;
		cout << message;
		while ((!(cin >> n)) || cin.get() != '\n')
		{
			cout << "Неправильный ввод !!  Повторите ввод!\n";
			cin.clear();  // восстанавливает поток если он в ошибочном сосотянии
			cin.sync();   // очищает поток от имеющихся символов
			cout << message;
			getchar();
			getchar();
		}
		//cout << "Неправильный ввод !!  Повторите ввод!\n";
	} while ((n < min) || (n > max));
	return n;
}

// чтение строки из бинарного файла
string instring_binary(ifstream& in)
{
	string result;
	size_t len_name;
	in.read((char*)&len_name, sizeof(len_name)); // чтение длины записанной строки
	char * buf = new char[len_name];         // Выделение буфера для чтения
	in.read(buf, len_name);// Чтение 
	result = buf;                       // Присвоение считанной строки 
	delete[]buf;               // Освобождение памяти

	return result;
}

// запись строки в бинарный файл
void outstring_binary(ofstream& os, string str)
{
	size_t len_name = str.length() + 1;  // длина 
	os.write((char*)&len_name, sizeof(int)); // запись длины
	os.write(str.c_str(), len_name);  // запись информации
}

// проверка даты на корректность
bool correct_date(int day, int month, int year, string &message) {

	// количество дней в феврале
	if (month == 2 && day > 29  )
	{
		message = "Неверное кол-во дней в феврале!";
		return false;
	}
	//кол-во дней в месяце
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
		{
			message = "Неверное кол-во дней в месяце!";
			return false;
		}
	}
	return true;
}

string input_filename() {
	string filename;
	cout << "Введите имя файла\n";
	char *ch;
	do {
		cin >> ch;
		filename += ch;
	} while (ch == "\n");

	if ((filename == "") || (filename.find(" ") == -1))
		throw "Невозможно открыть файл! Проверьте введённые данные.";

	return filename;
}
