#ifndef __DIRECTM_H__
#define __DIRECTM_H__
#include"communicate.h"

class DirectM : public Communicate{

private:
	string myMessage[MAX_NUM];
	int mesCnt;
public:
	DirectM(int mesCnt = 0); 
	string write(string str ="");
	bool deleteP(int pageNum=0);
	void prnMessage();
	int searchP(int pageNum=0);
	int getMesCnt() {
		return mesCnt;
	}
};
#endif