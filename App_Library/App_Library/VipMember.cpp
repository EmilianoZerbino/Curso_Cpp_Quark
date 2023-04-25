#include "VipMember.h"

VipMember::VipMember(string name, string lastName, string identificationCode, float monthlyFee)
	: Member(name, lastName, identificationCode)
{
	this->monthlyFee = monthlyFee;
	this->maxBorrowedEditions = 3;
}

float VipMember::getMonthlyFee()
{
	return monthlyFee;
}

