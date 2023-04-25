#include "Edition.h"

Edition::Edition(string isbnCode, string editionNumber, string location)
{
	this->isbnCode = isbnCode;
	this->editionNumber = editionNumber;
	this->location = location;
	this->borrowed = false;
}

string Edition::getEditionNumber()
{
	return editionNumber;
}

string Edition::getIsbnCode()
{
	return isbnCode;
}

string Edition::getLocation()
{
	return location;
}

bool Edition::getBorrowed()
{
	return borrowed;
}

void Edition::setBorrowed(bool state)
{
	borrowed = state;
}

