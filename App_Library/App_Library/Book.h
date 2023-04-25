#pragma once
#include <string>
#include <list>
#include "Edition.h"


using namespace std;

class Book
{
public:

	Book(string name, string isbncode, string author);
	string getName();
	string getIsbnCode();
	string getAuthor();
	list<Edition>& getEditions();
	void addNewEdition(Edition edition);
	bool getAvailability();
	Edition lendEdition();
	void returnEdition(Edition);

private:

	string name;
	string isbnCode;
	string author;
	list<Edition> editions;
};


