#pragma once
#include "stdafx.h"
#include <stdio.h>
#include <fstream>
#include <istream>
#include <iostream>
#include <string>
using namespace std;

// ввод числа в диапозоне (int)
int input_number(int min, int max, string message);

// ввод информации
string input_information(string messge);

// проверка символа на корректность в числе
bool correct_symbol(char c);

// проверка числа на корректность
bool correct_number(string s);

// ввод числа в диапозоне (double)
double inumber_to_double(double min, double max, string message);

// string из бинарного файла
string instring_binary(ifstream& in);

// string в бинарный файл
void outstring_binary(ofstream& os, string str);

// проверка даты на корректность
bool correct_date(int day, int month, int year, string &message);
string input_filename();