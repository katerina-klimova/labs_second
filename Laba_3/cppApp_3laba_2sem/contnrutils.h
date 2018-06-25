#pragma once
#include "abonent.h"

bool string_from_bin(ifstream& in,string &str);
void string_to_bin(ofstream& os, string str);
bool load_one(ifstream& in, abonent &abon);

abonent input_abonent();
void print_v(vector<abonent> &v);
bool contains(vector<abonent> v, int n);
void load_binary(vector<abonent> &v);
void save_file(vector<abonent> &v);
void save_binary(vector<abonent> &v);
void export_vect(vector<abonent> &v);

void add_v(vector<abonent> &v);
void delete_v(vector<abonent> &v);
void exchange_v(vector<abonent> &v);
vector<abonent> search(vector<abonent> &v);

