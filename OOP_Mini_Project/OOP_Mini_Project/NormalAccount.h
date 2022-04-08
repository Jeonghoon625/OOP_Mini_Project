#pragma once
#include "Account.h"

class NormalAccount : public Account
{
protected:
	int interest; //����
	NormalAccount(const NormalAccount& copy);

public:
	NormalAccount(const int& accountNum, const char* name, const int& ballance, const int& interest);

	virtual void AddBallance(const int& money);

	virtual void ShowAccountInfo() const;

	virtual ~NormalAccount();
};

