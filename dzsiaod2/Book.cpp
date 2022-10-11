#include "Book.h"

string Book::getAuthor()
{
    return author;
}

string Book::getLabel()
{
    return label;
}

unsigned long long Book::getIsbn()
{
    return isbn;
}

bool Book::isClear()
{
    return clear;
}

void Book::setClear(bool f)
{
    clear = f;
}

bool Book::isDeleted()
{
    return deleted;
}

void Book::setDeleted(bool f)
{
    deleted = f;
}

Book::Book(unsigned long long isbn,string author, string label)
{
    this->isbn = isbn;
    this->label = label;
    this->author = author;
}

Book::Book()
{
    clear = true;
}
