//
//  Created by ����� on 2020.02.22
//
#pragma warning (disable : 4996)
#include"information.h"
#include<iostream>
#include<string>
using namespace std;

Information::Information(string myID, string name, char gender, int age, string phoneNum, string address)
{
	this->myID = myID;
	this->name = name;
	this->gender = gender;
	this->age = age;
	this->phoneNum = phoneNum;
	this->address = address;
}

void Information::printInformation()
{
	cout << "ID : " << this->myID << endl;
	cout << "�̸� : " << this->name << endl;
	cout << "���� : " << this->gender << endl;
	cout << "���� : " << this->age << endl;
	cout << "��ȭ��ȣ : " << this->phoneNum << endl;
	cout << "�ּ� : " << this->address << endl;
}

string Information::getMyID()
{
	return (this->myID);
}

string Information::getName()
{
	return (this->name);
}

char Information::getGender()
{
	return (this->gender);
}

int Information::getAge()
{
	return (this->age);
}

string Information::getPhoneNum()
{
	return (this->phoneNum);
}

string Information::getAddress()
{
	return (this->address);
}

void Information::setMyID(string newMyID)
{
	this->myID = newMyID;
}

void Information::setName(string newName)
{
	this->name = newName;
}

void Information::setGender(char newGender)
{
	this->gender = newGender;
}

void Information::setAge(char newAge)
{
	this->age = newAge;
}

void Information::setPhoneNum(string newPhoneNum)
{
	this->phoneNum = newPhoneNum;
}

void Information::setAddress(string newAddress)
{
	this->address = newAddress;
}

