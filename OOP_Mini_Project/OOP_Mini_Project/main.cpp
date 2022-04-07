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
			std::cout << "�߸� �Է� �ϼ̽��ϴ�." << std::endl;
			break;
		}
	}
}

int Menu()
{
	std::cout << std::endl;
	std::cout << "=Menu=" << std::endl;
	std::cout << "1. ���°���\n" << "2. �� ��\n" << "3. �� ��\n"
		<< "4. �������� ��ü ���\n" << "5. ���α׷� ����\n" 
		<< "���� : ";
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
	std::cout << "\n[���� ���� ����]" << std::endl;
	std::cout << "1. ���뿹�ݰ���" << std::endl;
	std::cout << "2. �ſ�ŷڰ���" << std::endl;
	std::cout << "����: ";
	std::cin >> accountTypeNum;
	
	switch (accountTypeNum)
	{
	case 1:
		std::cout << "\n[���뿹�ݰ��� ����]" << std::endl;

		std::cout << "���¹�ȣ: ";
		std::cin >> accountNum;

		std::cout << "�̸�: ";
		std::cin >> name;

		std::cout << "�Աݾ�: ";
		std::cin >> money;

		std::cout << "������: ";
		std::cin >> interest;

		handler.NewAccount(new NormalAccount(accountNum, name, money, interest));
		break;

	case 2:
		std::cout << "\n[�ſ�ŷڰ��� ����]" << std::endl;

		std::cout << "���¹�ȣ : ";
		std::cin >> accountNum;

		std::cout << "�̸� : ";
		std::cin >> name;

		std::cout << "�Աݾ� : ";
		std::cin >> money;

		std::cout << "������: ";
		std::cin >> interest;
		
		std::cout << "�ſ���(1toA, 2toB, 3toC): ";
		std::cin >> creditRating;

		handler.NewAccount(new HighCreditAccount(accountNum, name, money, interest, creditRating));
		break;
	}
}

void Deposit(AccountHandler& handler)
{
	std::cout << "\n[�� ��]" << std::endl;

	std::cout << "���¹�ȣ : ";
	int accountNum = 0;
	std::cin >> accountNum;

	std::cout << "�Աݾ� : ";
	int money = 0;
	std::cin >> money;

	handler.Deposit(accountNum, money);
}

void WithDraw(AccountHandler& handler)
{
	std::cout << "\n[�� ��]" << std::endl;

	std::cout << "���¹�ȣ : ";
	int accountNum = 0;
	std::cin >> accountNum;

	std::cout << "��ݾ� : ";
	int money = 0;
	std::cin >> money;

	handler.WithDraw(accountNum, money);
}