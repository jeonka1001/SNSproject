#include"directM.h"
#include<string>
#include<iostream>
using namespace std;

DirectM::DirectM() {
	for (int i = 0; i < MAX_NUM; i++) 
		myMessage[i] = "";
	mesCnt = 0;
}

void DirectM::prnMessage(){
	if (mesCnt == 0) {
		cout << "-----------------------------------" << endl;
		cout << endl;
		cout << "표시할 메세지 내용이 없습니다." << endl;
		cout << endl;
		cout << "-----------------------------------" << endl;
	}

	for (int i = 0; i < mesCnt; i++) {
		cout << i + 1 << '.' << myMessage[i] << endl;
	}
}

string DirectM::write(string id,string str) {
	int i;
	string tmp;
	tmp = id;
	tmp += "->";
	tmp += str;
	// 메시지함이 꽉 차있는 경우 밀어내기 진행
	if (mesCnt == MAX_NUM) {
		for (i = 0; i < mesCnt - 1; i++) 
			myMessage[i] = myMessage[i + 1];
		myMessage[i] = tmp;
	}
	else {
		myMessage[mesCnt] = tmp;
		mesCnt++;
	}
	return tmp;
}

bool DirectM::deleteP(int pageNum) {

	int index, i;
	index = searchP(pageNum);

	if(index !=-1){

		for (i = index; i < mesCnt - 1; i++) {
			myMessage[i] = myMessage[i + 1];
		}
		mesCnt--;
    	return true;
	}
	return false;
}

int DirectM::searchP(int pageNum) {

	for (int i = 0; i < mesCnt; i++) {
		if (i == pageNum) {
			return i;
		}
	}
	return -1;
}