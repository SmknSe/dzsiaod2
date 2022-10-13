#pragma once
#include <string>
#include <iostream>
#include<fstream>
using namespace std;
class Book
{
public:
	unsigned long long getIsbn();
	int getPosition();
	bool isClear();
	void setClear(bool);
	bool isDeleted();
	void setDeleted(bool);
	Book(unsigned long long,int);
	Book();

private:
	unsigned long long isbn;
	int position;
	bool clear = true;
	bool deleted = false;
};

