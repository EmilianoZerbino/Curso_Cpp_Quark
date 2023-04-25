#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <iomanip>
#include <list>
#include "IView.h"
#include "Book.h";
#include "Member.h"
#include "Borrow.h"

using namespace std;

class View : public IView
{
public:

	View();
	string showMainMenu() override;
	void showBorrowMenu(string* pointerData, list<Member> members, list<Book> books) override;
	void showDevolutionMenu(string* pointer, list<Borrow>borrows) override;
	void showAddNewMemberMenu(string* pointer) override;
	void showAddNewBookMenu(string* pointer) override;
	void showAddNewEditionMenu(string* pointer, list<string> isbnCodes) override;
	void showHistorialBorrowMenu(list<Borrow> borrows, list<Book> books) override;
	void showAvailabilityMenu(list<Book> books) override;
	void showEndScreen() override;

private:

	string option;
	int options;

	void cleanConsole() override;
	void setHeaderAndFooter(string header, string footer, int x, int y) override;
	void checkIncorrectOption(int options, int posX, int posY) override;
	void check(int posX, int posY);
	void setConsole() override;
	void setErrorLetter() override;
	void setNormalLetter() override;
	void setCursorPosition(short x, short y) override;

};

