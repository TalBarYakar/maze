#include"xyPoint.h"
int xypoint::getHight()
{
	return height;
}
int xypoint::getWidth()
{
	return width;
}
void xypoint::setHeight(int he) 
{
	height = he;
}
void xypoint::setWidth(int wid)
{
	width = wid;
}
xypoint::xypoint(int a, int b)
{
	height = a;
	width=b;
}