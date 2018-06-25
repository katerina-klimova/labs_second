// cppApp_3laba_2sem.cpp: ���������� ����� ����� ��� ����������� ����������.
/*����������� ������ ���� ���������� ��������� � ��������� ����. ���������
������ ��������� ��������� ����� ��� ���������� ������� �������� �������.
��� �������� ������ ���������� ������� ����������� � ����� ������ �������
���������.
1. ������������� �������� ����������, ��������� � �������� ��������
����������.
2. ����������� ���� � ����� ��������� ���������� � �������������� ���������
���������� �� ����� � � ����.
3. ����������� �������� ������ �� �������� ��������� � ������� ������������
��������� �� �������� ���������.����������� ����� � ���� ��������� : ��������
����� � �������� ����� �� ��������������� ����������.
4. ������������� ����� ������������ ������� �� ����� � � ����.

������ ��������� ��������� ���� ������� �� �������� � ������ :
�������, �����, �����, �������, ����� ��������, ���� ���������� ��������,
������ ���������, ����������� ����� ���������, ���� ���������� �������.
����� �� �������, ������, ���� ���������� ��������, ���� ���������� �������
int 64*/

#include "stdafx.h"
#include "contnrutils.h"

int main()
{
	vector<abonent> vect;
	setlocale(LC_ALL, "Russian");
	load_binary(vect);
	print_v(vect);
	cout << "\n������ ���������!\n\n";
	int choise = -1;
	string print_choise;
	do {
		cout << "����:\n1.��������.\n2.����������\n3.�������\n4.��������\n5.�����\n0.�����.\n";
		cin >> print_choise;
		if (correct_number(print_choise))  choise = stoi(print_choise);
		switch (choise) {
		case 1:
			try {
				add_v(vect);
			}
			catch (char *s) {
				cout << s;
			}
			break;
		case 2:
		{export_vect(vect); }
			break;
		case 3:
			try {
				delete_v(vect);
			}
			catch (char *s) {
				cout << s;
			}
			break;
		case 4:
			try {
				exchange_v(vect);
			}
			catch (char *s) {
				cout << s;
			}
			break;
		case 5:
		{export_vect(search(vect)); }
			break;
		default:
			if (choise != 0) cout << "\n�������� ����, ������� ����� �� 0 �� 9\n";
		}
	} while (choise != 0);
	save_binary(vect);
		
	return 0;
}

