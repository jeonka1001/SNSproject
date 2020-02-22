//
//  Created by ����� on 2020.02.22
//
#pragma once
#include<iostream>
#include<string>
using namespace std;

class Information
{
private:
	string myID;
	string name;
	char gender;
	int age;
	string phoneNum;
	string address;
public:
	Information(string myID="", string name="", char gender=0, int age=0, string phoneNum="", string address="");   // ȸ������ �� �Է¹��� �����ͷ� �ʱ�ȭ
	void printInformation();   // ȸ�� ���� ���
	//getter member function
	string getMyID();
	string getName();
	char getGender();
	int getAge();
	string getPhoneNum();
	string getAddress();
	//setter member function
	void setMyID(string newMyID);
	void setName(string newName);
	void setGender(char newGender);
	void setAge(char newAge);
	void setPhoneNum(string newPhoneNum);
	void setAddress(string newAddress);
};
