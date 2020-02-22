#pragma warning (disable : 4996)
#define ID_SIZE 12
#define NAME_SIZE 50
#define ADDR_SIZE 100
#define PHONE_NUMBER_SIZE 12
#define MESSAGE_SIZE 40

#define DIRECTM_INDEX 1
#define TIMELINE_INDEX 2

#include "Account.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include <Windows.h>
using namespace std;

//// �ӽ÷� �־�����ϴ�
//class Account
//{
//private:
//	string myID;
//public:
//	Account(string myID = "") { this->myID = myID; }
//	string getID() { return myID; }
//	Account *getMyObj() { return this; } // Account Ŭ������ �ش� �Լ� �߰� ��Ź�帱�Կ�!
//};

void screen(); 
void signUp(list<Account> &accList);
void login(list<Account> &accList);

void manageMessage(list<Account> &accList, Account *ap);
void manageMyMessage(Account *ap);
void sendMessage(list<Account> &accList, Account *ap);

void manageTimeLine(list<Account> &accList, Account *ap);
void manageMyTimeLine(Account *ap);
void writeTimeLine(Account *ap);
void deleteTimeLine(Account *ap);
void showFriendTimeLine(list<Account> &accList, Account *ap);

void manageFriend(list<Account> &accList, Account *ap);
void showFollowing(list<Account> &accList, Account *ap);
void showFollower(Account *ap);
void manageInfo(Account *ap);
bool withDrawAccount(list<Account> &accList, list<Account>::iterator it);

void inputInfoString(const char *stp, string &str, int num);
int inputMenuNum(const char *message, int n);
int inputInteger(const char *message);
void myFlush();

int main()
{
	screen();
	return 0;
}

void screen()
{
	int menuNum;
	list<Account> accList; // Account ��ü�鸦 �����ϴ� ����Ʈ, �� �������� �����ϴ� ����Ʈ

	while (1) {
		system("cls");
		cout << "*****************" << endl;
		cout << "< ���� SNS ���α׷� >" << endl;
		cout << "1. �α���\n2. ȸ������\n3. ����" << endl;
		cout << "*****************" << endl;
		menuNum = inputMenuNum("���� : ", 3);	
		switch (menuNum) 
		{
		case 1: login(accList); break;
		case 2: signUp(accList); break;
		case 3: return;
		}
	}
}

// ȸ������ �Լ�
// �������� �Է� �� information, Account ��ü ����
// ������ Account ��ü�� ����Ʈ�� �߰�
void signUp(list<Account> &accList)
{
	list<Account>::iterator it;
	string id, name, addr, phoneNumber;
	int age;
	char gender;

	system("cls");
	cout << "* ȸ�� ���� �Է� *" << endl;

	// ID�� ���������� �Էµ� ������ ���Է¹���
	while (1) {
		inputInfoString("���̵� : ", id, ID_SIZE);
		// ����Ʈ�� ��������� �ߺ� �˻� �ʿ����
		if (accList.empty()) { 
			cout << "��� ������ ���̵� �Դϴ�." << endl;
			break; 
		}
		// id �ߺ��˻�
		for (it = accList.begin(); it != accList.end(); it++) 
			if (it->getID() == id) { break; }
		if (it == accList.end()) { 
			cout << "��� ������ ���̵� �Դϴ�." << endl;
			break; 
		}
		cout << "�̹� �����ϴ� ���̵� �Դϴ�. �ٽ� �Է����ּ���." << endl;
	}
	inputInfoString("�̸� : ", name, NAME_SIZE);
	age = inputInteger("���� : ");
	inputInfoString("������ : ", addr, ADDR_SIZE);
	inputInfoString("��ȭ��ȣ : ", phoneNumber, PHONE_NUMBER_SIZE);
	while (1) {
		cout << "����(M/F) : ";
		cin >> gender;
		if (gender == 'M' || gender == 'm' || gender == 'F' || gender == 'f') { break; }
		myFlush();
	}

	// account ��ü ���� �� ����Ʈ�� �߰�
	Account temp(name, age, addr, gender, phoneNumber, id);
	cout << "check" << endl;
	accList.push_back(temp);

	cout << "������ �����Ǿ����ϴ�." << endl;
	cout << "2�� �� ����ȭ������ ���ư��ϴ�..." << endl;
	Sleep(2000);
}

// �α��� �Լ�
void login(list<Account> &accList)
{
	list<Account>::iterator it;
	string id;
	int menuNum;
	Account *ap;

	system("cls");
	cout << "* �α��� �޴� *" << endl;
	inputInfoString("���̵� �Է� : ", id, ID_SIZE);

	// ����Ʈ�� ���������(������ 0�� ��ϵǾ� �ִ� ����) ����ȭ������ �̵�
	if (accList.empty()) { 
		cout << "�߸��� ���̵� �Դϴ�" << endl;
		cout << "2�� �� ����ȭ������ ���ư��ϴ�..." << endl;
		Sleep(2000);
		return; 
	}
	// ����Ʈ�� �ش� ���̵� �������� ������ ����ȭ������ �̵�
	for (it = accList.begin(); it != accList.end(); it++) 
		if (it->getID() == id) { break; } // it �� ��������� ��ü�� ����Ŵ(it �� ���ͷ�����)
	if (it == accList.end()) {
		cout << "�߸��� ���̵� �Դϴ�" << endl;
		cout << "2�� �� ����ȭ������ ���ư��ϴ�..." << endl;
		Sleep(2000);
		return;
	}

	// ap �� ��������� ��ü�� ����Ű�� ��(ap �� Account *)
	// ��, ap �� ��������� ��ü�� ��Ʈ��
    ap = it->getMyObj();

	while (1) {
		system("cls");
		cout << "'" << ap->getID() << "'" << " ���� ���� ����" << endl;
		cout << "1. �޼��� ����\n2. Ÿ�Ӷ��� ����\n3. ģ�� ����\n4. ������ ����\n5. �α׾ƿ�\n6. ����Ż��" << endl;
		menuNum = inputMenuNum("���� : ", 6);
		switch (menuNum)
		{
		case 1: manageMessage(accList, ap); break;
		case 2: manageTimeLine(accList, ap); break;
		case 3: manageFriend(accList, ap); break;
		case 4: manageInfo(ap); break;
		case 5: return;
		case 6:
			if (withDrawAccount(accList, it) == true) { return; }
			else { break; }
		}
	}
}

void manageMessage(list<Account> &accList, Account *ap)
{
	int menuNum;
	while (1) {
		system("cls");
		cout << "'" << ap->getID() << "'" << " ���� ���� ����" << endl;
		cout << "* �޽��� ���� �޴� *" << endl;
		cout << "1. �� ������(Ȯ��/����)\n2. �޽��� ����\n3. ������" << endl;
		menuNum = inputMenuNum("���� : ", 3);
		switch (menuNum)
		{
		case 1: manageMyMessage(ap);  break;
		case 2: sendMessage(accList, ap);  break;
		case 3: return;
		}
	}
}

// �� ������
void manageMyMessage(Account *ap)
{
	int messageIndex;
	char answer;
	while (1) {
		system("cls");
		cout << "'" << ap->getID() << "'" << " ���� ���� ����" << endl;
		cout << "* �� ������ *" << endl;

		//// �� �޽��� �ϰ� ���
		//ap->prnPage(DIRECTM_INDEX);

		messageIndex = inputInteger("������ �޽��� ��ȣ�� �Է� : ");
		cout << "�����Ͻðڽ��ϱ�?(Y/N) : ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y') {

			//// �ش� �ε����� �޽��� ����
			// ap->deletePage(DIRECTM_INDEX, num);
            //// ������ ���� ä��� �۾�

			cout << "������ �Ϸ�Ǿ����ϴ�.." << endl;
			cout << "2�� �� �޽��� ���� �޴��� ���ư��ϴ�..." << endl;
			Sleep(2000);
			return;
		}
		else if (answer == 'n' || answer == 'N') {
			cout << "������ ������� �ʾҽ��ϴ�." << endl;
			cout << "2�� �� �޽��� ���� �޴��� ���ư��ϴ�..." << endl;
			Sleep(2000);
			return;
		}
		else {
			cout << "�������� ���ڸ� �Է��Ͻʽÿ�." << endl;
			myFlush();
		}
		
	}
}

// �޽��� ����
void sendMessage(list<Account> &accList, Account *ap)
{
	list<Account>::iterator it;
	string id, message;
	system("cls");
	cout << "'" << ap->getID() << "'" << " ���� ���� ����" << endl;
	inputInfoString("�޴� ����� ���̵� �Է� : ", id, ID_SIZE);

	// ����Ʈ�� �Է¹��� ���̵� �������� ������ �޽��� ���� ȭ������ �̵�
	for (it = accList.begin(); it != accList.end(); it++)
		if (it->getID() == id) { break; } 
	if (it == accList.end()) {
		cout << "�߸��� ���̵� �Դϴ�" << endl;
		cout << "2�� �� �޽��� ���� �޴��� ���ư��ϴ�..." << endl;
		Sleep(2000);
		return;
	}
	
	inputInfoString("���� �޽��� �Է� : ", message, MESSAGE_SIZE);

	// �ڽ��� ���̵� �Է��� ��� �ڽ��� �޽����Կ� �߰��ϰ� �޽��� ����ȭ������ �̵�
	if (id == ap->getID()) {
		// �޽����Կ� �޽��� �߰�
		// �޽������� �����ִ� ��� �о�� ����
		cout << "* ������ �޽��� ������ �Ϸ�Ǿ����ϴ� *" << endl;
		cout << "2�� �� �޽��� ���� �޴��� ���ư��ϴ�..." << endl;
		Sleep(2000);
		return;
	}

	// �޽����� ���� ��뿡�Ը� ���� �� ����
	for (it = accList.begin(); it != accList.end(); it++) {
		// ���� �ȷο찡 �Ǿ��ִ� ��� �� ����
		//if (it->followerCheck(ap->getID()) == true && ap->follwerCheck(it->getID()) == true) {
		//	// �� �߿��� �Է��� ���̵�� ��ġ�ϴ� ��ü�� ã����
		//	if (it->getID() == id) {
		//		// it �� ����Ű�� ��ü(�޽����� �޴� ���)�� �޽����Կ� �޽����� �߰�
		//		// �޽������� �����ִ� ��� �о�� ����
		//	}
		// }	
	}
	cout << "* ������ �Ϸ� �Ǿ����ϴ� * " << endl;
	cout << "2�� �� �޽��� ���� �޴��� ���ư��ϴ�..." << endl;
	Sleep(2000);
}

void manageTimeLine(list<Account> &accList, Account *ap)
{
	int menuNum;
	while (1) {
		system("cls");
		cout << "'" << ap->getID() << "'" << " ���� ���� ����" << endl;
		cout << "* Ÿ�Ӷ��� ���� �޴� *" << endl;
		cout << "1. �� Ÿ�Ӷ��� ����\n2. ģ�� Ÿ�Ӷ��� ����\n3. ������" << endl;
		menuNum = inputMenuNum("���� : ", 3);
		switch (menuNum)
		{
		case 1: manageMyTimeLine(ap);  break;
		case 2: showFriendTimeLine(accList, ap);  break;
		case 3: return;
		}
	}
}

void manageMyTimeLine(Account *ap)
{
	int menuNum;
	while (1) {
		system("cls");
		cout << "'" << ap->getID() << "'" << " ���� ���� ����" << endl;
		cout << "* �� Ÿ�Ӷ��� �޴� *" << endl;
		
		//// �� Ÿ�Ӷ��� �ϰ� ���
		//ap->prnPage(TIMELINE_INDEX);
		
		cout << "1. �� Ÿ�Ӷ��� �ۼ�\n2. �� Ÿ�Ӷ��� ����\n3. ������" << endl;
		menuNum = inputMenuNum("���� : ", 3);
		switch (menuNum)
		{
		case 1: writeTimeLine(ap);  break;
		case 2: deleteTimeLine(ap);  break;
		case 3: return;
		}
	}
}

void writeTimeLine(Account *ap)
{
	string timeLineMessage;
	system("cls");
	inputInfoString("Ÿ�Ӷ��� �ۼ��� ���� �Է� : ", timeLineMessage, 40);

	//// �� Ÿ�Ӷ��ο� ���� �߰� 
	// Ÿ�Ӷ����� ��á�� ��� �о��
	cout << "�ۼ� �Ϸ�Ǿ����ϴ�." << endl; 
	cout << "2�� �� �޽��� ���� �޴��� ���ư��ϴ�..." << endl;
	Sleep(2000);
}

void deleteTimeLine(Account *ap)
{
	int timeLineIndex;
	system("cls");
	timeLineIndex = inputMenuNum("������ Ÿ�Ӷ��� ��ȣ : ", 9999); // 9999��� Ÿ�Ӷ��� ���� ������
	
    //// �ش� �ε����� Ÿ�Ӷ��� ����
	//ap->deletePage(TIMELINE_INDEX, timeLineNum);
	//// ������ ���� ä��� �۾�
	cout << "���� �Ϸ�Ǿ����ϴ�." << endl;
	cout << "2�� �� �޽��� ���� �޴��� ���ư��ϴ�..." << endl;
	Sleep(2000);
}

void showFriendTimeLine(list<Account> &accList, Account *ap)
{
	list<Account>::iterator it;
	system("cls");
	cout << "'" << ap->getID() << "'" << " ���� ���� ����" << endl;
	// ģ������ Ÿ�Ӷ��� �ϰ� ���
	// ���⼭ ģ���� ���ȵǾ��ִ� ����鸸 �ش�
	for (it = accList.begin(); it != accList.end(); it++) {
		//// ���� �ȷο찡 �Ǿ��ִ� ��� �� ����
		//if (it->followerCheck(ap->getID()) == true && ap->follwerCheck(it->getID()) == true) {
		//	cout << "'" << it->getID() << "'" << " ���� Ÿ�Ӷ���" << endl;
		//	it->prnPage(TIMELINE_INDEX);
		//	cout << endl;
		//}
	}
	// ���ͳ� �ƹ�Ű �Է½� Ÿ�Ӷ��� �޴��� �̵�
}

// ģ�� ���� �Լ�
void manageFriend(list<Account> &accList, Account *ap)
{
	int menuNum;
	while (1) {
		system("cls");
		cout << "'" << ap->getID() << "'" << " ���� ���� ����" << endl;
		cout << "* ģ�� ���� �޴� *" << endl;
		cout << "1. �ȷ��� ����\n2. �ȷο� ����\n3. ������" << endl;
		menuNum = inputMenuNum("���� : ", 3);
		switch (menuNum)
		{
		case 1: showFollowing(accList, ap); break;
		case 2: showFollower(ap); break;
		case 3: return;
		}
	}
}

// ���� �ȷ����� ģ�� ����� ����ϰ� 
// �ȷ��� �߰�, ������ �����ϴ� �Լ�
void showFollowing(list<Account> &accList, Account *ap)
{
	list<Account>::iterator it;
	string id;
	int menuNum;
	while (1) {
		system("cls");
		cout << "'" << ap->getID() << "'" << " ���� ���� ����" << endl;
		cout << "* �ȷ��� �޴� *" << endl;
		//// �ȷ����� ģ�� ��� ���
		//ap->prnFollowing();
		cout << "1. �ȷ��� �߰�\n2. �ȷ��� ����\n3. ������" << endl;
		menuNum = inputMenuNum("���� : ", 3);
		switch (menuNum) {
		case 1:
			system("cls");
			cout << "'" << ap->getID() << "'" << " ���� ���� ����" << endl;
			inputInfoString("�߰��� ģ�� ���̵� �˻� : ", id, ID_SIZE);

			for (it = accList.begin(); it != accList.end(); it++)
				if (it->getID() == id) { break; } // it �� �ȷ����� ������ ��ü�� ����Ŵ
			// ����Ʈ�� �ش� ���̵� �������� �ʴ� ��� ģ������ �޴��� �̵�
			if (it == accList.end()) {
				cout << "�������� �ʴ� �����Դϴ�." << endl;
				cout << "2�� �� �ȷ��� �޴��� ���ư��ϴ�..." << endl;
				Sleep(2000);
				break;
			}
			// �ڽ��� ���̵� �˻��� ��� ģ������ �޴��� �̵�
			if (it->getID() == ap->getID()) {
				cout << "�ڽ��� ������ �ȷο� �� �� �����ϴ�." << endl;
				cout << "2�� �� �ȷ��� �޴��� ���ư��ϴ�..." << endl;
				Sleep(2000);
				break;
			}

			//// �Է¹��� ���̵� �� �ȷ��� ��Ͽ� ���� ��� ��Ͽ� �߰�
			//if ((ap->followingCheck(id)) == false) {
			//	ap->addFollowing(id); // �� �ȷ��� ��Ͽ� ���� ���̵� �߰�
			//	it->addFollower(ap->getID()); // ���� �ȷο� ��Ͽ� �� ���̵� �߰�
			//	cout << "�߰� �Ǿ����ϴ�." << endl;
			//}
			//else { cout << "�̹� �ȷ��� �Ǿ��ִ� �����Դϴ�." << endl; }
			break;

		case 2:
			system("cls");
			cout << "'" << ap->getID() << "'" << " ���� ���� ����" << endl;
			inputInfoString("������ ģ�� ���̵� �˻� : ", id, ID_SIZE);

			for (it = accList.begin(); it != accList.end(); it++)
				if (it->getID() == id) { break; } // it �� �ȷ��� ������ ������ ��ü�� ����Ŵ
			// ����Ʈ�� �ش� ���̵� �������� �ʴ� ��� ģ������ �޴��� �̵�
			if (it == accList.end()) {
				cout << "�������� �ʴ� �����Դϴ�." << endl;
				cout << "2�� �� �ȷ��� �޴��� ���ư��ϴ�..." << endl;
				Sleep(2000);
				break;
			}
			// �ڽ��� ���̵� �˻��� ��� ģ������ �޴��� �̵�
			if (it->getID() == ap->getID()) {
				cout << "�ڽ��� ������ �ȷο� ������ �� �����ϴ�." << endl;
				cout << "2�� �� �ȷ��� �޴��� ���ư��ϴ�..." << endl;
				Sleep(2000);
				break;
			}
			//// �Է¹��� ���̵� �� �ȷ��� ��Ͽ� �ִ� ��� ��Ͽ��� ����
			//if ((ap->followingCheck(id)) == true) {
			//	ap->delFollowing(id); // �� �ȷ��� ��Ͽ��� ���� ���̵� ����
			//	it->delFollower(ap->getID()); // ���� �ȷο� ��Ͽ��� �� ���̵� ����
			//	cout << "���� �Ǿ����ϴ�." << endl;
			//}
			//else { cout << "�ȷ��� �Ǿ����� ���� �����Դϴ�." << endl; }
			break;
		case 3: return;
		}
	}
}

// ������ �ȷο� �Ǿ��ִ� ģ�� ��� ��� �Լ�
void showFollower(Account *ap)
{
	cout << "'" << ap->getID() << "'" << " ���� �ȷο�" << endl;
	// ap->prnFollower();
	// ����ġ�� ģ�� ���� �޴��� �̵�
	// ���� �ۼ�
}

// �� ���� ���� �Լ�
void manageInfo(Account *ap)
{
	int num;
	system("cls");
	cout << "'" << ap->getID() << "'" << " ���� ���� ����" << endl;
	cout << "* �� ���� ���� �޴� *" << endl;
	// �� ���� �ϰ� ���(���̵� ����)
	// ���� �ۼ�
	num = inputMenuNum("������ �׸� �Է� : ", 5);
	// �ش���������
	// ���� �ۼ�
}

// ���� Ż�� �Լ�
// Ż�� ���� �� true, �ƴϸ� false �� ����
bool withDrawAccount(list<Account> &accList, list<Account>::iterator it)
{
	char answer;
	while (1) {
		cout << "������ Ż���Ͻðڽ��ϱ�?(Y/N) : ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y') {
			accList.erase(it);
			cout << "Ż�� �Ϸ�Ǿ����ϴ�." << endl;
			cout << "2�� �� ����ȭ������ ���ư��ϴ�..." << endl;
			Sleep(2000);
			return true;
		}
		else if (answer == 'n' || answer == 'N') {
			cout << "Ż�� �������� �ʽ��ϴ�." << endl;
			cout << "2�� �� ����ȭ������ ���ư��ϴ�..." << endl;
			Sleep(2000);
			return false;
		}
		else {
			cout << "�������� ���ڸ� �Է��Ͻʽÿ�." << endl;
			myFlush();
		}
	}
}

// ID, ��ȭ��ȣ�� ���� �Է�	�Ұ�
// �̸�, �������� ���� �Է� ����
// ���̴� num �̸����θ� �Է¹���
void inputInfoString(const char *stp, string &str, int num)
{
	int i;
	char temp[20];
	for (i = 0; stp[i] != ' '; i++) {
		temp[i] = stp[i];
	} temp[i] = '\0';

	if (!strcmp(temp, "�߰���") || !strcmp(temp, "������") || !strcmp(temp, "�޴�"))
		strcpy(temp, "���̵�");
	if (!strcmp(temp, "����"))
		strcpy(temp, "�޽���");

	while (1) {
		cout << stp;

		// �̸�, ������, Ÿ�Ӷ���, �޽����� ���� �Է� ����
		if (!strcmp(stp, "�̸� : ") || !strcmp(stp, "������ : ") || !strcmp(temp, "Ÿ�Ӷ���") || !strcmp(temp, "�޽���")) {
			getline(cin, str);
			if (str.length() >= (unsigned int)num) {
				cout << temp << "�� " << num << "�ڸ� ���� �� �����ϴ�." << endl;
				continue;
			}
			break;
		}

		cin >> str;
		if (cin.get() == '\n') {
			if (str.length() >= (unsigned int)num) {
				cout << temp << "�� " << num << "�ڸ� ���� �� �����ϴ�." << endl;
				continue;
			}
			break;
		}
		// ID, ��ȭ��ȣ�� �����Է� �Ұ�
		else {
			cout << temp << "���� ������ �Է��� �� �����ϴ�." << endl;
			myFlush();
		}
	}
}


// �޴���ȣ �Է��Լ�
// 1 ~ n ������ ���ڸ� �Է¹޵��� ���� ó�� 
int inputMenuNum(const char *message, int n)
{
	int number;

	while (1) {
		cout << message;
		cin >> number;
		if (cin.get() == '\n') { 
			if (number >= 1 && number <= n)
				return number;
			else {
				cout << "�������� �ʴ� �޴���ȣ�Դϴ�. �ٽ� �Է��ϼ���." << endl;
				continue;
			}
		}
		cout << "�������� �ʴ� �޴���ȣ�Դϴ�. �ٽ� �Է��ϼ���." << endl;
		myFlush();
	}
}

 // message�� ����ϰ� ������ �Է� �޾� ����
 // ����, �Ǽ�, ����, 0 �Է� ����ó��
int inputInteger(const char *message)
{
	int number;

	while (1) {
		cout << message;
		cin >> number;

		if (cin.get() == '\n') {
			if (number >= 1) { return number; }
			else { continue; }
		}

		myFlush();
	}
}

void myFlush()
{
	cin.clear(); 
	while (cin.get() != '\n');  
}