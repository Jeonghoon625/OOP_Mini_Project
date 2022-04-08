#pragma once
#include "HighCreditAccount.h"
#include "BoundCheckPointPtrArray.h"
#define ACCOUNT_MAX 10

class AccountHandler
{
protected:
	Account* accountList[ACCOUNT_MAX];
	int memberNum;
	AccountHandler(const AccountHandler& copy);

public:
	AccountHandler();

	void NewAccount(Account* account);

	int GetMemberNum() const;

	int FindAccount(const int& acccountNum) const;

	void Deposit(const int& accountNum, const int& money);

	void WithDraw(const int& accountNum, const int& money);

	void ShowAllAccountInfo() const;

	~AccountHandler();
};

