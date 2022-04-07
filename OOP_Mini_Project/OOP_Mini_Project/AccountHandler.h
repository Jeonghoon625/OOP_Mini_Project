#pragma once
#include "Account.h"
#define ACCOUNT_MAX 10

class AccountHandler
{
private:
	Account* accountList[ACCOUNT_MAX];
	int memberNum;

public:
	AccountHandler();

	int GetMemberNum();
	void SetMemberNum();

};

