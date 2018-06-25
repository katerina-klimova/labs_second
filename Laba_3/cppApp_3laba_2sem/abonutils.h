#pragma once
#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <cstdlib>
#include "iostream"
#include <string>
using namespace std;
typedef struct date
{
	int day;
	int month;
	int year;
} date;

typedef struct adress
{
	string street;
	int house;
	int flat;
} address;

string date_to_str(date d);
date str_to_date(string str);
string address_to_str(adress d);
adress str_to_address(string str);
bool correct_symbol(char c);
bool correct_number(string s);
bool correct_date(date d);
date input_date();
adress input_address();
bool correct_phone(string s);


