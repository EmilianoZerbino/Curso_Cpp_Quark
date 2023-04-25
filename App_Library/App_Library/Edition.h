#pragma once
#include <string>

using namespace std;

class Edition
{
public:
	Edition(string isbnCode, string editionNumber, string location);
	string getEditionNumber();
	string getIsbnCode();
	string getLocation();
	bool getBorrowed();
	void setBorrowed(bool state);

private:

	string isbnCode;
	string editionNumber;
	string location;
	bool borrowed;

};

