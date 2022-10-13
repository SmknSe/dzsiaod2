#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include "HashTable.h"
using namespace std;

//struct Item
//{
//	bool Pins = true;
//	int position;
//};
//
static int items_c;
//
//void fillHashTable(vector<Item>& table);
//
void write(ostream& os, string a)
{
	os.write((char*)a.data(), 50);
}
//
int fileItems_c() {
	ifstream in;
	in.open("1.txt");
	string temp;
	getline(in, temp);
	in.close();
	return temp.length() / 50;
}
//
//void readAllFile()
//{
//	ifstream in;
//	in.open("1.txt", ios::binary | ios::in);
//	char* buf = new char[40];
//	for (int i = 0; i < fileItems_c(); i++) {
//		in.read(buf, 40);
//		cout << buf << endl;
//	}
//}
//
unsigned long long readKey(int t)
{
	ifstream in;
	in.open("1.txt", ios::binary | ios::in);
	string a;
	in.seekg(50 * t, ios::beg);
	unsigned long long tmp;
	in >> tmp;
	return tmp;
}

void autoFilling() {
	ofstream f;
	f.open("1.txt", ios::binary | ios::out);
	string a;
	a = "12345678901234567891 Shasha Scfsd";
	write(f, a);
	a = "12345678901234567894 ME Ssdc";
	write(f, a);
	a = "12345678901234567896 Smo fgbfsd";
	write(f, a);
	a = "15555555555555555554 Amin werd";
	write(f, a);
	a = "12345678901234567898 Who ghnsd";
	write(f, a);
	a = "12345678901234567893 Ya kj";
	write(f, a);
	a = "14444444444444444448 Neya lll";
	write(f, a);
	a = "12345678901234567897 Ti yey";
	write(f, a);
	a = "12345678901234567892 Neti ttt";
	write(f, a);
	f.close();
}
//
//int hashFunc(string s) {
//	int key = stoi(s.substr(6, 9));
//	return key % 10;
//}
//
//void reHash(vector<Item>& table) {
//	vector<Item> temp(table.size() * 2);
//	fillHashTable(temp);
//	table = temp;
//
//};
//
//void writeItemInTable(vector<Item>& table, int t) {
//	string item = readKey(t);
//	int key = hashFunc(item);
//	bool flag = false;
//	for (int i = key; i < table.size(); i++) {
//		if (table[i].Pins) {
//			table[i].Pins = false;
//			table[i].position = t;
//			flag = true;
//			items_c++;
//			break;
//		}
//	}
//	if (!flag) {
//		table.push_back(Item{ false, t });
//		items_c++;
//	}
//}
//


void fillHashTable(HashTable& table) {
	int t = fileItems_c();
	items_c = 0;
	for (int i = 0; i < t; i++) {
		table.insBook(new Book(readKey(i),i));
		float n = (float)items_c / (float)table.size();
		/*if (n >= 0.75) {
			reHash(table);
		}*/
	}
}


//
void print(HashTable h)
{
	for (int i = 0; i < h.books.size(); i++) {
		if (!h.books[i].isClear()) {
			cout << i << " " << readKey(h.books[i].getPosition()) << " удалена: " << h.books[i].isDeleted() << endl;
		}
		else cout << i << " empty\n";
	}
}
//
//void removeBook(HashTable& table, int item) {
//	string delStr = readKey(table[item].position);
//	table[item].Pins = true;
//	table[item].position = NULL;
//
//	vector<string> temp;
//
//	ifstream in;
//	in.open("1.txt", ios::binary | ios::in);
//	char* buf = new char[40];
//	for (int i = 0; i < fileItems_c(); i++) {
//		in.read(buf, 40);
//		string t = buf;
//		if (t != delStr) {
//			temp.push_back(t);
//		}
//	}
//	in.close();
//
//	ofstream f;
//	f.open("1.txt", ios::binary | ios::out);
//	for (int i = 0; i < temp.size(); i++) {
//		f.write((char*)temp[i].data(), 40);
//	}
//	f.close();
//	table.clear();
//	table.resize(10);
//	fillHashTable(table);
//	return table;
//}
//
//void printItem(vector<Item>& table, string date) {
//	int key = hashFunc(date);
//	string temp;
//	do
//	{
//		temp = readKey(table[key].position);
//		key++;
//	} while (date != temp.substr(0, 10));
//	cout << temp << endl;
//}

int main() {
	/*setlocale(0, "");
	autoFilling();
	vector<Item> table(10);
	fillHashTable(table);
	cout << "Изначальная таблица с данными:" << endl;
	printTable(table);
	cout << endl << "Размер таблицы: " << table.size() << endl << endl;
	cout << "Таблица после удаления 4-ой позиции:" << endl;
	table = removeBook(table, 4);
	printTable(table);

	unsigned int start_time = clock();
	cout << "Поиск первого элемента в файле:" << endl;
	printItem(table, "01.12.2002");
	unsigned int end_time = clock();
	cout << "Время, затраченное на поиск: " << end_time - start_time << endl;

	start_time = clock();
	cout << "Поиск серединного элемента в файле:" << endl;
	printItem(table, "30.08.2006");
	end_time = clock();
	cout << "Время, затраченное на поиск: " << end_time - start_time << endl;

	start_time = clock();
	cout << "Поиск крайнего элемента в файле:" << endl;
	printItem(table, "08.01.1993");
	end_time = clock();
	cout << "Время, затраченное на поиск: " << end_time - start_time << endl;*/
	setlocale(0, "");
	autoFilling();
	HashTable h(11);
	fillHashTable(h);
	cout << "Таблица:\n";
	print(h);
	int n;
	cout << "Введите номер удаляемой книги: "; cin >> n;
	//removeBook(h,n);
}