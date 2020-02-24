#include"timeLine.h"
#include<string>
#include<iostream>
using namespace std;

Timeline::Timeline() {
	for (int i = 0; i < MAX_NUM; i++) 
		myMessage[i] = "";
	mesCnt = 0;
}

void Timeline::prnMessage() {
	if (mesCnt == 0) {
		cout << "----------------------------------------------" << endl;
		cout << endl;
		cout << "ǥ���� Ÿ�Ӷ��� ������ �����ϴ�." << endl;
		cout << endl;
	}
	cout << "----------------------------------------------" << endl;
	for (int i = 0; i < mesCnt; i++) {
		cout << "Ÿ�Ӷ���" << i + 1 << ". " << myMessage[i] << endl;
		cout << "----------------------------------------------" << endl;
	}
}

string Timeline::write(string id,string str) {
	int i;
	// Ÿ�Ӷ����� �� ���ִ� ��� �о�� ����
	if (mesCnt == MAX_NUM) {
		for (i = 0; i < mesCnt - 1; i++)
			myMessage[i] = myMessage[i + 1];
		myMessage[i] = str;
	}
	else {
		myMessage[mesCnt] = str;
		mesCnt++;
	}
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

