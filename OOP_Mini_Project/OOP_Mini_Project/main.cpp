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
		<< "4. �������� ��ü ���\n" << "5. �������� ����\n" << "6. ���α׷� ����\n" 
		<< "���� : ";
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
		cin >> name;

		std::cout << "�Աݾ�: ";
		std::cin >> money;

		std::cout << "������: ";
		std::cin >> interest;

		if (handler.FindAccount(accountNum) < 0)
		{
			handler.NewAccount(new NormalAccount(accountNum, name, money, interest));
		}
		else
		{
			std::cout << "�̹� ������ ���¹�ȣ�� ������ ���°� �ֽ��ϴ�." << std::endl;
		}

		break;

	case 2:
		std::cout << "\n[�ſ�ŷڰ��� ����]" << std::endl;

		std::cout << "���¹�ȣ : ";
		std::cin >> accountNum;

		std::cout << "�̸� : ";
		cin >> name;

		std::cout << "�Աݾ� : ";
		std::cin >> money;

		std::cout << "������: ";
		std::cin >> interest;
		
		std::cout << "�ſ���(1toA, 2toB, 3toC): ";
		std::cin >> creditRating;

		if (handler.FindAccount(accountNum) < 0)
		{
			handler.NewAccount(new HighCreditAccount(accountNum, name, money, interest, creditRating));
		}
		else
		{
			std::cout << "�̹� ������ ���¹�ȣ�� ������ ���°� �ֽ��ϴ�." << std::endl;
		}

		break;
	}
}

void DeleteAccount(AccountHandler& handler)
{
	int accountNum = 0;

	std::cout << "\n[������ ���� ��ȣ �Է�]" << std::endl;
	std::cin >> accountNum;

	int find_idx = handler.FindAccount(accountNum);

	if (find_idx < 0)
	{
		std::cout << "�ش��ϴ� ���°� �������� �ʽ��ϴ�." << std::endl;
	}
	else
	{
		handler.DeleteAccount(find_idx);
	}
}

void Deposit(AccountHandler& handler)
{
	std::cout << "\n[�� ��]" << std::endl;

	std::cout << "���¹�ȣ : ";
	int accountNum = 0;
	std::cin >> accountNum;

	while (1)
	{
		std::cout << "�Աݾ� : ";
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
	std::cout << "\n[�� ��]" << std::endl;

	std::cout << "���¹�ȣ : ";
	int accountNum = 0;
	std::cin >> accountNum;

	while (1)
	{
		std::cout << "��ݾ� : ";
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