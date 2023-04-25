#include "Book.h"

Book::Book(string name, string isbnCode, string author)
{
	this->name = name;
	this->isbnCode = isbnCode;
	this->author = author;

}

string Book::getName()
{
	return name;
}

string Book::getIsbnCode()
{
	return isbnCode;
}

string Book::getAuthor()
{
	return author;
}

list<Edition>& Book::getEditions()
{
	return editions;
}

void Book::addNewEdition(Edition edition)
{
	editions.push_back(edition);
}

bool Book::getAvailability()
{
	bool availability = false;
	for (auto edition = editions.begin(); edition != editions.end(); ++edition) {
		if (!edition->getBorrowed()) {
			availability = true;
		}
	}
	return availability;
}

Edition Book::lendEdition()
{
	//Falta Completar
	return Edition("","","");
}

void Book::returnEdition(Edition)
{
	//Falta Completar
}

