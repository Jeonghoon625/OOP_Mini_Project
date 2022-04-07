#include "AccountHandler.h"

int Menu();

void NewAccount(AccountHandler& handler);

void Deposit(AccountHandler& handler);

void WithDraw(AccountHandler& handler);

int main()
{
	AccountHandler handler;

	while (1)
	{
		int menuNum = Menu();

		if (menuNum == 5)
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
		<< "4. 계좌정보 전체 출력\n" << "5. 프로그램 종료\n" 
		<< "선택 : ";
	int menuNum = 0;
	std::cin >> menuNum;

	return menuNum;
}

void NewAccount(AccountHandler& handler)
{
	int accountNum = 0;
	char name[10] = { 0, };
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
		std::cin >> name;

		std::cout << "입금액: ";
		std::cin >> money;

		std::cout << "이자율: ";
		std::cin >> interest;

		handler.NewAccount(new NormalAccount(accountNum, name, money, interest));
		break;

	case 2:
		std::cout << "\n[신용신뢰계좌 개설]" << std::endl;

		std::cout << "계좌번호 : ";
		std::cin >> accountNum;

		std::cout << "이름 : ";
		std::cin >> name;

		std::cout << "입금액 : ";
		std::cin >> money;

		std::cout << "이자율: ";
		std::cin >> interest;
		
		std::cout << "신용등급(1toA, 2toB, 3toC): ";
		std::cin >> creditRating;

		handler.NewAccount(new HighCreditAccount(accountNum, name, money, interest, creditRating));
		break;
	}
}

void Deposit(AccountHandler& handler)
{
	std::cout << "\n[입 금]" << std::endl;

	std::cout << "계좌번호 : ";
	int accountNum = 0;
	std::cin >> accountNum;

	std::cout << "입금액 : ";
	int money = 0;
	std::cin >> money;

	handler.Deposit(accountNum, money);
}

void WithDraw(AccountHandler& handler)
{
	std::cout << "\n[출 금]" << std::endl;

	std::cout << "계좌번호 : ";
	int accountNum = 0;
	std::cin >> accountNum;

	std::cout << "출금액 : ";
	int money = 0;
	std::cin >> money;

	handler.WithDraw(accountNum, money);
}