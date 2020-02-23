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
    bool addFollowing(string following); // 추가할 following 아이디
    bool delFollowing(string following); // 지울 following 아이디
    void prnFollowing();
    bool addFollower(string follower); // 추가할 follower 아이디
    bool delFollower(string follower); // 지울 follower 아이디
    void prnFollower();
    
    bool deletePage(int page,int index);//cast용 page변수 , 지우기 위한 메세지의 index번호 : 타임라인 / DM 지우기
    void writePage(int page,string text,string id);//cast용 page변수 , 쓰기위한 text메세지 : 자신의 타임라인 / DM 을 쓴다.
    void prnPage(int page); // cast용 page변수 : 자신의 타임라인/DM 을 전체 출력한다.
    
    bool followerCheck(string follower); // 입력받은 아이디가 팔로워 목록에 있는지 체크
    bool followingCheck(string following); // 입력받은 아이디가 팔로잉 목록에 있는지 체크
    
    string getID(); //아이디를 리턴받는 함수
    Information getInfo(); // infomation 리턴받는 함수
    void prnInfo(); // 개인정보 전체 출력받기
    void setInfo(int num);// 1. 이름 2. 나이 3.주소 4. 휴대폰 5. 성별 // 로 수정을 할 수 있다.
    int getPageNum(int); // 현 타임라인/ DM 개수 출력 1 = DM/ 2 = TIMELINE
	Account *getMyObj() { return this; }
};
#endif /* Account_h */
