#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include "HashTable.h"
#include<random>
using namespace std;

static int items_c;

void fillHashTable(HashTable& table);

void write(ostream& os, string a)
{
	os.write((char*)a.data(), 50);
}
//
int fileItems_c() {
	ifstream in;
	in.open("1.txt", ios::binary | ios::in);
	char* buf = new char[50];
	int c = 0;
	while(!in.eof()) {
		in.read(buf, 50);
		c++;
	}
	in.close();
	return c-1;
}

unsigned long long readKey(int t)
{
	ifstream in;
	in.open("1.txt", ios::binary | ios::in);
	in.seekg(50 * t, ios::beg);
	unsigned long long tmp;
	in >> tmp;
	return tmp;
}

void autoFilling() {
	ofstream f;
	f.open("1.txt", ios::binary | ios::out);
	string a;
	a = "12345678901234567891 Shasha Scfsd ";
	write(f, a);
	a = "12345678901234567894 ME Ssdc ";
	write(f, a);
	a = "12345678901234567896 Smo fgbfsd ";
	write(f, a);
	a = "15555555555555555554 Amin werd ";
	write(f, a);
	a = "12345678901234567898 Who ghnsd ";
	write(f, a);
	a = "12345678901234567893 Ya kj ";
	write(f, a);
	a = "14444444444444444448 Neya lll ";
	write(f, a);
	a = "12345678901234567897 Ti yey ";
	write(f, a);
	a = "12345678901234567892 Neti ttt ";
	write(f, a);
	f.close();
}

string rand20() {
	string str = "1" + to_string(rand() % 8);
	for (int i = 0; i < 18; i++)
		str += to_string(rand() % 10);
	return str;
}

string randStr(int n) {
	string a = "";
	for (int i = 0; i < n; i++) {
		a += char(97 + rand() % 26);
	}
	return a;
}

void bigAutoFilling(int n) {
	ofstream f;
	f.open("1.txt", ios::binary | ios::out);
	string a;
	for (int i = 0; i < n; i++)
	{
		a = rand20() + " " + randStr(5) + " " + randStr(10)+" ";
		a = "12345678901234567897 Ti yey ";
		write(f, a);
	}
	f.close();
}

void reHash(HashTable& table) {
	table.resize(table.size() * 2);
};



void fillHashTable(HashTable& table) {
	int t = fileItems_c();
	for (int i = 0; i < t; i++) {
		table.insBook(new Book(readKey(i),i));
		float n = (float)table.n / (float)table.size();
		if (n >= 0.75) {
			reHash(table);
		}
	}
}



void print(HashTable h)
{
	for (int i = 0; i < h.size(); i++) {
		if (!h.books[i].isClear()) {
			cout << i << " " << readKey(h.books[i].getPosition()) << endl;
		}
	}
}

void remove(HashTable& h, int item) {
	unsigned long long delKey = readKey(h.books[item].getPosition());
	h.books[item].setDeleted(true);

	vector<string> temp;

	ifstream in;
	in.open("1.txt", ios::binary | ios::in);
	char* buf = new char[50];
	for (int i = 0; i < fileItems_c(); i++) {
		in.read(buf, 50);
		string t = buf;
		t = t.substr(0, 20);
		if (t != to_string(delKey)) {
			temp.push_back(buf);
		}
	}
	in.close();
	
	ofstream f;
	f.open("1.txt", ios::binary | ios::out);
	for (int i = 0; i < temp.size(); i++) {
		f.write((char*)temp[i].data(), 50);
	}
	f.close();
	h.books.clear();
	h.books.resize(10);
	fillHashTable(h);
}

void find(HashTable h, unsigned long long k) {
	int p = h.findBook(k);
	ifstream in;
	in.open("1.txt", ios::binary | ios::in);
	in.seekg(50 * p, ios::beg);
	string isbn, name, label;
	in >> isbn; in >> name; in >> label;
	cout << isbn << " " << name << " " << label << endl;
}


int main() {
	setlocale(0, "");
	bigAutoFilling(9);
	//autoFilling();
	HashTable h(10);
	fillHashTable(h);
	cout << "Таблица:\n";
	print(h);
	cout << "Размер таблицы: " << h.size() << endl;

	int n;
	cout << "Введите номер удаляемой книги: "; cin >> n;
	remove(h,n);
	cout << "После удаления:\n";
	print(h);
	unsigned int start_time = clock();

	cout << "Поиск первого элемента в файле:" << endl;
	find(h, 12345678901234567891);
	unsigned int end_time = clock();
	cout << "Время, затраченное на поиск: " << end_time - start_time << endl;

	start_time = clock();
	cout << "Поиск серединного элемента в файле:" << endl;
	find(h, 12345678901234567898);
	end_time = clock();
	cout << "Время, затраченное на поиск: " << end_time - start_time << endl;

	start_time = clock();
	cout << "Поиск крайнего элемента в файле:" << endl;
	find(h, 12345678901234567892);
	end_time = clock();
	cout << "Время, затраченное на поиск: " << end_time - start_time << endl;
}