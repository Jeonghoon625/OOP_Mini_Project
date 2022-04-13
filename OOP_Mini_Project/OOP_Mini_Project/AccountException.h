#pragma once

class AccountException
{
public:
	virtual void ShowExceptionReason() const = 0;
};

class DepositException : public AccountException
{
private:
	int reqDeq;

public:
	DepositException(int money);
	void ShowExceptionReason() const;
};

class WithDrawException : public AccountException
{
private:
	int ballance;

public:
	WithDrawException(int money);
	void ShowExceptionReason() const;
};