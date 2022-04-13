#pragma once
#include "HighCreditAccount.h"
#include "BoundCheckArray.h"
#include "AccountException.h"

#define ACCOUNT_MAX 10

class AccountHandler
{
private:
	BoundCheckArray<ACCOUNT_PTR> accountList;
	int memberNum;

	AccountHandler(const AccountHandler& copy);

public:
	AccountHandler();

	void NewAccount(Account* account);

	void DeleteAccount(const int find_idx);

	int GetMemberNum() const;

	int FindAccount(const int& acccountNum) const;

	void Deposit(const int& accountNum, const int& money);

	void WithDraw(const int& accountNum, const int& money);

	void ShowAllAccountInfo() const;

	~AccountHandler();
};