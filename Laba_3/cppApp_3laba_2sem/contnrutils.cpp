#include "stdafx.h"
#include "contnrutils.h"

abonent input_abonent() {
	abonent result;

	string tmp_string;
	int tmp_int;

	cout << "\n������� �����:\n";
	cin >> tmp_string;
	if (!correct_number(tmp_string)) throw "����� ������ ���� ���������������:\n";
	else tmp_int = stoi(tmp_string);
	result.set_contract_number(tmp_int);

	cout << "\n������� �������: \n";
	cin >> tmp_string;
	result.set_name(tmp_string);

	cout << "\n������� �����: \n";
	cin >> tmp_string;
	result.set_district(tmp_string);

	result.set_address(input_address());

	cout << "\n������� ����� ��������: \n";
	cin >> tmp_string;
	result.set_phone(tmp_string);

	cout << "\n������� ������ ���������: \n";
	cin >> tmp_string;
	if (!correct_number(tmp_string)) throw "������ ������ ���� ���������������:\n";
	else tmp_int = stoi(tmp_string);
	result.set_cost_install(tmp_int);

	cout << "\n������� ����������� �����: \n";
	cin >> tmp_string;
	if (!correct_number(tmp_string)) throw "����� ������ ���� ���������������:\n";
	else tmp_int = stoi(tmp_string);
	result.set_abonent_cost(tmp_int);

	cout << "\n������� ���� �������: \n";
	result.set_contract_date(input_date());

	cout << "\n������� ���� ���������� �������: \n";
	result.set_date_last_pay(input_date());

	return result;
}

void print_v(vector<abonent> &v) {
	cout << "�����\t�������\t�����\t�����\t\t�������\t\t������\t���������\t���� ��������\t���� ���������� �������" << endl;
	for (vector<abonent>::iterator it = v.begin(); it != v.end(); it++) (*it).print_record();
}
bool contains(vector<abonent> v, int n) {
	for (vector<abonent>::iterator it = v.begin(); it != v.end(); it++) {
		if ((*it).get_contract_number() == n) return true;
	}
	return false;
}
void add_v(vector<abonent> &v) {
	bool is_correct=true;
	abonent a;
	try {
		a = input_abonent();
	}
	catch (char *s) {
		throw s;
	}
	// if (!is_correct) throw "������ �� �������������.\n";
	if (contains(v, a.get_contract_number())) throw "������� � ����� ������� ��� ���������������.\n";

	v.insert(v.end(), a);
	cout << "������ ���������!" << endl;
}
void delete_v(vector<abonent> &v) {
	int i;
	cout << "������� ����� �������� ��������, �������� ���� �������: ";
	cin >> i;
	if (i < 0) throw "����� ������ ���� �������������\n";
	if (!contains(v, i)) throw "������ ������ ���!\n";

	vector<abonent>::iterator it = v.begin();
	while ((*it).get_contract_number() != i && it != v.end()) it++;
	v.erase(it);
	cout << "������� �����!" << endl;
}
void exchange_v(vector<abonent> &v) {
	string tmp_string;
	int i;
	cout << "������� ����� �������� ��������, ������ � ������� ���� ��������: \n";
	cin >> tmp_string;
	/*try {
		cin >> i;
	}
	catch (exception& e) {
		throw e.what();
	}*/
	if (correct_number(tmp_string)) i = stoi(tmp_string);
	else throw "�������� ������\n";
	if (i < 0) throw "����� ������ ���� �������������\n";
	if (!contains(v, i)) throw "������ ������ ���!\n";

	vector<abonent>::iterator it = v.begin();
	while ((*it).get_contract_number() != i && it != v.end()) it++;

	
	int choise;
	cout << "1 - �������� ����� ��������\n";
	cout << "2 - �������� ���\n";
	cout << "3 - �������� �����\n";
	cout << "4 - �������� �����\n";
	cout << "5 - �������� ����� ��������\n";
	cout << "6 - �������� ���� ���������\n";
	cout << "7 - �������� ��������� ���������\n";
	cout << "8 - �������� ���������� �����\n";
	cout << "9 - �������� ���� ���������� �������\n";
	cin >> tmp_string;
	if (correct_number(tmp_string)) choise = stoi(tmp_string);
	else throw "�������� ����.\n";

	switch (choise) {
	case 1: {
		cout << "������� ����� ������:\n";
		int tmp_int;
		cin >> tmp_string;
		if (correct_number(tmp_string)) {
			tmp_int = stoi(tmp_string);
			if (!contains(v,tmp_int)) (*it).set_contract_number(tmp_int);
			else cout << "�������� �����! ������������ � ����� ������� ��� ���������������.\n";
		} 
		else cout << "�������� ������\n";
	}
	break;
	case 2:{
		cout << "������� ����� ������:\n";
		cin >> tmp_string;
		(*it).set_name(tmp_string);
	}
		
	break;
	case 3:{
		cout << "������� ����� ������:\n";
		cin >> tmp_string;
		(*it).set_district(tmp_string);
	}
		break;
	case 4:
	{
		(*it).set_address(input_address());
	}
		break;
	case 5: {
		cout << "������� ����� ������:\n";
		cin >> tmp_string;
		if (correct_number(tmp_string)) (*it).set_phone(tmp_string);
		else cout << "�������� ������";
	}
		break;
	case 6:
		(*it).set_contract_date(input_date());
		break;
	case 7: {
		cout << "������� ����� ������:\n";
		cin >> tmp_string;
		if (correct_number(tmp_string)) (*it).set_cost_install(stoi(tmp_string));
		else cout << "�������� ������\n"; }
			  break;
	case 8: {
		cout << "������� ����� ������:\n";
		cin >> tmp_string;
		if (correct_number(tmp_string)) (*it).set_abonent_cost(stoi(tmp_string));
		else cout << "�������� ������\n"; }
			  break;
	case 9: {
		(*it).set_date_last_pay(input_date());
	}
			  break;
	default:
		cout << "\n�������� ����, ������� ����� �� 0 �� 9\n";
	}
}
void export_vect(vector<abonent> &v) {
	string print_choise;
	if (v.empty()) cout << "�� ������ ������� ������ �� �������!\n";
	else {
		int choise;
		cout << "1.�� �����\n2.� ����\n";
		cin >> print_choise;
		if (!correct_number(print_choise)) throw "������ �������.\n";
		else choise=stoi(print_choise);
		switch (choise) {
		case 1:print_v(v);
			break;
		case 2:save_file(v);
			break;
		default: cout << "\n�������� ����\n";
		}
	}
	
}

// ������ ������ �� ��������� �����
bool string_from_bin(ifstream& in,string &str)
{
	size_t len;
	if (in.read((char *)(&len), sizeof(len))) {
		char * buf = new char[len];
		if (in.read((char *)(buf), len)) {
			str = buf;
			return true;
		}
	}
	return false;
}

// ������ ������ � �������� ����
void string_to_bin(ofstream& out, string str)
{
	size_t len = str.length() + 1;
	const char *buf = str.c_str();
	out.write((char *)(&len), sizeof(len));
	out.write((char *)(buf), len);
}
bool load_one(ifstream& in, abonent &abon) {
	//bool result = true;
	string tmp_str;
	if (string_from_bin(in, tmp_str)) abon.set_contract_number(stoi(tmp_str)); 
	else return false;
	if(string_from_bin(in, tmp_str)) abon.set_name(tmp_str);
	else return false;
	if (string_from_bin(in,tmp_str)) abon.set_district(tmp_str);
	else return false;
	if (string_from_bin(in, tmp_str)) abon.set_address(str_to_address(tmp_str));
	else return false;
	if (string_from_bin(in, tmp_str)) abon.set_phone(tmp_str);
	else return false;
	if (string_from_bin(in,tmp_str)) abon.set_contract_date(str_to_date(tmp_str));
	else return false;
	if (string_from_bin(in, tmp_str))
		abon.set_cost_install(stoi(tmp_str));
	else return false;
	if (string_from_bin(in, tmp_str)) abon.set_abonent_cost(stoi(tmp_str));
	else return false;
	if (string_from_bin(in, tmp_str)) abon.set_date_last_pay(str_to_date(tmp_str));
	else return false;
	return true;
}
void load_binary(vector<abonent> &v) {
	bool is_loaded=true;
	string filename = "twelw";
	ifstream in(filename, ios::binary);
	if (!in.is_open()) {
		throw "�� ������� ������� ����!\n";
	}
	if (in.eof()) {
		throw "���� ����!\n";
	}
	else {
		
		do{
			abonent abon;
			is_loaded = load_one(in, abon);
			if (is_loaded) v.push_back(abon);
		} while (is_loaded);
	}
}
void save_file(vector<abonent> &v) {
	string filename;
	cout << "������� ��� �����:\n";
	cin >> filename;
	if (filename == "") filename = "first.txt";
	ofstream file;
	file.open(filename, ios::out);
	for (vector<abonent>::iterator it = v.begin(); it != v.end(); it++)
	{
		file << (*it).get_contract_number() << "\t" << (*it).get_name() << "\t" << (*it).get_district() << "\t" << (*it).get_address() 
			<< "\t" << (*it).get_phone() << "\t" << (*it).get_cost_install() << "\t" << (*it).get_abonent_cost() << "\t\t" 
			<< date_to_str((*it).get_contract_date()) << "\t\t" << date_to_str((*it).get_date_last_pay())  << endl;
	}
}
void save_binary(vector<abonent> &v) {
	string filename = "twelw";
	ofstream out(filename, ios::binary);
	string tmp_str;
	for each (abonent abon in v)
	{
		string_to_bin(out, to_string(abon.get_contract_number()));
		string_to_bin(out, abon.get_name());
		string_to_bin(out, abon.get_district());
		string_to_bin(out, abon.get_address());
		string_to_bin(out, abon.get_phone());
		string_to_bin(out, date_to_str(abon.get_contract_date()));
		string_to_bin(out, to_string(abon.get_cost_install()));
		string_to_bin(out, to_string(abon.get_abonent_cost()));
		string_to_bin(out, date_to_str(abon.get_date_last_pay()));
	}
	out.close();
}

vector<abonent> posl_str(vector<abonent> &v, bool(*equals)(abonent &, string)) {
	vector<abonent> results;
	vector<abonent>::iterator v_it = v.begin();
	string strquery;
	cin >> strquery;

	while (v_it != v.end())
	{
		if (equals(*v_it, strquery)) results.insert(results.end(), *v_it);
		v_it++;
	}
	return results;
}

vector<abonent> posl_date(vector<abonent> &v, bool(*equals)(abonent &, date)) {
	vector<abonent> results;
	vector<abonent>::iterator v_it = v.begin();
	date datequery;
	datequery = input_date();

	while (v_it != v.end())
	{
		if (equals(*v_it, datequery))
			results.insert(results.end(), *v_it);
		v_it++;
	}
	return results;
}

vector<abonent> bin_str(vector<abonent> &v, bool(*comparator_rec)(abonent &, abonent &),
	bool(*comparator)( abonent &, string), bool(*equals)( abonent &, string)) {
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

vector<abonent> bin_date(vector<abonent> &v, bool(*comparator_rec)( abonent &,  abonent &),
	bool(*comparator)( abonent &, date), bool(*equals)( abonent &, date)) {
	vector<abonent> results;
	vector<abonent>::iterator v_it = v.begin();
	date datequery;
	datequery = input_date();

	sort(v.begin(), v.end(), comparator_rec);
	v_it = lower_bound(v.begin(), v.end(), datequery, comparator);
	while (equals(*v_it, datequery))
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
		cout << "�������� �������� ������:\n1.�������\n2.�����\n3.���� ���������� ��������\n4.���� ���������� �������\n";
		cin >> choise;
	} while (choise<1 || choise>4);
	do
	{
		cout << "�������� �������� ������:\n1.����������������\n2.��������\n";
		cin >> type;
	} while (type<1 || type>2);
	cout << "������� ������:\n";
	switch (type)
	{
	case 1:
	{
		switch (choise)
		{
		case 1:
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
			results = bin_str(v, name_rec_comp, name_comp, equals_name);
			break;
		case 2:
			results = bin_str(v, district_rec_comp, district_comp, equals_district);
			break;
		case 3:
			results = bin_date(v, datecontr_rec_comp, datecontr_comp, equals_contr);
			break;
		case 4:
			results = bin_date(v, datelp_rec_comp, datelp_comp, equals_lp);
			break;
		}
	} break;
	}
	return results;
}
