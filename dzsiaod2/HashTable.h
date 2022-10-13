#pragma once
#include"Book.h"
#include<vector>
using namespace std;
class HashTable
{
public:
	HashTable(int m);
	int getInd(unsigned long long);
	int getNewInd(unsigned long long,int);
	void insBook(Book*);
	int findBook(Book);
	void removeBook(Book);
	int size();
	friend void print(HashTable);

private:
	int m;
	int n;
	vector<Book> books;
};
