#pragma once
#include "Account.h"

class NormalAccount : public Account
{
private:
	int interest; //ÀÌÀÚ

public:
	NormalAccount(const int& accountNum, const char* name, const int& ballance, const int& interest);

	virtual void AddBallance(const int& money);
};

