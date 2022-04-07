#pragma once

#include <iostream>
#include <cstring>

class Account
{
private:
	int accountNum; // ���¹�ȣ
	char* name; // ����
	int ballance; // �ܾ�

public:
	Account(const int& accountNum, const char* name, const int& ballance);

	int GetaccountNum() const;

	int GetBallance() const;

	virtual void AddBallance(const int& money);

	void TakeBallance(const int& money);

	void ShowAccountInfo() const;

	~Account();
};