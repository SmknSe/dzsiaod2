#pragma once
#include <string>
#include <iostream>
#include<fstream>
using namespace std;
class Book
{
public:
	string getAuthor();
	string getLabel();
	unsigned long long getIsbn();
	bool isClear();
	void setClear(bool);
	bool isDeleted();
	void setDeleted(bool);
	Book(unsigned long long,string,string);
	Book();

private:
	unsigned long long isbn;
	string author;
	string label;
	bool clear = true;
	bool deleted = false;
};

