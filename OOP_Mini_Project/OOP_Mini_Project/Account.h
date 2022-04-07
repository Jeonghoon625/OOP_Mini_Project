#pragma once

#include <iostream>
#include <cstring>

class Account
{
private:
	int accountNum; // °èÁÂ¹øÈ£
	char* name; // ¼ºÇÔ
	int ballance; // ÀÜ¾×

public:
	Account(const int& accountNum, const char* name, const int& ballance);

	int GetaccountNum() const;

	int GetBallance() const;

	virtual void AddBallance(const int& money);

	void TakeBallance(const int& money);

	void ShowAccountInfo() const;

	~Account();
};