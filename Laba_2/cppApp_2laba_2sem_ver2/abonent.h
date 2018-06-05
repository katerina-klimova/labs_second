#pragma once
#include "stdafx.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <cstdlib>
#include "iostream"
#include "HelpUtils.h"
using namespace std;
typedef struct date
{
	int day;
	int month;
	int year;
} date;
class abonent
{
public:
	string name;
	string district;
	string address;
	string phone;
	int contract_number;
	date contract_date;
	int cost_install;
	int abonent_cost;
	date date_last_pay;
	abonent();
	abonent(string name, string district, string address, string phone, int contract_number, date contract_date, int cost_install, int abonent_cost, date date_last_pay);
	~abonent();

	void print_record();
	
	
};
abonent input_abonent();

//компораторы
static bool name_rec_comp(const abonent &r, const abonent &b);
static bool name_comp(const abonent& r, string value);
static bool district_rec_comp(const abonent& r, const abonent &b);
static bool district_comp(const abonent &r, string value);
static bool datecontr_rec_comp(const abonent &r, const abonent &b);
static bool datecontr_comp(const abonent &r, date value);
static bool datelp_rec_comp(const abonent &r, const abonent &b);
static bool datelp_comp(const abonent &r, date value);

void load_file(vector<abonent> &v);
void print_v(vector<abonent> &v);
bool contains(vector<abonent> v,int n);
void add_v(vector<abonent> &v);
void delete_v(vector<abonent> &v);
void exchange_v(vector<abonent> &v);
void save_file(vector<abonent> &v);
void save_binary(vector<abonent> &v);
vector<abonent> search(vector<abonent> &v);

