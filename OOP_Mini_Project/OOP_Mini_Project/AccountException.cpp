#include "AccountException.h"
#include <iostream>

DepositException::DepositException(int money) : reqDeq(money)
{
}

void DepositException::ShowExceptionReason() const
{
	std::cout << "�Աݱݾ� : " << reqDeq << "\n�Աݾ��� ������ �� �����ϴ�." << std::endl;
}

WithDrawException::WithDrawException(int money) : ballance(money)
{
}

void WithDrawException::ShowExceptionReason() const
{
	if (ballance < 0)
	{
		std::cout << "��ݱݾ� : " << ballance << "\n��ݾ��� ������ �� �����ϴ�." << std::endl;
	}
	else
	{
		std::cout << "�ܾ��� �����մϴ�." << std::endl;
	}
}
