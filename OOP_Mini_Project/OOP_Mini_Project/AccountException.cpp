#include "AccountException.h"
#include <iostream>

DepositException::DepositException(int money) : reqDeq(money)
{
}

void DepositException::ShowExceptionReason() const
{
	std::cout << "입금금액 : " << reqDeq << "\n입금액이 음수일 수 없습니다." << std::endl;
}

WithDrawException::WithDrawException(int money) : ballance(money)
{
}

void WithDrawException::ShowExceptionReason() const
{
	if (ballance < 0)
	{
		std::cout << "출금금액 : " << ballance << "\n출금액이 음수일 수 없습니다." << std::endl;
	}
	else
	{
		std::cout << "잔액이 부족합니다." << std::endl;
	}
}
