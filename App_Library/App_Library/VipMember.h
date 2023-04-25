#pragma once
#include <string>

#include "Member.h"

using namespace std;

class VipMember : public Member
{
public:

	VipMember(string name, string lastName, string identificationCode, float monthlyFee);
	float getMonthlyFee();

private:

	float monthlyFee;
};

