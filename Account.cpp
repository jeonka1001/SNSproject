#include "Account.h"

bool Account::addFollowing(string following){
    list<string>::iterator it; // ���ͷ����� �߰��ؾ� ����Ʈ �� ���� ���� ����
    it=find(this->following.begin(),this->following.end(),following); //�˰��� ��Ŭ��� �� find�Լ� �̿�
    // ������ġ, ������ġ(�б� ������), ���� ���� // ���ϰ��� ������ �ش� �ּ�
    // ���ϰ��� �޴� �뵵�� iterator ������ ����.
    if(*it==following){ // it�� ����Ű�� ���� following �� ��
        // cout <<"�ȷ��� �߰� ����"<<endl;
        return false;
    }
    else{
        this->following.push_front(following);
        // cout << "�ȷ��� �߰� ����"<<endl;
        return true;
    }
}
bool Account::delFollowing(string following){
    list<string>::iterator it;
    it=find(this->following.begin(),this->following.end(),following);
    if(*it!=following){
        // cout <<"�ȷ��� ���� ����"<<endl;
        return false;
    }
    else{
        this->following.remove(following);
        // cout << "�ȷ��� ���� ����"<<endl;
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
    cout<<"�̸� :" << myInfo.getName()<<endl;
    cout<<"���� :" << myInfo.getAge()<<endl;
    cout<<"������ :" << myInfo.getAddress()<<endl;
    cout<<"��ȭ��ȣ :" << myInfo.getPhoneNum()<<endl;
    cout<<"���� :" << myInfo.getGender()<<endl<<endl;
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
