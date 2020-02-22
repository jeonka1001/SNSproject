#ifndef __TIMELINE_H__
#define __TIMELINE_H__
#include"communicate.h"

class Timeline : public Communicate {

private:
	string myMessage[MAX_NUM];
	int mesCnt;
public:
	Timeline(int mesCnt = 0); 
	string write(string str="");
	bool deleteP(int pageNum=0);
	void prnMessage();
	int searchP(int pageNum = 0);
	int getMesCnt() {
		return mesCnt;
	}
};
#endif
