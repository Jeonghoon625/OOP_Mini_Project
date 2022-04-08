#pragma once
#include "Account.h"

class NormalAccount : public Account
{
private:
	int interest; //¿Ã¿⁄

public:
	NormalAccount(const int& accountNum, const char* name, const int& ballance, const int& interest);

	virtual void AddBallance(const int& money);

	virtual void ShowAccountInfo() const;

	virtual ~NormalAccount();
};

