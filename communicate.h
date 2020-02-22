#pragma once
#include<string>
#include<iostream>
using namespace std;
#define MAX_NUM 5

struct Communicate {

	virtual string write(string str) = 0;
	virtual bool deleteP(int num) = 0;
	virtual void prnMessage() = 0;
	virtual int searchP(int num) = 0;
	virtual int getMesCnt() = 0;
};
