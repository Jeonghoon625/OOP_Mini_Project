#include "AccountHandler.h"

//���������� ���� ����ü�� Ŭ������ �����Ѵ�.
//ĸ��ȭ, ��������, ������, �Ҹ��ڸ� ����Ͽ� �����Ѵ�.
//�ΰ��� ���� ������ �ִ�.
//����� ���ڿ� �����͸� ���� �Ҵ� ���·� �����ϰ�,
//���� ������ ��ü �迭�� �ƴ� ��ü ������ �迭�� ����Ͽ� ��ü�� �����Ѵ�.
//���� �Ҵ��� �޴� ��������� �Ҵ��� �Ͼ�� ���� ���簡 ����ǵ��� �����Ѵ�.
//��� ������ �� ������ �Ͼ�� �ȵǴ� ��� �Լ��� const �Լ��� �����Ѵ�.

//������������ �����ϴ� ��Ʈ�� Ŭ������ �����Ѵ�.�츮�� �����ϰ� �ִ� Banking System�� �ֿ����� ������ ����. 1. ���� ����
//2. �� ��
//3. �� ��
//4. �������� ��ü ���
//�̷��� ����� �����Լ��� ���ؼ� �����Ǿ� �ִ�.
//�׷��� ��ü���⿡�� '����'�̶�� �������������� �ʴ´�.
//��� C++������ �����Լ��� ���������� ������ ����ϰ� ������, 
//�̴� ��ü�������α׷����� ���� ���� �ƴϴ� ������ ������� �ʴ� ���� ����.
//����� ������ ���� ��Ʈ�� Ŭ������ �����Ű��, �츮�� �����ϰ� �ִ� �ܰ躰 ������Ʈ���������Լ����� ���� �� �ִ�.
//�̵��� �ϳ��� ��Ʈ�� Ŭ������ ���� �� �ֱ� �����̴�.�̷��� �Ǹ���Ʈ�� Ŭ������ ���α׷��� ����� ������ ����ϰ� �ǹǷ�, 
//��Ʈ�� Ŭ������ ���ݿ� �����Ѵ�.�׷��̹� �ܰ迡�� �������� �� ��Ʈ�� Ŭ������ ��������� ���ؼ� ������ ���� �帮�ڴ�.
//
//1. AccountHandler��� �̸��� ��Ʈ�� Ŭ������ �����ϰ�, �ռ� ������ �����Լ�������Ŭ������ ����Լ��� ���Խ�Ų��.
//2. Account ��ü�� ������ ���� ������ �迭�� ������ �� Ŭ������ ����� ���Խ�Ų��. 
//3. AccountHandler Ŭ������ ������� ���α׷��� ����ǵ��� main �Լ��� �����Ѵ�

int Menu();

void NewAccount(Account* account, int* account_idx);
//
//void Deposit(Account* account, const int account_idx);
//
//void WithDraw(Account* account, const int account_idx);
//
//int FileSave(Account* account, const int account_idx);
//
//int FileLoad(Account* account, int* account_idx);
//
//void PrintAccount(Account* account, const int account_idx);

int main()
{

	while (1)
	{
		int menuNum = Menu();

		if (menuNum == 7)
		{
			break;
		}

		switch (menuNum)
		{
		case 1:
			NewAccount();
		

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
		<< "4. �������� ��ü ���\n" << "5. �� ��\n" << "6. �� ��\n"
		<< "7. �� ��\n" << "���� : ";

	int menuNum = 0;
	std::cin >> menuNum;

	return menuNum;
}

void NewAccount(account* account, int* account_idx)
{
	std::cout << "\n[���°���]" << std::endl;

	std::cout << "���¹�ȣ : ";
	std::cin >> account[*account_idx].accountnum;

	std::cout << "�̸� : ";
	std::cin >> account[*account_idx].name;

	std::cout << "�Աݾ� : ";
	std::cin >> account[*account_idx].ballance;

	(*account_idx)++;
}

//void Deposit(Account* account, const int account_idx)
//{
//	int accountNum = 0;
//	int find_idx = -1;
//
//	std::cout << "\n[�� ��]" << std::endl;
//
//	std::cout << "���¹�ȣ : ";
//
//	std::cin >> accountNum;
//
//	for (int i = 0; i < account_idx; i++)
//	{
//		if (account[i].accountNum == accountNum)
//		{
//			find_idx = i;
//		}
//	}
//
//	if (find_idx < 0)
//	{
//		std::cout << "���� ������ �����ϴ�." << std::endl;
//	}
//	else
//	{
//		std::cout << "�Աݾ� : ";
//		int deposit = 0;
//		std::cin >> deposit;
//		account[find_idx].ballance += deposit;
//		std::cout << "�ԱݿϷ�" << std::endl;
//	}
//}


//void WithDraw(Account* account, const int account_idx)
//{
//	int accountNum = 0;
//	int find_idx = -1;
//
//	std::cout << "\n[�� ��]" << std::endl;
//
//	std::cout << "���¹�ȣ : ";
//	std::cin >> accountNum;
//
//	find_idx = -1;
//	for (int i = 0; i < ACCOUNT_MAX; i++)
//	{
//		if (account[i].accountNum == accountNum)
//		{
//			find_idx = i;
//		}
//	}
//
//	if (find_idx < 0)
//	{
//		std::cout << "���� ������ �����ϴ�." << std::endl;
//	}
//	else
//	{
//		std::cout << "��ݾ� : ";
//		int withdrawal = 0; // ���
//		std::cin >> withdrawal;
//
//		if (account[find_idx].ballance - withdrawal < 0)
//		{
//			std::cout << "���� �ܾ��� �����մϴ�." << std::endl;
//		}
//		else
//		{
//			account[find_idx].ballance -= withdrawal;
//			std::cout << "��ݿϷ�" << std::endl;
//		}
//	}
//}
//
//void PrintAccount(Account* account, const int account_idx)
//{
//	if (account_idx == 0)
//	{
//		std::cout << "������ ���°� �����ϴ�." << std::endl;
//	}
//
//	else
//	{
//		for (int i = 0; i < account_idx; i++)
//		{
//			std::cout << "\n���¹�ȣ : " << account[i].accountNum << std::endl;
//			std::cout << "�̸� : " << account[i].name << std::endl;
//			std::cout << "�ܾ� : " << account[i].ballance << std::endl;
//		}
//	}
//}
//
//int FileSave(Account* account, const int account_idx)
//{
//	FILE* fp = NULL;
//	errno_t err = fopen_s(&fp, "Account.bin", "wb");
//
//	if (err != 0)
//	{
//		puts("Error");
//		return -1;
//	}
//
//	fwrite(&account_idx, sizeof(int), 1, fp);
//	fwrite(account, sizeof(Account), account_idx, fp);
//
//	std::cout << "������ ����Ǿ����ϴ�." << std::endl;
//
//	fclose(fp);
//
//	return 0;
//}
//
//int FileLoad(Account* account, int* account_idx)
//{
//	FILE* fp = NULL;
//	errno_t err = fopen_s(&fp, "Account.bin", "rb");
//
//	if (err != 0)
//	{
//		puts("Error");
//		return -1;
//	}
//
//	fread(account_idx, sizeof(int), 1, fp);
//
//	if (*account_idx > ACCOUNT_MAX) // ���� ������ ��� ����� ����
//	{
//		std::cout << "���� �ε� ����" << std::endl;
//	}
//
//	else
//	{
//		fread(account, sizeof(Account), *account_idx, fp);
//	}
//
//	std::cout << "������ �ε�Ǿ����ϴ�." << std::endl;
//
//	fclose(fp);
//
//	return 0;
//}