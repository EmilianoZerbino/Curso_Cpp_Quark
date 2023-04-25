#pragma once
#include <string>
#include <list>
#include "Book.h"
#include "Member.h"
#include "Borrow.h"

using namespace std;

class IView
{
public:

	virtual string showMainMenu()=0;
	virtual void showBorrowMenu(string* pointerData, list<Member> members, list<Book> books) = 0;
	virtual void showDevolutionMenu(string* pointer, list<Borrow>borrows) = 0;
	virtual void showAddNewMemberMenu(string* pointer) = 0;
	virtual void showAddNewBookMenu(string* pointer) = 0;
	virtual void showAddNewEditionMenu(string* pointer, list<string> isbnCodes) = 0;
	virtual void showHistorialBorrowMenu(list<Borrow> borrows, list<Book> books)=0;
	virtual void showAvailabilityMenu(list<Book> books) = 0;
	virtual void showEndScreen() = 0;

private:

	virtual void cleanConsole() = 0;
	virtual void setHeaderAndFooter(string header, string footer, int x, int y) = 0;
	virtual void checkIncorrectOption(int options, int posX, int posY) = 0;
	virtual void setConsole() = 0;
	virtual void setErrorLetter() = 0;
	virtual void setNormalLetter() = 0;
	virtual void setCursorPosition(short x, short y) = 0;

};

