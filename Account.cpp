#include "define.h"
#include "Account.h"

bool Account::addFollowing(string following){
    list<string>::iterator it; 
    it=find(this->following.begin(),this->following.end(),following);
    if(it == this->following.end()){ 
		this->following.push_front(following);
		return true;
    }
    else{
		return false;
    }
}
bool Account::delFollowing(string following){
    list<string>::iterator it;
    it=find(this->following.begin(),this->following.end(),following);
    if(it == this->following.end()){
        return false;
    }
    else{
        this->following.remove(following);
        return true;
    }
}
void Account::prnFollowing(){
	for (auto a : following) {
		cout << a;
		for (auto b : follower) {
			if (a == b) {
				cout << "(맞팔)";
			}
			else { ; }
		}
		cout << endl;
	}
}
bool Account::addFollower(string follower){
    list<string>::iterator it;
    it=find(this->follower.begin(),this->follower.end(),follower);
    if(it == this->follower.end()){
		this->follower.push_front(follower);
		return true;
    }
    else{
		return false;
    }
}
bool Account::delFollower(string follower){
    list<string>::iterator it;
    it=find(this->follower.begin(),this->follower.end(),follower);
    if(it == this->follower.end()){
        return false;
    }
    else{
        this->follower.remove(follower);
        return true;
    }
}
void Account::prnFollower(){
	for (auto a : follower) {
		cout << a;
		for (auto b : following) {
			if (a == b) {
				cout << "(맞팔)";
			}
			else { ; }
		}
		cout << endl;
	}
}
bool Account::deletePage(int page,int index){// driectM인지 timeline 인지 구분하기위한 파라미터 , 지울 메세지의 index
    Communicate *cp = NULL;
    switch(page-1){
        case DIRECTM:
            cp=myPage[DIRECTM];
            break;
        case TIMELINE:
            cp=myPage[TIMELINE];
            break;
    }
    if(cp->deleteP(index-1)){
        return true;
    }
    else{
      return false;
    }
}
void Account::writePage(int page,string text,string id){
    Communicate *cp = NULL;
    switch(page-1){
        case DIRECTM:
            cp=myPage[DIRECTM];
            break;
        case TIMELINE:
            cp=myPage[TIMELINE];
            break;
    }
    cp->write(id,text);
}
void Account::prnPage(int page){
    Communicate *cp = NULL;
    switch(page-1){
        case DIRECTM:
            cp=myPage[DIRECTM];
			break;
        case TIMELINE:
            cp=myPage[TIMELINE];
			break;
    }
    cp->prnMessage();
}
bool Account::followerCheck(string follower){
    list<string>::iterator it;
    it=find(this->follower.begin(),this->follower.end(),follower);
    if(it==this->follower.end()){
		return false;
    }
    else{
		return true;
    }
}
bool Account::followingCheck(string following){
    list<string>::iterator it;
    it=find(this->following.begin(),this->following.end(),following);
	if(it == this->following.end()){
	   return false;
    }
    else{
	   return true;
    }
}
string Account::getID(){
    return this->myID;
}
Information Account::getInfo(){
    return this->myInfo;
}
void Account::prnInfo(){
	myInfo.printInformation();
}
int Account::getPageNum(int page){
    Communicate *cp = NULL;
    switch(page-1){
        case DIRECTM:
            cp=myPage[DIRECTM];
            break;
        case TIMELINE:
            cp=myPage[TIMELINE];
            break;
    }
    return cp->getMesCnt();
}
void Account::setInfo(int num){
	while (1) {
		cout << "수정할 내용 입력 : ";

		// 이름 입력
		if (num == 1) {
			string name;
			getline(cin, name);
			if (name.length() >= NAME_SIZE) {
				cout << "이름은 " << NAME_SIZE << "자를 넘을 수 없습니다." << endl;
				continue;
			}
			myInfo.setName(name);
			break;
		}
		// 성별 입력
		else if (num == 2) {
			char gen;
			cin >> gen;
			if (gen == 'M' || gen == 'm' || gen == 'F' || gen == 'f') { 
				myInfo.setGender(gen);
				break; 
			}
			cin.clear();
			while (cin.get() != '\n');
		}
		// 나이 입력
		else if (num == 3) {
			int age;
			cin >> age;
			if (cin.get() == '\n') { 
				if (age >= 1) { 
					myInfo.setAge(age);
					break; 
				}
				else { continue; }
			}
			cin.clear();
			while (cin.get() != '\n');
		}
		// 전화번호 입력
		else if (num == 4) {
			string phone;
			cin >> phone;
			if (cin.get() == '\n') {
				if (phone.length() >= PHONE_NUMBER_SIZE) {
					cout << "전화번호는 " << PHONE_NUMBER_SIZE << "를 넘을 수 없습니다." << endl;
					continue;
				}
				myInfo.setPhoneNum(phone);
				break;
			}
			else {
				cout << "전화번호에는 공백을 입력할 수 없습니다." << endl;
				cin.clear();
				while (cin.get() != '\n');
			}
		}
		// 거주지 입력
		else {
			string add;
			getline(cin, add);
			if (add.length() >= ADDR_SIZE) {
				cout << "거주지는 " << ADDR_SIZE << "자를 넘을 수 없습니다." << endl;
				continue;
			}
			myInfo.setAddress(add);
			break;
		}
	}
}
