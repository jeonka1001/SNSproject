#include "Account.h"

// find 함수를 통해서 탐색을 진행할 때 찾으려는 대상이 리스트에 없으면
// end()를 리턴해서 it이 end()를 가리키게 되는데, end() 가 아마 리스트 밖의 메모리를 가리키는 것 같아요
// 그래서 (*it) 이렇게 접근하면 계속 런타임 에러가 나서 전체적으로 약간 수정했습니다.
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
    cout <<"수정할 내용 입력:";
    
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
