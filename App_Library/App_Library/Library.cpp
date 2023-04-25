#include "Library.h"

list<Member>& Library::getMembers()
{
    return members;
}

list<Book>& Library::getBooks()
{
    return books;
}

list<Borrow>& Library::getBorrows()
{
    return borrows;
}

void Library::addBorrow(Borrow borrow)
{
    borrows.push_back(borrow);
}

void Library::addNewMember(Member member)
{
    members.push_back(member);
}

void Library::addNewBook(Book book)
{
    books.push_back(book);
}

list<string> Library::getIsbnCodes()
{
    list<string> isbnCodes;
    for (auto book = books.begin(); book != books.end(); ++book) {
        isbnCodes.push_back(book->getIsbnCode());
    }
    return isbnCodes;
}
