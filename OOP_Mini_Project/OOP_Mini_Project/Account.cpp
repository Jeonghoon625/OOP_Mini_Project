#include "Account.h"

Account::Account(const int& accountNum, const char* name, const int& ballance)
{
	this->accountNum = accountNum;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	this->ballance = ballance;
}

Account::Account(const Account& copy) : accountNum(copy.accountNum), ballance(copy.ballance)
{	
	name = new char[strlen(copy.name) + 1];
	strcpy_s(name, strlen(copy.name) + 1, copy.name);
}

Account& Account::operator= (const Account& ref) 
{
	accountNum = ref.accountNum;
	ballance = ref.ballance;
	delete[] name;
	name = new char[strlen(ref.name) + 1];
	strcpy_s(name, strlen(ref.name) + 1, ref.name);

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
	std::cout << "ÀÌ¸§ : " << name << std::endl;
	std::cout << "ÀÜ¾× : " << ballance << std::endl;
}

Account::~Account()
{
	delete[] name;
}