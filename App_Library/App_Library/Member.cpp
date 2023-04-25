#include "Member.h"
#include "Edition.h"

Member::Member(string name, string lastName, string identificationCode)
{
	this->name = name;
	this->lastName = lastName;
	this->identificationCode = identificationCode;
	this->maxBorrowedEditions = 1;
}

string Member::getName()
{
	return name;
}

string Member::getLastName()
{
	return lastName;
}

string Member::getIdentificationCode()
{
	return identificationCode;
}

list<Edition>& Member::getBorrowedEditions()
{
	return borrowedEditions;
}

int Member::getMaxBorrowedEditions()
{
	return maxBorrowedEditions;
}

void Member::borrowEdition(Edition edition)
{
	borrowedEditions.push_back(edition);
}

void Member::deleteEdition(Edition edition)
{
	
	list<Edition> aux = getBorrowedEditions();
	borrowedEditions.clear();
	for (auto ed = aux.begin(); ed != aux.end(); ++ed) {
		if (ed->getIsbnCode() != edition.getIsbnCode()) {
			borrowedEditions.push_back(*ed);
		}
	}
	
}
