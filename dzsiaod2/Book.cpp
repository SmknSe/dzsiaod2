#include "Book.h"

unsigned long long Book::getIsbn()
{
    return isbn;
}

int Book::getPosition()
{
    return position;
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

Book::Book(unsigned long long isbn, int pos)
{
    this->isbn = isbn;
    position = pos;
}

Book::Book()
{
    clear = true;
}
