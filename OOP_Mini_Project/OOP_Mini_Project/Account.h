#pragma once

#include <iostream>
#include <cstring>

class Account
{
private:
	int accountNum; // ฐ่มยน๘ศฃ
	char* name; // ผบวิ
	int ballance; // ภÜพื

public:
	Account(const int& accountNum, const char* name, const int& ballance);

	int GetBallance() const;

	void SetBallance(const int& ballance);

	void ShowAccountInfo() const;

	~Account();
};