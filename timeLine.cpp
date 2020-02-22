#include"timeLine.h"
#include<string>
#include<iostream>
using namespace std;

Timeline::Timeline(int mesCnt) {
	cout << "Timeline 생성자 호출1" << endl;
	for (int i = 0; i < MAX_NUM; i++) {
		myMessage[i] = "";
	}
	mesCnt = 0;
	cout << "Timeline 생성자 호출2" << endl;
}

void Timeline::prnMessage() {

	//cout << "---------------타임라인----------------" << endl;
	//cout << endl;

	for (int i = 0; i < mesCnt; i++) {
		cout << i << '.' << myMessage[i] << endl;
	}
	// cout << "----------------------------------" << endl;
}

string Timeline::write(string str) {

	cout << "타임라인에 작성 할 내용 입력: ";
	getline(cin, str);
	myMessage[mesCnt] = str;
	return str;
}

bool Timeline::deleteP(int pageNum) {

	int index, i;
	index = searchP(pageNum);

	if (index != -1) {

		for (i = index; i < mesCnt - 1; i++) {
			myMessage[i] = myMessage[i + 1];
		}
		mesCnt--;
		return true;
	}
	return false;
}

int Timeline::searchP(int pageNum) {

	for (int i = 0; i < mesCnt; i++) {
		if (i == pageNum) {
			return i;
		}
	}
	return -1;
}

