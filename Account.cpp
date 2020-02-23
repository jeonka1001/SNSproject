#include "Account.h"

// find �Լ��� ���ؼ� Ž���� ������ �� ã������ ����� ����Ʈ�� ������
// end()�� �����ؼ� it�� end()�� ����Ű�� �Ǵµ�, end() �� �Ƹ� ����Ʈ ���� �޸𸮸� ����Ű�� �� ���ƿ�
// �׷��� (*it) �̷��� �����ϸ� ��� ��Ÿ�� ������ ���� ��ü������ �ణ �����߽��ϴ�.
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
				cout << "(����)";
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
				cout << "(����)";
			}
			else { ; }
		}
		cout << endl;
	}
}
bool Account::deletePage(int page,int index){// driectM���� timeline ���� �����ϱ����� �Ķ���� , ���� �޼����� index
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
    cout <<"������ ���� �Է�:";
    
    if(num==1){
        string name;
        cin>> name;
        myInfo.setName(name);
    }
    else if(num == 2){
		char gen;
		cin >> gen;
		myInfo.setGender(gen);
    }
    else if(num ==3){
		int age;
		cin >> age;
		myInfo.setAge(age);
 
    }
    else if(num == 4){
        string phone;
        cin >> phone;
        myInfo.setPhoneNum(phone);
    }
    else{
		string add;
		cin >> add;
		myInfo.setAddress(add);
    }
}
