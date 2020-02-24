#include "operation.h"

void screen();
int main()
{
	screen();
	return 0;
}

void screen()
{
	int menuNum;

	// Account 객체들를 관리하는 리스트, 즉 계정들을 관리하는 리스트
	list<Account> accList; 
	list<Account>::iterator it;

	while (1) {
		system("cls");
		cout << "- 회원 목록 -" << endl;
		for (it = accList.begin(); it != accList.end(); it++)
			cout << it->getID() << endl;
		cout << endl;

		cout << "*********************" << endl;
		cout << "< 간단 SNS 프로그램 >" << endl;
		cout << "1. 로그인\n2. 회원가입\n3. 종료" << endl;
		cout << "*********************" << endl;
		menuNum = inputMenuNum("선택 : ", 3);
		switch (menuNum)
		{
		case 1: login(accList); break;
		case 2: signUp(accList); break;
		case 3: return;
		}
	}
}
