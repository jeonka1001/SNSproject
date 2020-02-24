#pragma once
#pragma warning (disable : 4996)

#include "define.h"
#include "Account.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include <Windows.h>
using namespace std;

void signUp(list<Account> &accList); // ȸ������ �Լ�
void login(list<Account> &accList); // �α��� �Լ�

void manageMessage(list<Account> &accList, Account *ap); // �޽��� ���� �Լ�
void manageMyMessage(Account *ap); // �� �޽����� ���� �Լ�
void sendMessage(list<Account> &accList, Account *ap); // �޽��� ���� �Լ�

void manageTimeLine(list<Account> &accList, Account *ap); // Ÿ�� ���� �Լ�
void manageMyTimeLine(Account *ap); // �� Ÿ�� ���� �Լ�
void writeTimeLine(Account *ap); // Ÿ�Ӷ��� �ۼ� �Լ�
void deleteTimeLine(Account *ap); // Ÿ�Ӷ��� ���� �Լ�
void showFriendTimeLine(list<Account> &accList, Account *ap); // ����ģ�� Ÿ�Ӷ��� ���� �Լ�

void manageFriend(list<Account> &accList, Account *ap); // ģ�� ���� �Լ�
void showFollowing(list<Account> &accList, Account *ap); // �ȷ��� ���� �Լ�
void showFollower(Account *ap); // �ȷο� ���� �Լ�
void manageInfo(Account *ap); // �� ���� ���� �Լ� // ���ۼ�
bool withDrawAccount(list<Account> &accList, list<Account>::iterator it); // ���� Ż�� �Լ�

void inputInfoString(const char *stp, string &str, int num); // �� ���� �Է� �Լ�
int inputMenuNum(const char *message, int n); // �޴���ȣ �Է� �Լ�
int inputInteger(const char *message); // ���� �Է� �Լ�
void myFlush();
