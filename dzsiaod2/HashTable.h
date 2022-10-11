#pragma once
#include"Book.h"
using namespace std;
class HashTable
{
public:
	HashTable(int m);
	~HashTable();
	int getInd(unsigned long long);
	int getNewInd(unsigned long long,int);
	void insBook(Book);
	int findBook(Book);
	void removeBook(Book);

private:
	int m;
	int n;
	Book* books;
};
