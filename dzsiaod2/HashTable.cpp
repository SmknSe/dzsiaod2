#include "HashTable.h"

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

int HashTable::getNewInd(unsigned long long key,int ind)
{
    return ((key/m)+ind)%m;
}

void HashTable::insBook(Book* b)
{
    int ind = this->getInd(b->getIsbn());
    while (!books[ind].isClear()) {
        ind = this->getNewInd(b->getIsbn(), ind);
    }
    books[ind] = *b;
    n++;
    books[ind].setClear(false);
}

int HashTable::findBook(Book b)
{
    int i = this->getInd(b.getIsbn());
    while ((!books[i].isClear() || books[i].isDeleted()) && b.getIsbn() != books[i].getIsbn()) {
        i = this->getNewInd(b.getIsbn(), i);
    }
    if (books[i].isClear() || books[i].isDeleted()) return -1;
    else return i;
}

void HashTable::removeBook(Book b)
{
    int i = this->getInd(b.getIsbn());
    while ((!books[i].isClear() || books[i].isDeleted()) && b.getIsbn() != books[i].getIsbn()) {
        i = this->getNewInd(b.getIsbn(), i);
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

