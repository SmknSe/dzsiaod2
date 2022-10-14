#include "HashTable.h"

void HashTable::resize(int n)
{
    books.resize(n);
}

HashTable::HashTable(int m)
{
    books.resize(m);
    this->m = m;
    n = 0;
}

int HashTable::getInd(unsigned long long key)
{
    return key%m;
}

unsigned long long HashTable::getNewInd(unsigned long long key)
{
    return key / m;
}

void HashTable::insBook(Book* b)
{
    int ind = this->getInd(b->getIsbn());
    while (!books[ind].isClear()) {
        unsigned long long sm = this->getNewInd(b->getIsbn());
        if (sm != 0) ind = (ind + sm) % m;
        else ind = (ind++) % m;
    }
    books[ind] = *b;
    n++;
    books[ind].setClear(false);
}

int HashTable::findBook(unsigned long long key)
{
    int i = this->getInd(key);
    unsigned long long sm = this->getNewInd(key);
    while ((!books[i].isClear() || books[i].isDeleted()) && key != books[i].getIsbn()) {
        if (sm != 0) i = (i + sm) % m;
        else i = (i++) % m;
    }
    if (books[i].isClear() || books[i].isDeleted()) return NULL;
    else return books[i].getPosition();
}

void HashTable::removeBook(Book* b)
{
    int i = this->getInd(b->getIsbn());
    while ((!books[i].isClear() || books[i].isDeleted()) && b->getIsbn() != books[i].getIsbn()) {
        unsigned long long sm = this->getNewInd(b->getIsbn());
        if (sm != 0) i = (i + sm) % m;
        else i = (i++) % m;
    }
    if (books[i].isClear() || books[i].isDeleted()) return;
    else {
        books[i].setDeleted(true);
    }
}

int HashTable::size()
{
    return books.size();
}

