#ifndef _ST_H
#define _ST_H
#include"xyPoint.h"
struct Node 
{
	xypoint point;
	Node *next;
};
class stack
{
private:
	Node* top;
public:
	stack();
	xypoint pop();
	void push(xypoint newPoint);
	bool isEmpty();
};
#endif 
