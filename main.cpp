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

	// Account ��ü�鸦 �����ϴ� ����Ʈ, �� �������� �����ϴ� ����Ʈ
	list<Account> accList; 
	list<Account>::iterator it;

	while (1) {
		system("cls");
		cout << "- ȸ�� ��� -" << endl;
		for (it = accList.begin(); it != accList.end(); it++)
			cout << it->getID() << endl;
		cout << endl;

		cout << "*********************" << endl;
		cout << "< ���� SNS ���α׷� >" << endl;
		cout << "1. �α���\n2. ȸ������\n3. ����" << endl;
		cout << "*********************" << endl;
		menuNum = inputMenuNum("���� : ", 3);
		switch (menuNum)
		{
		case 1: login(accList); break;
		case 2: signUp(accList); break;
		case 3: return;
		}
	}
}
