#ifndef _QU_H
#define _QU_H
#include"xyPoint.h"
class queue
{
public:
	static const int MAX_SIZE_OF_QUEUE = 100;
	queue();
	
	~queue();
	void makeEmpty();
	int addOne(int x);
	int isEmpty();
	int isFull();
	void EnQueue(xypoint point);
	xypoint DeQueue();
	void printHead();
	int getHead();
	int getTail();
private:
	xypoint arrayOfPointsInTheMaze[MAX_SIZE_OF_QUEUE];
	int head, tail;

};
#endif // !_QU_H
