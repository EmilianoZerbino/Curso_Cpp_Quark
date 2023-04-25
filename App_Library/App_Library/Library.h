#pragma once
#include<list>
#include "Member.h"
#include "Book.h"
#include "Borrow.h"

//#include "Member.h"
//#include "Book.h"
//#include "Borrow.h"

class Library
{
public:
	
	list<Member>& getMembers();
	list<Book>& getBooks();
	list<Borrow>& getBorrows();
	void addBorrow(Borrow borrow);
	void addNewMember(Member member);
	void addNewBook(Book book);
	list<string> getIsbnCodes();

private:

	list<Member> members;
	list<Book> books;
	list<Borrow> borrows;
};

