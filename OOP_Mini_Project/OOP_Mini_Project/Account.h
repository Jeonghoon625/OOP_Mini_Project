#pragma once

#include <iostream>
#include <cstring>
#include "Mystring.h"

using namespace my;

class Account
{
protected:

	int accountNum; // ���¹�ȣ
	string name; // ����
	int ballance; // �ܾ�

public:
	Account(const int& accountNum, string name, const int& ballance);

	Account(const Account& copy);

	Account& operator= (const Account& ref);

	int GetaccountNum() const;

	int GetBallance() const;

	virtual void AddBallance(const int& money);

	void TakeBallance(const int& money);

	virtual void ShowAccountInfo() const;

	virtual ~Account();
};

typedef Account* ACCOUNT_PTR;