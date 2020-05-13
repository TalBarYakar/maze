#ifndef _MA_H
#define _MA_H
#include"queue.h"
#include"stack.h"
class maze 
{
public:
	maze(int height=0, int width=0);
	static const int SIZEOFMAZE = 7;//for the checks 
	void setMaze();//just for the cheks
	void solveMaxe();
	void printMaze();
	void makingMaze();//for the checks
	void setMazeAtBegining();
	bool checkIfAvailable(int heightCur, int widthCur);
private:
	queue q1;
	stack s1;
	char limits[SIZEOFMAZE][SIZEOFMAZE];
};
#endif // !_MA_H
