#pragma once
#include "Edition.h"
#include "Member.h"
#include "Borrow.h"

class Borrow
{
public:

	Borrow(Member member, Edition edition);
	Member getMember();
	Edition getEdition();
	string getDateOfBorrow();
	string getDateOfDevolution();
	bool getDevolution();
	void setDevolution(bool state);

private:

	string calculateDateAndTime();
	Member member;
	Edition edition;
	string dateOfBorrow;
	string dateOfDevolution;
	bool devolution;
};

