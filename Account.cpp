#include "Account.h"

bool Account::addFollowing(string following){
    list<string>::iterator it; // 이터레이터 추가해야 리스트 내 파일 제어 가능
    it=find(this->following.begin(),this->following.end(),following); //알고리즘 인클루드 후 find함수 이용
    // 시작위치, 종료위치(읽기 미포함), 비교할 문자 // 리턴값은 성공시 해당 주소
    // 리턴값을 받는 용도로 iterator 변수를 쓴다.
    if(*it==following){ // it가 가리키는 값과 following 을 비교
        // cout <<"팔로잉 추가 실패"<<endl;
        return false;
    }
    else{
        this->following.push_front(following);
        // cout << "팔로잉 추가 성공"<<endl;
        return true;
    }
}
bool Account::delFollowing(string following){
    list<string>::iterator it;
    it=find(this->following.begin(),this->following.end(),following);
    if(*it!=following){
        // cout <<"팔로잉 삭제 실패"<<endl;
        return false;
    }
    else{
        this->following.remove(following);
        // cout << "팔로잉 삭제 성공"<<endl;
        return true;
    }
}
void Account::prnFollowing(){
    for(auto a : following){
        cout << a <<endl;
    }
}
bool Account::addFollower(string follower){
    list<string>::iterator it;
    it=find(this->follower.begin(),this->follower.end(),follower);
    if(*it==follower){
        return false;
    }
    else{
        this->follower.push_front(follower);
        return true;
    }
}
bool Account::delFollower(string follower){
    list<string>::iterator it;
    it=find(this->follower.begin(),this->follower.end(),follower);
    if(*it != follower){
        return false;
    }
    else{
        this->follower.remove(follower);
        return true;
    }
}
void Account::prnFollower(){
    for(auto a: follower){
        cout << a <<endl;
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
void Account::writePage(int page,string text){
    Communicate *cp = NULL;
    switch(page-1){
        case DIRECTM:
            cp=myPage[DIRECTM];
            break;
        case TIMELINE:
            cp=myPage[TIMELINE];
            break;
    }
    cp->write(text);
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
    if(*it==follower){
        return true;
    }
    else{
        return false;
    }
}
bool Account::followingCheck(string following){
    list<string>::iterator it;
    it=find(this->following.begin(),this->following.end(),following);
    if(*it==following){
        return true;
    }
    else{
        return false;
    }
}
string Account::getID(){
    return this->myID;
}
Information Account::getInfo(){
    return this->myInfo;
}
void Account::prnInfo(){
    cout<<"이름 :" << myInfo.getName()<<endl;
    cout<<"나이 :" << myInfo.getAge()<<endl;
    cout<<"거주지 :" << myInfo.getAddress()<<endl;
    cout<<"전화번호 :" << myInfo.getPhoneNum()<<endl;
    cout<<"성별 :" << myInfo.getGender()<<endl<<endl;
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
        int age;
        cin >>age;
        myInfo.setAge(age);
    }
    else if(num ==3){
        string add;
        cin >> add;
        myInfo.setAddress(add);
    }
    else if(num == 4){
        string phone;
        cin >> phone;
        myInfo.setPhoneNum(phone);
    }
    else{
        char gen;
        cin>>gen;
        myInfo.setGender(gen);
    }
}
