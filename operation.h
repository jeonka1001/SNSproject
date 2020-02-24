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

void signUp(list<Account> &accList); // 회원가입 함수
void login(list<Account> &accList); // 로그인 함수

void manageMessage(list<Account> &accList, Account *ap); // 메시지 관리 함수
void manageMyMessage(Account *ap); // 내 메시지함 관리 함수
void sendMessage(list<Account> &accList, Account *ap); // 메시지 전송 함수

void manageTimeLine(list<Account> &accList, Account *ap); // 타임 라인 함수
void manageMyTimeLine(Account *ap); // 내 타임 라인 함수
void writeTimeLine(Account *ap); // 타임라인 작성 함수
void deleteTimeLine(Account *ap); // 타임라인 삭제 함수
void showFriendTimeLine(list<Account> &accList, Account *ap); // 맞팔친구 타임라인 관리 함수

void manageFriend(list<Account> &accList, Account *ap); // 친구 관리 함수
void showFollowing(list<Account> &accList, Account *ap); // 팔로잉 관리 함수
void showFollower(Account *ap); // 팔로워 관리 함수
void manageInfo(Account *ap); // 내 정보 관리 함수 // 미작성
bool withDrawAccount(list<Account> &accList, list<Account>::iterator it); // 계정 탈퇴 함수

void inputInfoString(const char *stp, string &str, int num); // 내 정보 입력 함수
int inputMenuNum(const char *message, int n); // 메뉴번호 입력 함수
int inputInteger(const char *message); // 정수 입력 함수
void myFlush();
