#pragma once

#include <string>
#include<list>
#include "Edition.h"

using namespace std;

class Member
{
public:

	Member(string name, string lastName, string identificationCode);
	string getName();
	string getLastName();
	string getIdentificationCode();
	list<Edition>& getBorrowedEditions();
	int getMaxBorrowedEditions();
	void borrowEdition(Edition edition);
	void deleteEdition(Edition edition);

protected:

	string name;
	string lastName;
	string identificationCode;
	list<Edition> borrowedEditions;
	int maxBorrowedEditions;

};

