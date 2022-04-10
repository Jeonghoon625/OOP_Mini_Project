#pragma once

#include <iostream>
#include <cstring>

class Account
{
protected:
	int accountNum; // ���¹�ȣ
	char* name; // ����
	int ballance; // �ܾ�

	Account(const Account& copy);

public:
	Account(const int& accountNum, const char* name, const int& ballance);

	Account& operator= (const Account& ref);

	int GetaccountNum() const;

	int GetBallance() const;

	virtual void AddBallance(const int& money);

	void TakeBallance(const int& money);

	virtual void ShowAccountInfo() const;

	virtual ~Account();
};

typedef Account* ACCOUNT_PTR;