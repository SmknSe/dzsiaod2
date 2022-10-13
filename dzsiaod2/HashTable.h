#pragma once
#include"Book.h"
#include<vector>
using namespace std;
class HashTable
{
public:
	HashTable(int m);
	int getInd(unsigned long long);
	unsigned long long getNewInd(unsigned long long);
	void insBook(Book*);
	int findBook(unsigned long long);
	void removeBook(Book*);
	int size();
	friend void print(HashTable);
	friend void remove(HashTable&,int);

private:
	int m;
	int n;
	vector<Book> books;
};
