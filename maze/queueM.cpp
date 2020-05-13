#include"queue.h"
//queue using a circle way
queue::queue()
{
	makeEmpty();

}

queue::~queue()
{

}
void queue::makeEmpty()
{
	head = 1; tail = 0;
}
int queue::addOne(int x)
{
	return ((x + 1) % queue::MAX_SIZE_OF_QUEUE);
}
int queue::isEmpty()
{
	return (addOne(tail) == head);
}
int queue::isFull()
{
	return (addOne(addOne(tail)) == head);
}
void queue::EnQueue(xypoint point)
{
	if (isFull() == 1)
	{
		cout << "the queue is full" << endl;
		exit(1);
	}
	tail++;
	arrayOfPointsInTheMaze[tail] = point;
} 

xypoint queue::DeQueue()
{
	if (isEmpty())
	{
		cout << "the queue is full" << endl;
		exit(1);
	}
	xypoint temp= arrayOfPointsInTheMaze[head];
	head = addOne(head);
	return temp;
}
void queue::printHead()
{
	cout << arrayOfPointsInTheMaze[head].getHight() << arrayOfPointsInTheMaze[head].getWidth() << endl;
}
int queue::getHead()
{
	return head;
}
int queue::getTail()
{
	return tail;
}