#pragma once
#include "stdafx.h"
#include <stdio.h>
#include <fstream>
#include <istream>
#include <iostream>
#include <string>
using namespace std;

// ���� ����� � ��������� (int)
int input_number(int min, int max, string message);

// ���� ����������
string input_information(string messge);

// �������� ������� �� ������������ � �����
bool correct_symbol(char c);

// �������� ����� �� ������������
bool correct_number(string s);

// ���� ����� � ��������� (double)
double inumber_to_double(double min, double max, string message);

// string �� ��������� �����
string instring_binary(ifstream& in);

// string � �������� ����
void outstring_binary(ofstream& os, string str);

// �������� ���� �� ������������
bool correct_date(int day, int month, int year, string &message);
string input_filename();