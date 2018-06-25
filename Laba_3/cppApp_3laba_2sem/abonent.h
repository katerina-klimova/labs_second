#pragma once

#include "abonutils.h"

class abonent
{
private:
	string name;
	string district;
	adress address;
	string phone;
	int contract_number;
	date contract_date;
	int cost_install;
	int abonent_cost;
	date date_last_pay;
public:
	//name
	string get_name();
	void set_name(string n);
	//district
	string get_district();
	void set_district(string d);
	//address
	string get_address();
	void set_address(adress a);
	//phone
	string get_phone();
	void set_phone(string p);
	//number of the contract
	int get_contract_number();
	void set_contract_number(int num);
	//date of contract
	date get_contract_date();
	void set_contract_date(date d);
	//install cost
	int get_cost_install();
	void set_cost_install(int c);
	//abonent cost
	int get_abonent_cost();
	void set_abonent_cost(int c);
	//date of the las pay
	date get_date_last_pay();
	void set_date_last_pay(date d);


	abonent();
	abonent(string name, string district, adress address, string phone, int contract_number, date contract_date, int cost_install, int abonent_cost, date date_last_pay);
	~abonent();

	void print_record();
	
};

//компораторы
 bool name_rec_comp( abonent &r,  abonent &b);
 bool name_comp( abonent& r, string value);
 bool district_rec_comp( abonent& r,  abonent &b);
 bool district_comp( abonent &r, string value);
 bool datecontr_rec_comp( abonent &r,  abonent &b);
 bool datecontr_comp( abonent &r, date value);
 bool datelp_rec_comp( abonent &r,  abonent &b);
 bool datelp_comp( abonent &r, date value);
//возвр равенство
bool equals_name(abonent & a, string strquery);
bool equals_district(abonent & a, string strquery);
bool equals_contr(abonent & a, date datequery);
bool equals_lp(abonent & a, date datequery);
