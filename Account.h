#ifndef Account_h
#define Account_h

#include "Information.h"
#include "Communicate.h"
#include "directM.h"
#include "timeLine.h"
#include <cstring>
#include <list>
#include <string>
#include <iostream>
#define DIRECTM 0
#define TIMELINE 1
using namespace std;

class Account{
private:
    Information myInfo;
    list<string> following;
    list<string> follower;
    string myID;
    Communicate *myPage[2];
public:
    Account(){}
    Account(string name,int age,string address,char gender,string phoneNum,string myID)
    :myID(myID),myInfo(myID, name, gender, age, phoneNum, address){
		myPage[DIRECTM] = new DirectM();
        myPage[TIMELINE] = new Timeline();
    }
    ~Account() {
		delete myPage[DIRECTM];
		delete myPage[TIMELINE];
	}

	Account(const Account &br) 
	{
		myID = br.myID;
		myPage[DIRECTM] = new DirectM(*(DirectM *)br.myPage[DIRECTM]);
		myPage[TIMELINE] = new Timeline(*(Timeline *)br.myPage[TIMELINE]);
		myInfo = br.myInfo;
		following = br.following;
		follower = br.follower;
	}

	Account &operator=(const Account &br)
	{
		if (this == &br) { return *this; }
		delete myPage[TIMELINE];
		delete myPage[DIRECTM];
		myID = br.myID;
		myPage[TIMELINE] = new Timeline(*(Timeline *)br.myPage[TIMELINE]);
		myPage[DIRECTM] = new DirectM(*(DirectM *)br.myPage[DIRECTM]);
		myInfo = br.myInfo;
		following = br.following;
		follower = br.follower;
		return *this;
	}
    bool addFollowing(string following); // �߰��� following ���̵�
    bool delFollowing(string following); // ���� following ���̵�
    void prnFollowing();
    bool addFollower(string follower); // �߰��� follower ���̵�
    bool delFollower(string follower); // ���� follower ���̵�
    void prnFollower();
    
    bool deletePage(int page,int index);//cast�� page���� , ����� ���� �޼����� index��ȣ : Ÿ�Ӷ��� / DM �����
    void writePage(int page,string text,string id);//cast�� page���� , �������� text�޼��� : �ڽ��� Ÿ�Ӷ��� / DM �� ����.
    void prnPage(int page); // cast�� page���� : �ڽ��� Ÿ�Ӷ���/DM �� ��ü ����Ѵ�.
    
    bool followerCheck(string follower); // �Է¹��� ���̵� �ȷο� ��Ͽ� �ִ��� üũ
    bool followingCheck(string following); // �Է¹��� ���̵� �ȷ��� ��Ͽ� �ִ��� üũ
    
    string getID(); //���̵� ���Ϲ޴� �Լ�
    Information getInfo(); // infomation ���Ϲ޴� �Լ�
    void prnInfo(); // �������� ��ü ��¹ޱ�
    void setInfo(int num);// 1. �̸� 2. ���� 3.�ּ� 4. �޴��� 5. ���� // �� ������ �� �� �ִ�.
    int getPageNum(int); // �� Ÿ�Ӷ���/ DM ���� ��� 1 = DM/ 2 = TIMELINE
	Account *getMyObj() { return this; }
};
#endif /* Account_h */
