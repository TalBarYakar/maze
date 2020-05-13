#include"stack.h"
stack::stack()
{
	top = nullptr;
}
xypoint stack::pop()
{
	if (isEmpty() == false)
	{
		Node*temp=top;
		xypoint p1 = top->point;
		top = top->next;
		delete temp;
		return p1;
	}
	else
	{
		cout << "the stack is empty" << endl;
		exit(1);
	}
}
void stack::push(xypoint newPoint)
{
	Node* newNode = new Node;
	newNode->point = newPoint;
	newNode->next = top;
	top = newNode;
}
bool stack::isEmpty()
{
	return (top == nullptr);
}