#include "stdafx.h"
#include "abonutils.h"

bool correct_symbol(char c) {
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

bool correct_number(string s) {
	bool is_correct = true;
	for (size_t i = 0; ((i < s.length()) && (is_correct)); i++) {
		is_correct = correct_symbol(s[i]);
	}
	is_correct = is_correct&&(s.length() < 9);
	return is_correct;

}

string date_to_str(date d) {
	string result;
	result = to_string(d.day) + "." + to_string(d.month) + "." + to_string(d.year);
	return result;
}

bool correct_date(date d) {
	if ((d.day < 1) || (d.day > 31) || (d.month < 1) || (d.month > 12) || (d.year < 1800) || (d.year > 2018)) return false;
	return true;
}

date input_date() {
	date result;
	string tmp_str;
	cout << "Введите день:\n";
	cin >> tmp_str;
	if (correct_number(tmp_str)) result.day = stoi(tmp_str);
	else throw "Некорректная дата:\n";
	cout << "Введите месяц:\n";
	cin >> tmp_str;
	if (correct_number(tmp_str)) result.month = stoi(tmp_str);
	else throw "Некорректная дата:\n";
	cout << "Введите год:\n";
	cin >> tmp_str;
	if (correct_number(tmp_str)) result.year = stoi(tmp_str);
	else throw "Некорректная дата:\n";
	return result;
}
bool correct_phone(string s) {
	bool is_correct = true;
	for (size_t i = 0; ((i < s.length()) && (is_correct)); i++) {
		is_correct = correct_symbol(s[i]);
	}
	is_correct = is_correct && (s.length() > 8);
	return is_correct;
}

date str_to_date(string str) {
	date result;

	result.day = (int)(str[0]-'0');
	size_t i = 1;
	while (str[i] != '.') {
		result.day *= 10;
		result.day += (int)(str[i]-'0');
		i++;
	}
	i++;
	result.month = (int)(str[i] - '0');
	i++;
	while (str[i] != '.') {
		result.month *= 10;
		result.month += (int)(str[i] - '0');
		i++;
	}
	i++;
	result.year = (int)(str[i] - '0');
	i++;
	while (i < str.length()) {
		result.year *= 10;
		result.year += (int)(str[i] - '0');
		i++;
	}
	return result;
}

string address_to_str(adress a) {
	return (a.street + "_" + to_string(a.house) + "_" + to_string(a.flat));
}
adress str_to_address(string str) {
	adress result;
	result.street = "";
	size_t i = 0;
	do {
		result.street += str[i];
		i++;
	} while (str[i] != '_');
	i++;
	result.house = int(str[i] - '0');
	i++;
	while (str[i] != '_') {
		result.house *= 10;
		result.house += int(str[i] - '0');
		i++;
	}
	i++;
	result.flat = int(str[i] - '0');
	i++;
	while (i<str.length()) {
		result.flat *= 10;
		result.flat += int(str[i] - '0');
		i++;
	}
	return result;
}

adress input_address() {
	adress result;
	string tmp_str;
	cout << "Введите улицу:\n";
	cin >> result.street;
	cout << "Введите дом:\n";
	cin >> tmp_str;
	if (correct_number(tmp_str)) result.house = stoi(tmp_str);
	else throw "Некорректный ввод:\n";
	cout << "Введите квартиру (если квартира отсутсвует, введите 0):\n";
	cin >> tmp_str;
	if (correct_number(tmp_str)) result.flat = stoi(tmp_str);
	else throw "Некорректный ввод:\n";
	return result;
}