#include "stdafx.h"
#include "abonent.h"


abonent::abonent()
{
	date *d = new date();
	d->day = 0;
	d->month = 0;
	d->year = 0;
	name = "";
	district = "";
	address = "";
	phone = "";
	contract_number = 0;
	contract_date = *d;
	cost_install = 0;
	abonent_cost = 0;
	date_last_pay = *d;
}

abonent::abonent(string Aname, string Adistrict, string Aaddress, string Aphone, int Acontract_number, date Acontract_date, int Acost_install, int Aabonent_cost, date Adate_last_pay)
{
	name = Aname;
	district = Adistrict;
	address = Aaddress;
	phone = Aphone;
	contract_number = Acontract_number;
	contract_date = Acontract_date;
	cost_install = Acost_install;
	abonent_cost = Aabonent_cost;
	date_last_pay = Adate_last_pay;
}

abonent::~abonent()
{
	
}

// ввод даты с консоли
date input_date()
{
	date d;
	bool is_correct_date = true; // корректна ли введенная дата
	string message = "";  // сообщение о причине ошибки
	do
	{
		if (!is_correct_date)
			cout << message << endl;
		d.day = input_number(1, 31, "Ввод даты:\nВведите день: ");
		d.month = input_number(1, 12, "Введите месяц : ");
		d.year = input_number(1970, 2018, "Введите год : ");
		is_correct_date = correct_date(d.day, d.month, d.year, message);
	} while (!correct_date);  // повторять ввод пока не корректная дата
	return d;
}

// перевод даты в строку (для последующей записи в файл)
string ToString(date d)
{
	return (to_string(d.day) + ' ' + to_string(d.month) + ' ' + to_string(d.year));
}

//печать 1 записи в консоль
void abonent::print_record()
{
	cout << contract_number << "\t" << name << "\t" << district << "\t" << address << "\t"
		<< phone << "\t" << cost_install << "\t" << abonent_cost << "\t\t" << contract_date.day
		<< "." << contract_date.month << "." << contract_date.year << "\t\t" << date_last_pay.day <<
		"." << date_last_pay.month << "." << date_last_pay.year << endl;
}

void load_file(vector<abonent> &vect) {
	vector<abonent>::iterator it = vect.begin();

	abonent abon;
	string filename = "second.txt";
	ifstream in;
	in.open(filename, ios::in);
	if (!in.is_open()) {
		throw "Не удалось открыть файл!\n";
	}
	if (in.eof()) {
		throw "Файл пуст!\n";
	}
	while (!in.eof())
	{
		in.read((char*)&it, sizeof(abonent));
		it++;
	}
	in.close();
}

void load_binary(vector<abonent> &vect) {
	abonent abon;
	string filename = "twelw";
	ifstream in(filename, ios::binary);
	in.open(filename, ios::in);

	if (!in.is_open()) {
		throw "Не удалось открыть файл!\n";
	}
	if (in.eof()) {
		throw "Файл пуст!\n";
	}
	else {
		while (!in.eof())
		{
			abonent *abon = new abonent();//!
			in.read((char*)&abon, sizeof(abonent));
			vect.insert(vect.end(),*abon);
		}
	}
}

void print_v(vector<abonent> &v) {
	cout << "Номер\tФамилия\tРайон\tАдрес\tТелефон\tОплата\tАбонплата\tДата договора\tДата последнего платежа" << endl;
	for (vector<abonent>::iterator it = v.begin(); it != v.end(); it++) (*it).print_record();
}

bool contains(vector<abonent> v,int n) {
	for (vector<abonent>::iterator it = v.begin(); it != v.end(); it++) {
		if ((*it).contract_number == n) return true;
	}
	return false;
}
abonent input_abonent() {
	string tmp_name;
	string tmp_district;
	string tmp_address;
	string tmp_phone;
	int tmp_contract_number;
	date tmp_contract_date;
	int tmp_cost_install;
	int tmp_abonent_cost;
	date tmp_date_last_pay;

	cout << "\nВведите номер: ";
	cin >> tmp_contract_number;
	if (tmp_contract_number < 1) throw "Неверный номер!\n";

	cout << "\nВведите фамилию: ";
	cin >> tmp_name;
	if (tmp_name == "") throw "Имя не должно быть пустым!\n";

	cout << "\nВведите район: ";
	cin >> tmp_district;
	if (tmp_district == "") throw "Район не должен быть пустым!\n";

	cout << "\nВведите адрес: ";
	getline(cin, tmp_address);
	if (tmp_address == "") throw "Адрес не должен быть пустым!\n";

	cout << "\nВведите оплату установки: ";
	cin >> tmp_cost_install;
	if (tmp_cost_install<1) throw "Оплата установки должна быть положительным числом!\n";

	cout << "\nВведите абонентскую плату: ";
	cin >> tmp_abonent_cost;
	if (tmp_abonent_cost<1) throw "Абоненская плата должна быть положительным числом!\n";

	cout << "\nВведите дату договора (день, месяц и год через пробел): ";
	cin >> tmp_contract_date.day >> tmp_contract_date.month >> tmp_contract_date.year;
	if ((tmp_contract_date.day<1)||(tmp_contract_date.day>31) ||
		(tmp_contract_date.month<1) || (tmp_contract_date.month>12) ||
		(tmp_contract_date.year<1980) || (tmp_contract_date.year>2018) )
			throw "Неверный ввод даты договора!\n";

	cout << "\nВведите дату последнего платежа (день, месяц и год через пробел): ";
	cin >> tmp_date_last_pay.day >> tmp_date_last_pay.month >> tmp_date_last_pay.year;
	if ((tmp_date_last_pay.day<1) || (tmp_date_last_pay.day>31) ||
		(tmp_date_last_pay.month<1) || (tmp_date_last_pay.month>12) ||
		(tmp_date_last_pay.year<1980) || (tmp_date_last_pay.year>2018))
		throw "Неверный ввод даты последнего платежа!\n";

	abonent a(tmp_name, tmp_district, tmp_address, tmp_phone, tmp_contract_number,
		tmp_contract_date, tmp_cost_install, tmp_abonent_cost, tmp_date_last_pay);
	return a;
}
void add_v(vector<abonent> &v) {
	abonent a = input_abonent();
	if (contains(v, a.contract_number)) throw "Абонент с таким номером уже зарегистрирован.\n";
	
	v.insert(v.end(), a);
	cout << "Запись добавлена!" << endl;
}

void delete_v(vector<abonent> &v) {
	int i;
	cout << "Введите номер договора абонента, которого надо удалить: ";
	cin >> i;
	if (i < 0) throw "Номер должен быть положительным\n";
	if (!contains(v, i)) throw "Такого номера нет!\n";

	vector<abonent>::iterator it = v.begin();
	while ((*it).contract_number != i && it != v.end()) it++;
	v.erase(it);
	cout << "Договор удалён!" << endl; 
}

void exchange_v(vector<abonent> &v) {
	int i;
	cout << "Введите номер договора абонента, данные о котором надо заменить: ";
	cin >> i;
	if (i < 0) throw "Номер должен быть положительным\n";
	if (!contains(v, i)) throw "Такого номера нет!\n";

	vector<abonent>::iterator it = v.begin();
	while ((*it).contract_number != i && it != v.end()) it++;

	string tmp_string;
	date tmp_date;

	int choise;
	cout << "1 - Заменить номер договора\n";
	cout << "2 - Заменить имя\n";
	cout << "3 - Заменить район\n";
	cout << "4 - Заменить адрес\n";
	cout << "5 - Заменить номер телефона\n";
	cout << "6 - Заменить дату контракта\n";
	cout << "7 - Заменить стоимость установки\n";
	cout << "8 - Заменить абоненскую плату\n";
	cout << "9 - Заменить дату последнего платежа\n";
	cin >> choise;
	cout << "Введите новые данные:\n";
	switch (choise) {
	case '1': {
		cin >> tmp_string;
		if (correct_number(tmp_string)) (*it).contract_number = stoi(tmp_string);
		else cout << "Неверные данные";
		}
		break;
	case '2':
		cin >> (*it).name;
		break;
	case '3':
		cin >> (*it).district;
		break;
	case '4':
		cin >> (*it).address;
		break;
	case '5':
		cin >> (*it).phone;
		break;
	case '6':
		(*it).contract_date = input_date();
		break;
	case '7': {
		cin >> tmp_string;
		if (correct_number(tmp_string)) (*it).cost_install = stoi(tmp_string);
		else cout << "Неверные данные"; }
		break;
	case '8': {
		cin >> tmp_string;
		if (correct_number(tmp_string)) (*it).abonent_cost = stoi(tmp_string);
		else cout << "Неверные данные"; }
		break;
	case '9': {
		(*it).date_last_pay = input_date(); 
		}
		break;
	default:
		cout << "\nНеверный ввод, введите число от 0 до 9\n";
	}
}

void save_binary(vector<abonent> &v) {
	string filename="twelw";
	ofstream out(filename, ios::binary);
	for each (abonent abon in v)
	{
		out.write((char*)&abon,sizeof(abonent));
	}
	out.close();
}

void save_file(vector<abonent> &v) {
	string filename = "first.txt";
	ofstream file;
	file.open(filename, ios::out);
	for (vector<abonent>::iterator it = v.begin(); it != v.end(); it++)
	{
		file << (*it).contract_number << "\t" << (*it).name << "\t" << (*it).district << "\t" << (*it).address << "\t"
			<< (*it).phone << "\t" << (*it).cost_install << "\t" << (*it).abonent_cost << "\t\t" << (*it).contract_date.day
			<< "." << (*it).contract_date.month << "." << (*it).contract_date.year << "\t\t" << (*it).date_last_pay.day <<
			"." << (*it).date_last_pay.month << "." << (*it).date_last_pay.year << endl;
	}
}
//компараторы
static bool name_rec_comp(const abonent &r, const abonent &b)
{
	return r.name < b.name;

}
static bool name_comp(const abonent &r, string value)
{
	return (r.name < value);
}
static bool district_rec_comp(const abonent &r, const abonent &b)
{
	return r.district < b.district;

}
static bool district_comp(const abonent &r, string value)
{
	return (r.district < value);
}
static bool datecontr_rec_comp(const abonent &r, const abonent &b)
{
	return (r.contract_date.year < b.contract_date.year) ||
		((r.contract_date.year == b.contract_date.year) && (r.contract_date.month < b.contract_date.month)) ||
		((r.contract_date.year == b.contract_date.year) && (r.contract_date.month == b.contract_date.month) && (r.contract_date.day < b.contract_date.day));
}
static bool datecontr_comp(const abonent &r, date value)
{
	return (r.contract_date.year < value.year) ||
		((r.contract_date.year == value.year) && (r.contract_date.month < value.month)) ||
		((r.contract_date.year == value.year) && (r.contract_date.month == value.month) && (r.contract_date.day < value.day));

}
static bool datelp_rec_comp(const abonent &r, const abonent &b)
{
	return (r.date_last_pay.year < b.date_last_pay.year) ||
		((r.date_last_pay.year == b.date_last_pay.year) && (r.date_last_pay.month < b.date_last_pay.month)) ||
		((r.date_last_pay.year == b.date_last_pay.year) && (r.date_last_pay.month == b.date_last_pay.month) && (r.date_last_pay.day < b.date_last_pay.day));

}
static bool datelp_comp(const abonent &r, date value)
{
	return (r.date_last_pay.year < value.year) ||
		((r.date_last_pay.year == value.year) && (r.date_last_pay.month < value.month)) ||
		((r.date_last_pay.year == value.year) && (r.date_last_pay.month == value.month) && (r.date_last_pay.day < value.day));

}

//возвр раенство
bool equals_name(const abonent & a, string strquery) {
	if (a.name == strquery) return true;
	return false;
}

bool equals_district(const abonent & a, string strquery) {
	if (a.district == strquery) return true;
	return false;
}

bool equals_contr(const abonent & a , date datequery) {
	if (a.contract_date.day == datequery.day &&
		a.contract_date.month == datequery.month &&
		a.contract_date.year == datequery.year)
		return true;
	return false;
}

bool equals_lp(const abonent & a, date datequery) {
	if (a.date_last_pay.day == datequery.day &&
		a.date_last_pay.month == datequery.month &&
		a.date_last_pay.year == datequery.year)
		return true;
	return false;
}

vector<abonent> posl_str(vector<abonent> &v, bool(*equals)(const abonent &, string)) {
	vector<abonent> results;
	vector<abonent>::iterator v_it = v.begin();
	string strquery;
	cin >> strquery;

		while (v_it != v.end())
		{
			if (equals(*v_it,strquery)) results.insert(results.end(), *v_it);
			v_it++;
		}
	return results;
}

vector<abonent> posl_date(vector<abonent> &v, bool(*equals)(const abonent &, date)) {
	vector<abonent> results;
	vector<abonent>::iterator v_it = v.begin();
	cout << "День месяц и год через пробел";
	date datequery;
	cin >> datequery.day >> datequery.month >> datequery.year;

		while (v_it != v.end())
		{
			if(equals(*v_it ,datequery ))
				results.insert(results.end(), *v_it);
			v_it++;
		}
	return results;
}

vector<abonent> bin_str(vector<abonent> &v, bool(*comparator_rec)(const abonent &, const abonent &),
	bool(*comparator)(const abonent &, string), bool(*equals)(const abonent &, string)) {
	vector<abonent> results;
	vector<abonent>::iterator v_it = v.begin();
	string strquery;
	cin >> strquery;
		sort(v.begin(), v.end(), comparator_rec);
		v_it = lower_bound(v.begin(), v.end(), strquery, comparator);
		while (equals(*v_it, strquery)) { 
			results.insert(results.end(), *v_it); 
			v_it++;
		}
	return results;
}

vector<abonent> bin_date(vector<abonent> &v, bool(*comparator_rec)(const abonent &, const abonent &),
	bool(*comparator)(const abonent &, date), bool(*equals)(const abonent &, date)) {
	vector<abonent> results;
	vector<abonent>::iterator v_it = v.begin();
	cout << "День месяц и год через пробел";
	date datequery;
	cin >> datequery.day >> datequery.month >> datequery.year;

		sort(v.begin(), v.end(), comparator_rec);
		v_it = lower_bound(v.begin(), v.end(), datequery, comparator);
		while (equals(*v_it,datequery))
		{
			results.insert(results.end(), *v_it);
			v_it++;
		}

	return results;
}

vector<abonent> search(vector<abonent> &v) {
	vector<abonent> results;
	vector<abonent>::iterator v_it = v.begin();
	int choise, type;
	do
	{
		cout << "Выберите критерий поиска:\n1.Фамилия\n2.Район\n3.Дата заключения договора\n4.Дата последнего платежа\n";
		cin >> choise;
	} while (choise<1 || choise>4);
	do
	{
		cout << "Выберите алгоритм поиска:\n1.Последовательный\n2.Двоичный\n";
		cin >> type;
	} while (type<1 || type>2);
	cout << "Введите запрос:";
	switch (type)
	{
	case 1:
	{
		switch (choise)
		{
			case 1 :
				results = posl_str(v, equals_name);
			break;
			case 2:
				results = posl_str(v, equals_district);
			break;
			case 3:
				results = posl_date(v, equals_contr);
			break;
			case 4:
				results = posl_date(v, equals_lp);
			break;
		}
	} break;

	case 2:
	{
		switch (choise)
		{
		case 1:
			results = bin_str(v, name_rec_comp,name_comp,equals_name);
		 break;
		case 2:
			results = bin_str(v, district_rec_comp,district_comp,equals_district); 
		 break;
		case 3:
			results = bin_date(v, datecontr_rec_comp, datecontr_comp,equals_contr); 
		 break;
		case 4:
			results = bin_date(v, datelp_rec_comp,datelp_comp,equals_lp); 
		 break;
		}
	} break;
	}
	return results;
}