#include "AccountHandler.h"
#include "BoundCheckArray.cpp"
#include "AccountException.h"

int Menu();

void NewAccount(AccountHandler& handler);

void DeleteAccount(AccountHandler& handler);

void Deposit(AccountHandler& handler);

void WithDraw(AccountHandler& handler);

int main()
{
	AccountHandler handler;

	while (1)
	{
		int menuNum = Menu();

		if (menuNum == 6)
		{
			break;
		}

		switch (menuNum)
		{
		case 1:
			NewAccount(handler);
			break;

		case 2:
			Deposit(handler);
			break;

		case 3:
			WithDraw(handler);
			break;

		case 4: 
			handler.ShowAllAccountInfo();
			break;

		case 5:
			DeleteAccount(handler);
			break;

		default:
			std::cout << "잘못 입력 하셨습니다." << std::endl;
			
			break;
		}
	}
}

int Menu()
{
	std::cout << std::endl;
	std::cout << "=Menu=" << std::endl;
	std::cout << "1. 계좌개설\n" << "2. 입 금\n" << "3. 출 금\n"
		<< "4. 계좌정보 전체 출력\n" << "5. 계좌정보 삭제\n" << "6. 프로그램 종료\n" 
		<< "선택 : ";
	int menuNum = 0;
	std::cin >> menuNum;

	return menuNum;
}

void NewAccount(AccountHandler& handler)
{
	mystd::istream cin;

	int accountNum = 0;
	string name;
	int money = 0;
	int interest = 0;
	int creditRating = 0;

	int accountTypeNum = 0;
	std::cout << "\n[계좌 종류 선택]" << std::endl;
	std::cout << "1. 보통예금계좌" << std::endl;
	std::cout << "2. 신용신뢰계좌" << std::endl;
	std::cout << "선택: ";
	std::cin >> accountTypeNum;
	
	switch (accountTypeNum)
	{
	case 1:
		std::cout << "\n[보통예금계좌 개설]" << std::endl;

		std::cout << "계좌번호: ";
		std::cin >> accountNum;

		std::cout << "이름: ";
		cin >> name;

		std::cout << "입금액: ";
		std::cin >> money;

		std::cout << "이자율: ";
		std::cin >> interest;

		if (handler.FindAccount(accountNum) < 0)
		{
			handler.NewAccount(new NormalAccount(accountNum, name, money, interest));
		}
		else
		{
			std::cout << "이미 동일한 계좌번호로 개설된 계좌가 있습니다." << std::endl;
		}

		break;

	case 2:
		std::cout << "\n[신용신뢰계좌 개설]" << std::endl;

		std::cout << "계좌번호 : ";
		std::cin >> accountNum;

		std::cout << "이름 : ";
		cin >> name;

		std::cout << "입금액 : ";
		std::cin >> money;

		std::cout << "이자율: ";
		std::cin >> interest;
		
		std::cout << "신용등급(1toA, 2toB, 3toC): ";
		std::cin >> creditRating;

		if (handler.FindAccount(accountNum) < 0)
		{
			handler.NewAccount(new HighCreditAccount(accountNum, name, money, interest, creditRating));
		}
		else
		{
			std::cout << "이미 동일한 계좌번호로 개설된 계좌가 있습니다." << std::endl;
		}

		break;
	}
}

void DeleteAccount(AccountHandler& handler)
{
	int accountNum = 0;

	std::cout << "\n[삭제할 계좌 번호 입력]" << std::endl;
	std::cin >> accountNum;

	int find_idx = handler.FindAccount(accountNum);

	if (find_idx < 0)
	{
		std::cout << "해당하는 계좌가 존재하지 않습니다." << std::endl;
	}
	else
	{
		handler.DeleteAccount(find_idx);
	}
}

void Deposit(AccountHandler& handler)
{
	std::cout << "\n[입 금]" << std::endl;

	std::cout << "계좌번호 : ";
	int accountNum = 0;
	std::cin >> accountNum;

	while (1)
	{
		std::cout << "입금액 : ";
		int money = 0;
		std::cin >> money;

		try
		{
			handler.Deposit(accountNum, money);
			break;
		}
		catch (AccountException& expn)
		{
			expn.ShowExceptionReason();
		}
	}	
}

void WithDraw(AccountHandler& handler)
{
	std::cout << "\n[출 금]" << std::endl;

	std::cout << "계좌번호 : ";
	int accountNum = 0;
	std::cin >> accountNum;

	while (1)
	{
		std::cout << "출금액 : ";
		int money = 0;
		std::cin >> money;

		try
		{
			handler.WithDraw(accountNum, money);
			break;
		}
		catch (AccountException& expn)
		{
			expn.ShowExceptionReason();
		}
	}
	
}