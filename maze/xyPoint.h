#ifndef _XY_H
#define _XY_H
#include<iostream>
using namespace std;

class xypoint 
{
public:
	xypoint(int a=1, int b=0);
	int getHight();
	int getWidth();
	void setHeight(int he);
	void setWidth(int wid);
private:
	int height;
	int width;
};
#endif // !_XY_H
