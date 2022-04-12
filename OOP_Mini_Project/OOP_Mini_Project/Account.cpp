#include "Account.h"

Account::Account(const int& accountNum, string name, const int& ballance)
{
	this->accountNum = accountNum;
	this->name = name;
	this->ballance = ballance;
}

Account::Account(const Account& copy) : accountNum(copy.accountNum), name(copy.name), ballance(copy.ballance)
{	
}

Account& Account::operator= (const Account& ref) 
{
	accountNum = ref.accountNum;
	ballance = ref.ballance;
	name = ref.name;

	return *this;
}

int Account::GetaccountNum() const
{
	return accountNum;
}

int Account::GetBallance() const
{
	return ballance;
}

void Account::AddBallance(const int& money)
{
	ballance += money;
}

void Account::TakeBallance(const int& money)
{
	ballance -= money;
}

void Account::ShowAccountInfo() const
{
	std::cout << "\n°èÁÂ¹øÈ£ : " << accountNum << std::endl;
	mystd::ostream cout;
	cout << "ÀÌ¸§ : " << name << mystd::endl;
	std::cout << "ÀÜ¾× : " << ballance << std::endl;
}

Account::~Account()
{
}