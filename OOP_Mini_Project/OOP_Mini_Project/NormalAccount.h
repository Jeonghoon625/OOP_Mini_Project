#pragma once
#include "Account.h"

class NormalAccount : public Account
{
protected:
	int interest; //¿Ã¿⁄
	
public:
	NormalAccount(const int& accountNum, const char* name, const int& ballance, const int& interest);

	NormalAccount(const NormalAccount& copy);
	
	NormalAccount& operator= (const NormalAccount& ref);

	virtual void AddBallance(const int& money);

	virtual void ShowAccountInfo() const;

	virtual ~NormalAccount();
};

