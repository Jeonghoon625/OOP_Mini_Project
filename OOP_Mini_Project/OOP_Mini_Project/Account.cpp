#include "Account.h"

Account::Account(const int& accountNum, const char* name, const int& ballance)
{
	this->accountNum = accountNum;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	this->ballance = ballance;
}

int Account::GetBallance() const
{
	return ballance;
}

void Account::SetBallance(const int& ballance)
{
	this->ballance = ballance;
}

void Accout::AddBallance(const int& money)
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