// cppApp_laba1_2sem.cpp: ���������� ����� ����� ��� ����������� ����������.
/*�������� ���������, ���������� ��������� �������:
1. ������� ���������� ���������� ����� N ������ ���������� ������� �
��������� �� -M �� M. ��� �����, N � M ��������� �� ���� �������, ����
������������ �������� ��� ��������� (������������ ������ �����-������).
����������� ��� �������� ��������� ����� � � ����� � � ��������������
��������� std::generate.
2. �������, ���������� ���� �� ����, � ������������ ����������������
���������, ����������� ������� �� �����.
3. ������� modify, ����������� �������������� ����������� ����������. �� ����
������� ������ ��������� ���������, � �������� ���������� ������� ������
���������� ���������������� ���������.
4. ������������� ������� modify, ����������� �� ���� ��������� ������ � �����
�������������� ����� ����������.
5. �������, ����������� ��������� �������������� � �������������� ���������
std::transform ������ ������� modify.
6. �������, ����������� ��������� �������������� � �������������� ���������
std::for_each ������ ������� modify.
7. �������, ����������� ����� � ������� �������������� �����, ������������ �
����������.
8. ������� ������ ���������� � ���� � �� ����� (�����������).

��������������: �������� ��� ���� ������� �������������� �����.
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <deque>
#include <iterator>
using namespace std;


//���������� ����� ���������� N ������� � �����
fstream make_file_for(string filename, int count, int diapazone) {
	fstream file(filename, ios::out);
	if (!file.is_open())
	{
		throw "�� ������� ������� ����";
	}

	if (count < 1)
	{
		throw "���������� ��������� ������ ���� �������������";
	}

	if (diapazone < 1)
	{
		throw "����� � ������ ���� �������������";
	}

	for(int i=0;i<count;i++) 
	{
		file << ' ' << rand() % (diapazone * 2 + 1) - diapazone;
	}
	return file;
}

//���������� ����� ���������� N ������� ���������� generate
fstream make_file_generate(string filename, int count, int diapazone) {
	fstream file(filename, std::ios::out);
	if (!file.is_open())
	{
		throw "�� ������� ������� ����";
	}

	if (count< 1)
	{
		throw "���������� ��������� ������ ���� �������������";
	}

	if (diapazone < 1)
	{
		throw "����� � ������ ���� �������������";
	}

	deque<int> deq = deque<int>(count);
	generate(deq.begin(), deq.end(), [diapazone]() {return rand() % (diapazone * 2 + 1) - diapazone; });

	deque<int>::iterator iter = deq.begin();
	copy(deq.begin(),deq.end(), ostream_iterator<double>(file));

	return file;
}

//���������� ������������������ �� ����� � ������������ ����������
deque<double> make_contnr(string filename)
{
	
	ifstream file(filename);
	if (file.fail())
	{
		throw "�� ������� ������� ����";
	}
	deque<double> deq;
	copy(istream_iterator<double>(file), istream_iterator<double>(), back_inserter(deq));
	return deq;
}


//����� ���� ����� � ����������
double sum(deque<double>::iterator start, deque<double>::iterator end)
{
	deque<double> deq;

	deque<double>::iterator head = start;
	deque<double>::iterator tail = end;
	while (head != tail) {
		deq.push_back(*head);
		head++;
	}

	int res = 0;
	
	if (deq.empty())
	{
		throw "���������� ��������� �����: ��������� ����";
		
	}

	for each (double ex in deq)
	{
		res += ex;
	}
	return res;
}

//������� �������������� ���� ����� ����������
double average(deque<double>::iterator start, deque<double>::iterator end)
{
	if (start==end)
	{
		throw "���������� ��������� ������� ��������������: ��������� ����!";
	}
	return sum(start,end)/ (double)(end-start);
}

//��������� �������������� ����������
deque<double> modify(deque<double>::iterator start, deque<double>::iterator end) {
	//deque<double> part_deq(start,end);

	deque<double> deq;
	double ave = average(start,end);
	;
	for (deque<double>::iterator iter = start; iter != end;iter++) {
		(*iter == 0 ? deq.push_back(ave) : deq.push_back(*iter));
	}
	return deq;
}

//������ �������������� ����������
deque<double> modify(deque<double> &deq)
{
	return modify(deq.begin(),deq.end());
}

//�������������� ���������� ���������� transform
deque<double> transform_cntnr(deque<double> deq)
{
	deque<double> deqNew = deque<double>(deq.size());
	double ave = average(deqNew.begin(),deqNew.end());
	if (deq.size() == 0)
	{
		throw "��������� ����!";
	}
	transform(deq.begin(), deq.end(), deqNew.begin(), [ave](double value) { return((value == 0) ? ave : value); }); 
	return deqNew;
}

//�������������� � �������� ��������� for_each
deque<double> for_each_cntnr(deque<double> deq)
{
	if (deq.size() == 0)
	{
		throw "��������� ����!";
	}
	double ave = average(deq.begin(),deq.end());
	for_each(deq.begin(), deq.end(), [ave](double value) { return((value == 0) ? ave : value); });
	return deq;
}

//����� ���� ��������� �� �����
void print(deque<double> &deq)
{
	if (deq.empty())
	{
		throw "��������� ����!";
	}
	
		deque<double>::iterator iter = deq.begin();
		while(iter != deq.end())
		{
			cout << *iter << ' ';
			iter++;
		}
		cout << endl;
	
}

//����� ���� ��������� ���������� � ����
void print_file(string filename, deque<double> &deq)
{
	fstream file;
	file.open(filename, ios::out);
	if (!file.is_open())
	{
		throw "�� ������� ������� ����!";
	}
	
	if (deq.empty())
	{
		file << "��������� ����!" << endl;
	}
	else
	{
		deque<double>::iterator iter = deq.begin();
		while(iter!=deq.end())
		{
			file << *iter << ' ';
			iter++;
		}
		file << endl;
	}
}

//��������� ��������� �� �����
deque<double>::iterator get_iterator(deque<double> &deq, int n)
{
	if ((n < 1) || (n > deq.size() + 1))
	{
		throw "���������� ����� ������� � ������ �������";
	}
	deque<double>::iterator iter = deq.begin();
	for(int i=1;i<n;i++)
	{
		++iter;
	}
	return iter;
}

string filename;
int N, M;
fstream file;
deque<double> contnr;
deque<double>::iterator head, tail;


//���� ����� �����, �����, ���������
void input_filename(string &filename, int &N, int &M) {
	cout << "������� ��� �����" << endl;
	cin.clear();
	cin >> filename;
	cout << "������� ���������� ��������� �����" << endl;
	while (!(cin >> N))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "������� �����" << endl;
	}
	cout << "������� ������� ��������� ��������� ����� [-M; M]" << endl;
	while (!(cin >> M))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "������� �����" << endl;
	}
}

//���� ��������� ����������� ����������
void input_diapazone(int &N, int &M) {
	cout << "������� ������ �� ������, � �������� ������� ����� ��������������" << endl;
	while (!(cin >> N))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "������� �����" << endl;
	}
	cout << "������� ������� �� ������, � �������� ������� ����� ��������������" << endl;
	while (!(cin >> M))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "������� �����" << endl;
	}
	while ((N <= 0) || (M <= 0) || (N > (int)(contnr.size() + 1)) || (M > (int)(contnr.size() + 1)))
	{
		cout << "������� ������� ������(��������� �������� �� 1 �� " << contnr.size() + 1 << "). ��������� ����!" << endl;
		try
		{
			cout << "������� ������ �� ������, � �������� ������� ����� ��������������" << endl;
			while (!(cin >> N))
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "������� �����" << endl;
			}
			cout << "������� ������� �� ������, � �������� ������� ����� ��������������" << endl;
			while (!(cin >> M))
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "������� �����" << endl;
			}
		}
		catch (char *s)
		{
			cout << s << endl;
		}
	}
	if (N > M)
	{
		N = N + M;
		M = N - M;
		N = N - M;
	}
}

//������ ����
void cases()
{
	cout << endl;
	cout << "������� ����� �������:" << endl;
	cout << "1 - ��������� ���� ���������� ������� � ������� �����" << endl;
	cout << "2 - ��������� ���� ���������� ������� � ������� ��������� std::generate" << endl;
	cout << "3 - ������������ ��������� �� ������ �����" << endl;
	cout << "4 - ������������� ���������" << endl;
	cout << "5 - ������������� ����� ����������" << endl;
	cout << "6 - ������������� ��������� � ������� ��������� transform" << endl;
	cout << "7 - ������������� ��������� � ������� ��������� for_each" << endl;
	cout << "8 - ��������� ����� ���� ��������� ����������" << endl;
	cout << "9 - ��������� ������� �������������� ���� ��������� ����������" << endl;
	cout << "10 - ������� ��� �������� ���������� �� �����" << endl;
	cout << "11 - ������� ��� �������� ���������� � ����" << endl;
	cout << "0 - ��������� ������ ���������" << endl;
	cout << endl;
}



//����
void menu(int key)
{
	
	switch (key)
	{
	case 1:
		input_filename(filename, N, M);
		try
		{
			file = make_file_for(filename, N, M);
			file.close();
		}
		catch (char *s)
		{
			cout << s << endl;
		}
		break;

	case 2:
		input_filename(filename, N, M);
		try
		{
			file = make_file_generate(filename, N, M);
			file.close();
		}
		catch (char *s)
		{
			cout << s << endl;
		}
		break;

	case 3:
		try
		{
			string filename;
			cout << "������� ��� �����, �� �������� ����� ������� ������������������" << endl;
			cin >> filename;
			contnr = make_contnr(filename);
		}
		catch (char *s)
		{
			cout << s << endl;
		}
		break;
	case 4:
		if (!contnr.empty())
		{
			contnr = modify(contnr);
		}
		else
		{
			cout << "��������� ����" << endl;
		}
		break;
	case 5:
		input_diapazone(N, M);
		try
		{
			head = get_iterator(contnr, N);
			tail = get_iterator(contnr, M);
			modify(head, tail);
		}
		catch (char *s)
		{
			cout << s << endl;
		}
		break;
	case 6:
		try
		{
			contnr = transform_cntnr(contnr);
		}
		catch (char *s)
		{
			cout << s << endl;
		}
		break;
	case 7:
		try
		{
			contnr = for_each_cntnr(contnr);
		}
		catch (char *s)
		{
			cout << s << endl;
		}
		break;
	case 8:
		try
		{
			cout << "����� ���� ����� ���������� ����� " << sum(contnr.begin(),contnr.end()) << endl;
		}
		catch (char *s)
		{
			cout << s << endl;
		}
		break;
	case 9:
		try
		{
			cout << "������� �������������� ���� ��������� ���������� ����� " << average(contnr.begin(), contnr.end()) << endl;
		}
		catch (char *s)
		{
			cout << s << endl;
		}
		break;
	case 10:
		try
		{
			print(contnr);
		}
		catch (char *s)
		{
			cout << s << endl;
		}
		break;
	case 11:
		cout << "������� ��� �����" << endl;
		cin.clear();
		cin >> filename;
		try
		{
			print_file(filename, contnr);
		}
		catch (char *s)
		{
			cout << s << endl;
		}
		break;
	case 0:
		break;
	default:
		cout << "����� ������� �� ����������! ��������� ����" << endl;
		break;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int key;
	do
	{
		cases();
		while (!(cin >> key))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "������� �������� � ����� �����" << endl;
		}
		menu(key);
	} while (key != 0);

	return 0;
	
}

