#include "NormalAccount.h"

NormalAccount::NormalAccount(const int& accountNum, const char* name, const int& ballance, const int& interest)
	: Account(accountNum, name, ballance)
{
	this->interest = interest;
}

void NormalAccount::AddBallance(const int& money)
{
	Account::AddBallance(money);
	Account::AddBallance(money * interest / 100);
}