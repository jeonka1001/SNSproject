#include "operation.h"

// 회원가입 함수
// 개인정보 입력 후 information, Account 객체 생성
// 생성된 Account 객체를 리스트에 추가
void signUp(list<Account> &accList)
{
	list<Account>::iterator it;
	string id, name, addr, phoneNumber;
	int age;
	char gender;

	system("cls");
	cout << "* 회원 정보 입력 *" << endl;

	// ID가 정상적으로 입력될 때까지 재입력받음
	while (1) {
		inputInfoString("아이디 : ", id, ID_SIZE);
		// 리스트가 비어있으면 중복 검사 필요없음
		if (accList.empty()) {
			cout << "사용 가능한 아이디 입니다." << endl;
			break;
		}
		// id 중복검사
		for (it = accList.begin(); it != accList.end(); it++)
			if (it->getID() == id) { break; }
		if (it == accList.end()) {
			cout << "사용 가능한 아이디 입니다." << endl;
			break;
		}
		cout << "이미 존재하는 아이디 입니다. 다시 입력해주세요." << endl;
	}
	inputInfoString("이름 : ", name, NAME_SIZE);
	age = inputInteger("나이 : ");
	inputInfoString("거주지 : ", addr, ADDR_SIZE);
	inputInfoString("전화번호 : ", phoneNumber, PHONE_NUMBER_SIZE);
	while (1) {
		cout << "성별(M/F) : ";
		cin >> gender;
		if (gender == 'M' || gender == 'm' || gender == 'F' || gender == 'f') { break; }
		myFlush();
	}

	// account 객체 생성 뒤 리스트에 추가
	Account temp(name, age, addr, gender, phoneNumber, id);
	accList.push_back(temp);

	cout << "계정이 생성되었습니다." << endl;
	cout << "2초 뒤 시작화면으로 돌아갑니다..." << endl;
	Sleep(2000);
}

// 로그인 함수
void login(list<Account> &accList)
{
	list<Account>::iterator it;
	string id;
	int menuNum;
	Account *ap;

	system("cls");
	cout << "* 로그인 메뉴 *" << endl;
	inputInfoString("아이디 입력 : ", id, ID_SIZE);

	// 리스트가 비어있으면(계정이 0개 등록되어 있는 상태) 시작화면으로 이동
	if (accList.empty()) {
		cout << "잘못된 아이디 입니다" << endl;
		cout << "2초 뒤 시작화면으로 돌아갑니다..." << endl;
		Sleep(2000);
		return;
	}
	// 리스트에 해당 아이디가 존재하지 않으면 시작화면으로 이동
	for (it = accList.begin(); it != accList.end(); it++)
		if (it->getID() == id) { break; } // it 이 현재계정의 객체를 가리킴(it 은 이터레이터)
	if (it == accList.end()) {
		cout << "잘못된 아이디 입니다" << endl;
		cout << "2초 뒤 시작화면으로 돌아갑니다..." << endl;
		Sleep(2000);
		return;
	}

	// ap 가 현재계정의 객체를 가리키게 함(ap 는 Account *)
	// 즉, ap 로 현재계정의 객체를 컨트롤
	ap = it->getMyObj();

	while (1) {
		system("cls");
		cout << "'" << ap->getID() << "'" << " 님의 계정 관리" << endl;
		cout << "1. 메세지 관리\n2. 타임라인 관리\n3. 친구 관리\n4. 내정보 관리\n5. 로그아웃\n6. 계정탈퇴" << endl;
		menuNum = inputMenuNum("선택 : ", 6);
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
		cout << "'" << ap->getID() << "'" << " 님의 계정 관리" << endl;
		cout << "* 메시지 관리 메뉴 *" << endl;
		cout << "1. 내 보관함(확인/삭제)\n2. 메시지 전송\n3. 나가기" << endl;
		menuNum = inputMenuNum("선택 : ", 3);
		switch (menuNum)
		{
		case 1: manageMyMessage(ap);  break;
		case 2: sendMessage(accList, ap);  break;
		case 3: return;
		}
	}
}

// 내 보관함
void manageMyMessage(Account *ap)
{
	int messageIndex;
	char answer;
	while (1) {
		system("cls");
		cout << "'" << ap->getID() << "'" << " 님의 계정 관리" << endl;
		cout << "* 내 보관함 *" << endl;

		// 내 메시지 일괄 출력
		ap->prnPage(DIRECTM_INDEX);

		cout << "메세지를 삭제하시겠습니까?(Y/N) : ";
		cin >> answer;

		if (answer == 'y' || answer == 'Y') {

			messageIndex = inputInteger("삭제할 메시지 번호를 입력 : ");
			cout << "삭제하시겠습니까?(Y/N)";
			cin >> answer;
			if (answer == 'y' || answer == 'Y') {
				// 해당 인덱스의 메시지 삭제
				if (ap->deletePage(DIRECTM_INDEX, messageIndex) == true) {
					cout << "삭제가 완료되었습니다.." << endl;
					cout << "2초 뒤 메시지 관리 메뉴로 돌아갑니다..." << endl;
					Sleep(2000);
					return;
				}
			}
			// 잘못된 인덱스 입력
			else {
				cout << "삭제를 실패했습니다.." << endl;
				cout << "2초 뒤 메시지 관리 메뉴로 돌아갑니다..." << endl;
				Sleep(2000);
				return;
			}
		}
		else if (answer == 'n' || answer == 'N') {
			cout << "삭제가 진행되지 않았습니다." << endl;
			cout << "2초 뒤 메시지 관리 메뉴로 돌아갑니다..." << endl;
			Sleep(2000);
			return;
		}
		else {
			cout << "정상적인 문자를 입력하십시오." << endl;
			myFlush();
		}
	}
}

// 메시지 전송
void sendMessage(list<Account> &accList, Account *ap)
{
	list<Account>::iterator it;
	string id, message;
	system("cls");
	cout << "'" << ap->getID() << "'" << " 님의 계정 관리" << endl;
	inputInfoString("받는 사람의 아이디 입력 : ", id, ID_SIZE);

	// 리스트에 입력받은 아이디가 존재하지 않으면 메시지 관리 화면으로 이동
	for (it = accList.begin(); it != accList.end(); it++)
		if (it->getID() == id) { break; }
	if (it == accList.end()) {
		cout << "잘못된 아이디 입니다" << endl;
		cout << "2초 뒤 메시지 관리 메뉴로 돌아갑니다..." << endl;
		Sleep(2000);
		return;
	}

	inputInfoString("보낼 메시지 입력 : ", message, MESSAGE_SIZE);

	// 자신의 아이디를 입력한 경우 자신의 메시지함에 추가하고 메시지 관리화면으로 이동
	if (id == ap->getID()) {
		// 나의 메시지함에 메시지 추가
		ap->writePage(DIRECTM_INDEX, message, id);
		cout << "* 나에게 메시지 전송이 완료되었습니다 *" << endl;
		cout << "2초 뒤 메시지 관리 메뉴로 돌아갑니다..." << endl;
		Sleep(2000);
		return;
	}

	// 메시지는 맞팔 상대에게만 보낼 수 있음
	for (it = accList.begin(); it != accList.end(); it++) {
		// 자기 자신은 넘어감
		if (it->getID() == ap->getID())
			continue;
		// 서로 팔로우가 되어있는 경우, 즉 맞팔인 경우
		if (it->followerCheck(ap->getID()) == true && ap->followerCheck(it->getID()) == true) {
			// 그 중에서 입력한 아이디와 일치하는 객체를 찾으면
			if (it->getID() == id) {
				// it 이 가리키는 객체(메시지를 받는 상대)의 메시지함에 메시지를 추가
				it->writePage(DIRECTM_INDEX, message, ap->getID());
				cout << "* 전송이 완료 되었습니다 * " << endl;
				cout << "2초 뒤 메시지 관리 메뉴로 돌아갑니다..." << endl;
				Sleep(2000);
				return;
			}
		}
	}
	cout << "서로 팔로우 되어있지 않으면 메시지를 보낼 수 없습니다." << endl;
	cout << "2초 뒤 메시지 관리 메뉴로 돌아갑니다..." << endl;
	Sleep(2000);
}

void manageTimeLine(list<Account> &accList, Account *ap)
{
	int menuNum;
	while (1) {
		system("cls");
		cout << "'" << ap->getID() << "'" << " 님의 계정 관리" << endl;
		cout << "* 타임라인 관리 메뉴 *" << endl;
		cout << "1. 내 타임라인 관리\n2. 친구 타임라인 보기\n3. 나가기" << endl;
		menuNum = inputMenuNum("선택 : ", 3);
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
		cout << "'" << ap->getID() << "'" << " 님의 계정 관리" << endl;
		cout << "* 내 타임라인 메뉴 *" << endl;

		// 내 타임라인 일괄 출력
		ap->prnPage(TIMELINE_INDEX);

		cout << "1. 내 타임라인 작성\n2. 내 타임라인 삭제\n3. 나가기" << endl;
		menuNum = inputMenuNum("선택 : ", 3);
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
	inputInfoString("타임라인 작성할 내용 입력 : ", timeLineMessage, TIMELINE_SIZE);

	ap->writePage(TIMELINE_INDEX, timeLineMessage, ap->getID());
	cout << "작성 완료되었습니다." << endl;
	cout << "2초 뒤 타임라인 관리 메뉴로 돌아갑니다..." << endl;
	Sleep(2000);
}

void deleteTimeLine(Account *ap)
{
	int timeLineIndex;
	char answer;

	while (1) {
		system("cls");
		timeLineIndex = inputInteger("삭제할 타임라인 번호를 입력 : ");
		cout << "삭제하시겠습니까?(Y/N) : ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y') {
			// 해당 인덱스의 타임라인 삭제
			if (ap->deletePage(TIMELINE_INDEX, timeLineIndex) == true) {
				cout << "삭제가 완료되었습니다.." << endl;
				cout << "2초 뒤 타임라인 관리 메뉴로 돌아갑니다..." << endl;
				Sleep(2000);
				return;
			}
			// 잘못된 인덱스 입력
			else {
				cout << "삭제를 실패했습니다.." << endl;
				cout << "2초 뒤 타임라인 관리 메뉴로 돌아갑니다..." << endl;
				Sleep(2000);
				return;
			}
		}
		else if (answer == 'n' || answer == 'N') {
			cout << "삭제가 진행되지 않았습니다." << endl;
			cout << "2초 뒤 타임관리 메뉴로 돌아갑니다..." << endl;
			Sleep(2000);
			return;
		}
		else {
			cout << "정상적인 문자를 입력하십시오." << endl;
			myFlush();
		}
	}
}

void showFriendTimeLine(list<Account> &accList, Account *ap)
{
	list<Account>::iterator it;
	system("cls");
	cout << "'" << ap->getID() << "'" << " 님의 계정 관리" << endl;

	// 친구들의 타임라인 일괄 출력
	// 여기서 친구는 내가 팔로잉하고 있는 모든 사람
	for (it = accList.begin(); it != accList.end(); it++) {
		// 팔로잉을 하고 있는 경우
		if (it->followerCheck(ap->getID()) == true) {
			cout << "'" << it->getID() << "'" << " 님의 타임라인" << endl;
			it->prnPage(TIMELINE_INDEX);
			cout << endl;
		}
	}
	cout << "아무 키나 입력하면 타임라인 관리 메뉴로 이동합니다..." << endl;
	getchar();
}

// 친구 관리 함수
void manageFriend(list<Account> &accList, Account *ap)
{
	int menuNum;
	while (1) {
		system("cls");
		cout << "'" << ap->getID() << "'" << " 님의 계정 관리" << endl;
		cout << "* 친구 관리 메뉴 *" << endl;
		cout << "1. 팔로잉 보기\n2. 팔로워 보기\n3. 나가기" << endl;
		menuNum = inputMenuNum("선택 : ", 3);
		switch (menuNum)
		{
		case 1: showFollowing(accList, ap); break;
		case 2: showFollower(ap); break;
		case 3: return;
		}
	}
}

// 내가 팔로잉한 친구 목록을 출력하고 
// 팔로잉 추가, 삭제를 진행하는 함수
void showFollowing(list<Account> &accList, Account *ap)
{
	list<Account>::iterator it;
	string id;
	int menuNum;
	while (1) {
		system("cls");
		cout << "'" << ap->getID() << "'" << " 님의 계정 관리" << endl;
		cout << "* 팔로잉 메뉴 *" << endl;
		cout << "'" << ap->getID() << "'" << " 님의 팔로잉" << endl;
		cout << "-----------------------------------" << endl;
		ap->prnFollowing();
		cout << "-----------------------------------" << endl;
		cout << "1. 팔로잉 추가\n2. 팔로잉 삭제\n3. 나가기" << endl;
		menuNum = inputMenuNum("선택 : ", 3);
		switch (menuNum) {
		case 1:
			system("cls");
			cout << "'" << ap->getID() << "'" << " 님의 계정 관리" << endl;
			inputInfoString("추가할 친구 아이디 검색 : ", id, ID_SIZE);

			for (it = accList.begin(); it != accList.end(); it++)
				if (it->getID() == id) { break; } // it 이 팔로잉할 계정의 객체를 가리킴
			// 리스트에 해당 아이디가 존재하지 않는 경우 친구관리 메뉴로 이동
			if (it == accList.end()) {
				cout << "존재하지 않는 계정입니다." << endl;
				cout << "2초 뒤 팔로잉 메뉴로 돌아갑니다..." << endl;
				Sleep(2000);
				break;
			}
			// 자신의 아이디를 검색한 경우 친구관리 메뉴로 이동
			if (it->getID() == ap->getID()) {
				cout << "자신의 계정을 팔로우 할 수 없습니다." << endl;
				cout << "2초 뒤 팔로잉 메뉴로 돌아갑니다..." << endl;
				Sleep(2000);
				break;
			}

			// 입력받은 아이디가 내 팔로잉 목록에 없는 경우 목록에 추가
			if ((ap->followingCheck(id)) == false) {
				ap->addFollowing(id); // 내 팔로잉 목록에 상대방 아이디 추가
				it->addFollower(ap->getID()); // 상대방 팔로워 목록에 내 아이디 추가
				cout << "추가 되었습니다." << endl;
				cout << "2초 뒤 팔로잉 메뉴로 돌아갑니다..." << endl;
				Sleep(2000);
			}
			else {
				cout << "이미 팔로잉 되어있는 계정입니다." << endl;
				cout << "2초 뒤 팔로잉 메뉴로 돌아갑니다..." << endl;
				Sleep(2000);
			}
			break;

		case 2:
			system("cls");
			cout << "'" << ap->getID() << "'" << " 님의 계정 관리" << endl;
			inputInfoString("삭제할 친구 아이디 검색 : ", id, ID_SIZE);

			for (it = accList.begin(); it != accList.end(); it++)
				if (it->getID() == id) { break; } // it 이 팔로잉 삭제할 계정의 객체를 가리킴
			// 리스트에 해당 아이디가 존재하지 않는 경우 친구관리 메뉴로 이동
			if (it == accList.end()) {
				cout << "존재하지 않는 계정입니다." << endl;
				cout << "2초 뒤 팔로잉 메뉴로 돌아갑니다..." << endl;
				Sleep(2000);
				break;
			}
			// 자신의 아이디를 검색한 경우 친구관리 메뉴로 이동
			if (it->getID() == ap->getID()) {
				cout << "자신의 계정을 팔로우 삭제할 수 없습니다." << endl;
				cout << "2초 뒤 팔로잉 메뉴로 돌아갑니다..." << endl;
				Sleep(2000);
				break;
			}
			// 입력받은 아이디가 내 팔로잉 목록에 있는 경우 목록에서 삭제
			if ((ap->followingCheck(id)) == true) {
				ap->delFollowing(id); // 내 팔로잉 목록에서 상대방 아이디 삭제
				it->delFollower(ap->getID()); // 상대방 팔로워 목록에서 내 아이디 삭제
				cout << "삭제 되었습니다." << endl;
				cout << "2초 뒤 팔로잉 메뉴로 돌아갑니다..." << endl;
				Sleep(2000);
			}
			else {
				cout << "팔로잉 되어있지 않은 계정입니다." << endl;
				cout << "2초 뒤 팔로잉 메뉴로 돌아갑니다..." << endl;
				Sleep(2000);
			}
			break;
		case 3: return;
		}
	}
}

// 나에게 팔로우 되어있는 친구 목록 출력 함수
void showFollower(Account *ap)
{
	system("cls");
	cout << "'" << ap->getID() << "'" << " 님의 팔로워" << endl;
	cout << "-----------------------------------" << endl;
	ap->prnFollower();
	cout << "-----------------------------------" << endl;
	cout << "아무 키나 입력하면 친구 관리 메뉴로 이동합니다..." << endl;
	getchar();
}

// 내 정보 관리 함수
void manageInfo(Account *ap)
{
	int num;
	system("cls");
	cout << "'" << ap->getID() << "'" << " 님의 계정 관리" << endl;
	cout << "* 내 정보 관리 메뉴 *" << endl;

	ap->prnInfo();

	num = inputMenuNum("수정할 항목 입력 : ", 5);

	ap->setInfo(num);
}

// 계정 탈퇴 함수
// 탈퇴 성공 시 true, 아니면 false 를 리턴
bool withDrawAccount(list<Account> &accList, list<Account>::iterator it)
{
	list<Account>::iterator it_t;
	string temp;
	char answer;
	while (1) {
		cout << "계정을 탈퇴하시겠습니까?(Y/N) : ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y') {
			// temp 에 탈퇴계정의 아이디를 넣어놓는다
			// 이 temp 를 이용하여 해당 계정의 다른 계정들에서의 팔로우, 팔로잉을 삭제한다
			temp = it->getID();

			// 해당 계정 리스트에서 삭제
			accList.erase(it);

			// 해당 계정의 팔로우, 팔로잉 정보를 모든 리스트의 계정에서 삭제
			for (it_t = accList.begin(); it_t != accList.end(); it_t++) {
				if (it_t->followingCheck(temp) == true)
					it_t->delFollowing(temp);
				if (it_t->followerCheck(temp) == true)
					it_t->delFollower(temp);
			}
			cout << "탈퇴가 완료되었습니다." << endl;
			cout << "2초 뒤 시작화면으로 돌아갑니다..." << endl;
			Sleep(2000);
			return true;
		}
		else if (answer == 'n' || answer == 'N') {
			cout << "탈퇴를 진행하지 않습니다." << endl;
			cout << "2초 뒤 계정화면으로 돌아갑니다..." << endl;
			Sleep(2000);
			return false;
		}
		else {
			cout << "정상적인 문자를 입력하십시오." << endl;
			myFlush();
		}
	}
}

// ID, 전화번호는 공백 입력	불가
// 이름, 거주지는 공백 입력 가능
// 길이는 num 미만으로만 입력받음
void inputInfoString(const char *stp, string &str, int num)
{
	int i;
	char temp[20];
	for (i = 0; stp[i] != ' '; i++) {
		temp[i] = stp[i];
	} temp[i] = '\0';

	if (!strcmp(temp, "추가할") || !strcmp(temp, "삭제할") || !strcmp(temp, "받는"))
		strcpy(temp, "아이디");
	if (!strcmp(temp, "보낼"))
		strcpy(temp, "메시지");

	while (1) {
		cout << stp;

		// 이름, 거주지, 타임라인, 메시지는 공백 입력 가능
		if (!strcmp(stp, "이름 : ") || !strcmp(stp, "거주지 : ") || !strcmp(temp, "타임라인") || !strcmp(temp, "메시지")) {
			getline(cin, str);
			if (str.length() >= (unsigned int)num) {
				cout << temp << "는 " << num << "자를 넘을 수 없습니다." << endl;
				continue;
			}
			break;
		}

		cin >> str;
		if (cin.get() == '\n') {
			if (str.length() >= (unsigned int)num) {
				cout << temp << "는 " << num << "자를 넘을 수 없습니다." << endl;
				continue;
			}
			break;
		}
		// ID, 전화번호는 공백입력 불가
		else {
			cout << temp << "에는 공백을 입력할 수 없습니다." << endl;
			myFlush();
		}
	}
}

// 메뉴번호 입력함수
// 1 ~ n 사이의 숫자만 입력받도록 예외 처리 
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
				cout << "존재하지 않는 메뉴번호입니다. 다시 입력하세요." << endl;
				continue;
			}
		}
		cout << "존재하지 않는 메뉴번호입니다. 다시 입력하세요." << endl;
		myFlush();
	}
}

// message를 출력하고 정수값 입력 받아 리턴
// 문자, 실수, 음수, 0 입력 예외처리
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
