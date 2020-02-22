#include"directM.h"
#include<string>
#include<iostream>
using namespace std;

DirectM::DirectM(int mesCnt) {

	for (int i = 0; i < MAX_NUM; i++) {
		myMessage[i] = "";
	} 
	mesCnt = 0;
}

void DirectM::prnMessage(){

	// cout << "------- 메세지 보관함 -------" << endl;
	// cout << endl;

	for (int i = 0; i < mesCnt; i++) {
		cout << i <<'.'<< myMessage[i] << endl;
	}
	// cout << "----------------------------------" << endl;
}

string DirectM::write(string str) {

	cout << "보낼 메세지를 입력하세요: ";
	getline(cin, str);
	myMessage[mesCnt] = str;
	return str;
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