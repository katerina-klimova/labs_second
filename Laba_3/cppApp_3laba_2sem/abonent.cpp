#include "stdafx.h"
#include "abonent.h"


//name
string abonent::get_name(){
	return name;
}
void abonent::set_name(string n){
	if (n == "") throw "Имя не должно быть пустым:\n";
	name = n;
}
//district
string abonent::get_district(){
	return district;
}
void abonent::set_district(string d){
	if (d == "") throw "Район не должен быть пустым:\n";
	district = d;
}
//address
string abonent::get_address(){
	return address_to_str(address);
}
void abonent::set_address(adress a){
	if (a.street == "") throw "Адрес не должен быть пустым:\n";
	if (a.house < 1) throw "Значение дома должно быть положительным:\n";
	if (a.flat<0) throw "Значение квартиры должно быть неотрицательным:\n";
	address = a;
}
//phone
string abonent::get_phone(){
	return phone;
}
void abonent::set_phone(string p){
	if (p == "") throw "Телефон не должен быть пустым:\n";
	if (!correct_phone(p)) throw "Номер не соответсвует:\n";
	phone = p;
}
//number of the contract
int abonent::get_contract_number(){
	return contract_number;
}
void abonent::set_contract_number(int num){
	if (num < 1) throw "Номер должен быть положительным:\n";
	contract_number = num;
}
//date of contract
date abonent::get_contract_date(){
	return contract_date;
}
void abonent::set_contract_date(date d){
	if (!(correct_date(d))) throw "Дата должна быть соответствующей:\n";
	contract_date = d;
}
//install cost
int abonent::get_cost_install(){
	return cost_install;
}
void abonent::set_cost_install(int c){
	if (c < 1) throw "Стоимость должна быть положительной:\n";
	cost_install = c;
}
//abonent cost
int abonent::get_abonent_cost(){
	return abonent_cost;
}
void abonent::set_abonent_cost(int c){
	if (c < 1) throw "Стоимость должна быть положительной:\n";
	abonent_cost = c;
}
//date of the las pay
date abonent::get_date_last_pay(){
	return date_last_pay;
}
void abonent::set_date_last_pay(date d){
	if (!(correct_date(d))) throw "Дата должна быть соответствующей:\n";
	date_last_pay = d;
}


abonent::abonent(){
	date *d = new date();
	adress *a = new adress();
	a->street = "";
	a->house = 0;
	a->flat = 0;
	d->day = 0;
	d->month = 0;
	d->year = 0;
	name = "";
	district = "";
	phone = "";
	contract_number = 0;
	contract_date = *d;
	cost_install = 0;
	abonent_cost = 0;
	date_last_pay = *d;
}
abonent::abonent(string Aname, string Adistrict, adress Address, string Aphone, 
				int Acontract_number, date Acontract_date, int Acost_install, int Aabonent_cost, date Adate_last_pay){
	set_name(Aname);
	set_district(Adistrict);
	set_address(Address);
	set_phone(Aphone);
	set_contract_number(Acontract_number);
	set_contract_date(Acontract_date);
	set_cost_install(Acost_install);
	set_abonent_cost(Aabonent_cost);
	set_date_last_pay(Adate_last_pay);
}
abonent::~abonent(){}

void abonent::print_record(){
	cout << contract_number << "\t" << name << "\t" << district << "\t" << address_to_str(address) << "\t"
		<< phone << "\t" << cost_install << "\t" << abonent_cost << "\t\t" << date_to_str(contract_date)
		<< "\t\t" << date_to_str(date_last_pay) << endl;
}

//компараторы
 bool name_rec_comp(abonent &r, abonent &b)
{
	return r.get_name() < b.get_name();

}
 bool name_comp( abonent &r, string value)
{
	return (r.get_name() < value);
}
 bool district_rec_comp( abonent &r,  abonent &b)
{
	return r.get_district() < b.get_district();

}
 bool district_comp( abonent &r, string value)
{
	return (r.get_district() < value);
}
 bool datecontr_rec_comp( abonent &r,  abonent &b)
{
	return (r.get_contract_date().year < b.get_contract_date().year) ||
		((r.get_contract_date().year == b.get_contract_date().year) && (r.get_contract_date().month < b.get_contract_date().month)) ||
		((r.get_contract_date().year == b.get_contract_date().year) && (r.get_contract_date().month == b.get_contract_date().month) && 
		(r.get_contract_date().day < b.get_contract_date().day));
}
 bool datecontr_comp(abonent &r, date value)
{
	return (r.get_contract_date().year < value.year) ||
		((r.get_contract_date().year == value.year) && (r.get_contract_date().month < value.month)) ||
		((r.get_contract_date().year == value.year) && (r.get_contract_date().month == value.month) && 
		(r.get_contract_date().day < value.day));

}
 bool datelp_rec_comp( abonent &r,  abonent &b)
{
	return (r.get_date_last_pay().year < b.get_date_last_pay().year) ||
		((r.get_date_last_pay().year == b.get_date_last_pay().year) && (r.get_date_last_pay().month < b.get_date_last_pay().month)) ||
		((r.get_date_last_pay().year == b.get_date_last_pay().year) && (r.get_date_last_pay().month == b.get_date_last_pay().month) && 
		(r.get_date_last_pay().day < b.get_date_last_pay().day));

}
 bool datelp_comp(abonent &r, date value)
{
	return (r.get_date_last_pay().year < value.year) ||
		((r.get_date_last_pay().year == value.year) && (r.get_date_last_pay().month < value.month)) ||
		((r.get_date_last_pay().year == value.year) && (r.get_date_last_pay().month == value.month) && 
		(r.get_date_last_pay().day < value.day));

}

//возвр раенство
bool equals_name( abonent & a, string strquery) {
	if (a.get_name() == strquery) return true;
	return false;
}

bool equals_district( abonent & a, string strquery) {
	if (a.get_district() == strquery) return true;
	return false;
}

bool equals_contr( abonent & a, date datequery) {
	if (a.get_contract_date().day == datequery.day &&
		a.get_contract_date().month == datequery.month &&
		a.get_contract_date().year == datequery.year)
		return true;
	return false;
}

bool equals_lp( abonent & a, date datequery) {
	if (a.get_date_last_pay().day == datequery.day &&
		a.get_date_last_pay().month == datequery.month &&
		a.get_date_last_pay().year == datequery.year)
		return true;
	return false;
}