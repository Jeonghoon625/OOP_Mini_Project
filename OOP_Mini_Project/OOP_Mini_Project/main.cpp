#include "AccountHandler.h"

//계좌정보에 관한 구조체를 클래스로 변경한다.
//캡슐화, 정보은닉, 생성자, 소멸자를 고려하여 구현한다.
//두가지 제약 사항이 있다.
//멤버의 문자열 데이터를 동적 할당 형태로 구현하고,
//계좌 정보의 객체 배열이 아닌 객체 포인터 배열을 사용하여 객체을 저장한다.
//동적 할당을 받는 멤버변수에 할당이 일어날때 깊은 복사가 수행되도록 구현한다.
//멤버 변수의 값 변경이 일어나면 안되는 멤버 함수는 const 함수로 구현한다.

//계좌정보들을 관리하는 컨트롤 클래스를 구현한다.우리가 구현하고 있는 Banking System의 주요기능은 다음과 같다. 1. 계좌 개설
//2. 입 금
//3. 출 금
//4. 계좌정보 전체 출력
//이러한 기능은 전역함수를 통해서 구현되어 있다.
//그러나 객체지향에는 '전역'이라는 개념이존재하지 않는다.
//비록 C++에서는 전역함수와 전역변수의 선언을 허용하고 있지만, 
//이는 객체지향프로그래밍을 위한 것은 아니니 가급적 사용하지 않는 것이 좋다.
//기능적 성격이 강한 컨트롤 클래스를 등장시키면, 우리가 구현하고 있는 단계별 프로젝트에서전역함수들을 없앨 수 있다.
//이들을 하나의 컨트롤 클래스로 묶을 수 있기 때문이다.이렇게 되면컨트롤 클래스는 프로그램의 기능적 측면을 담당하게 되므로, 
//컨트롤 클래스의 성격에 부합한다.그럼이번 단계에서 구현해햐 할 컨트롤 클래스의 구현방법에 대해서 간단히 말씀 드리겠다.
//
//1. AccountHandler라는 이름의 컨트롤 클래스를 정의하고, 앞서 정의한 전역함수들을이클래스의 멤버함수에 포함시킨다.
//2. Account 객체의 저장을 위해 선언한 배열과 변수도 이 클래스의 멤버에 포함시킨다. 
//3. AccountHandler 클래스를 기반으로 프로그램이 실행되도록 main 함수를 변경한다

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
		<< "4. 계좌정보 전체 출력\n" << "5. 저 장\n" << "6. 로 드\n"
		<< "7. 종 료\n" << "선택 : ";

	int menuNum = 0;
	std::cin >> menuNum;

	return menuNum;
}

void NewAccount(account* account, int* account_idx)
{
	std::cout << "\n[계좌개설]" << std::endl;

	std::cout << "계좌번호 : ";
	std::cin >> account[*account_idx].accountnum;

	std::cout << "이름 : ";
	std::cin >> account[*account_idx].name;

	std::cout << "입금액 : ";
	std::cin >> account[*account_idx].ballance;

	(*account_idx)++;
}

//void Deposit(Account* account, const int account_idx)
//{
//	int accountNum = 0;
//	int find_idx = -1;
//
//	std::cout << "\n[입 금]" << std::endl;
//
//	std::cout << "계좌번호 : ";
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
//		std::cout << "계좌 정보가 없습니다." << std::endl;
//	}
//	else
//	{
//		std::cout << "입금액 : ";
//		int deposit = 0;
//		std::cin >> deposit;
//		account[find_idx].ballance += deposit;
//		std::cout << "입금완료" << std::endl;
//	}
//}


//void WithDraw(Account* account, const int account_idx)
//{
//	int accountNum = 0;
//	int find_idx = -1;
//
//	std::cout << "\n[출 금]" << std::endl;
//
//	std::cout << "계좌번호 : ";
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
//		std::cout << "계좌 정보가 없습니다." << std::endl;
//	}
//	else
//	{
//		std::cout << "출금액 : ";
//		int withdrawal = 0; // 출금
//		std::cin >> withdrawal;
//
//		if (account[find_idx].ballance - withdrawal < 0)
//		{
//			std::cout << "계좌 잔액이 부족합니다." << std::endl;
//		}
//		else
//		{
//			account[find_idx].ballance -= withdrawal;
//			std::cout << "출금완료" << std::endl;
//		}
//	}
//}
//
//void PrintAccount(Account* account, const int account_idx)
//{
//	if (account_idx == 0)
//	{
//		std::cout << "개설된 계좌가 없습니다." << std::endl;
//	}
//
//	else
//	{
//		for (int i = 0; i < account_idx; i++)
//		{
//			std::cout << "\n계좌번호 : " << account[i].accountNum << std::endl;
//			std::cout << "이름 : " << account[i].name << std::endl;
//			std::cout << "잔액 : " << account[i].ballance << std::endl;
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
//	std::cout << "파일이 저장되었습니다." << std::endl;
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
//	if (*account_idx > ACCOUNT_MAX) // 버퍼 오버런 경고 지우기 위해
//	{
//		std::cout << "파일 로드 실패" << std::endl;
//	}
//
//	else
//	{
//		fread(account, sizeof(Account), *account_idx, fp);
//	}
//
//	std::cout << "파일이 로드되었습니다." << std::endl;
//
//	fclose(fp);
//
//	return 0;
//}