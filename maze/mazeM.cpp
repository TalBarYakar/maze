#include"maze.h"
#include<ctime>
maze::maze(int height, int width)
{
	q1.makeEmpty();
	xypoint first;
	first.setHeight(1);
	first.setWidth(0);
	q1.EnQueue(first);
}
//___________________________________________________
void maze::setMaze()
{
	for (int i = 0; i < SIZEOFMAZE; i++)
	{
		for (int j = 0; j < SIZEOFMAZE; j++)
			limits[i][j] = NULL;
	}
	for (int i = 0; i < SIZEOFMAZE; i++)
		limits[0][i] = '*';
	for (int i = 0; i < SIZEOFMAZE; i++)
		limits[SIZEOFMAZE - 1][i] = '*';
	for (int i = 1; i < (SIZEOFMAZE - 1); i++)
	{
		for (int j = 0; j < SIZEOFMAZE; j++)
		{
			if (j == 0 || (j = SIZEOFMAZE - 1))
				limits[i][j] = '*';
		}
	}
	makingMaze();//making the maze according to the instruction
}
//_______________________________________________________________________________________________________________
void maze::solveMaxe()/// agood function i must make alittle changes------------------------------------------------
{
	int CurrentHeight;
	int currentWidth;
	bool isQueueEmpty = false;// if there are no more points there is no way from the start spot to the finish spot
	bool finishTheMaze = false;// if the queue head points are same as the finish points
	

	while (finishTheMaze != true && isQueueEmpty==false)//we will exit the loop in to option if we finish the maze or we get stuck 
	{
		xypoint temp = q1.DeQueue();//we take of the head of the queue
		 CurrentHeight = temp.getHight();
		 currentWidth = temp.getWidth();
		 if (limits[CurrentHeight][currentWidth] != '$')// if the spot isnt $ we havent visit it yet . 
		 {
			 if (currentWidth == (SIZEOFMAZE - 1) && CurrentHeight == (SIZEOFMAZE - 2))//if the queue head is at the finish spot, we find a path from the beggining 
			 {
				 cout << "-------------there is a path---------------" << endl;
				 limits[CurrentHeight][currentWidth] = '$';
				 finishTheMaze = true;
				 continue;
			 }
			 if (q1.isFull() == 1)// if the queue is full 
			 {
				 cout << "the queue is full " << endl;
				 exit(1);
			 }
			 if (checkIfAvailable(CurrentHeight, currentWidth + 1) && currentWidth != (SIZEOFMAZE - 1))//checkng if we can walk to the right side of the current point 
			 {
				 q1.EnQueue(xypoint(CurrentHeight, currentWidth + 1));
			 }
			 if (checkIfAvailable(CurrentHeight + 1, currentWidth))//checkng if we can walk down  from the current point 
			 {
				 q1.EnQueue(xypoint(CurrentHeight + 1, currentWidth));
			}
			 if (checkIfAvailable(CurrentHeight, currentWidth - 1) && currentWidth != 0)//checkng if we can walk to the left side of the current point 
			 {
				 q1.EnQueue(xypoint(CurrentHeight, currentWidth - 1));
				
			 }
			 if (checkIfAvailable(CurrentHeight - 1, currentWidth))//checkng if there is no wall upper then th current point 
			 {
				 q1.EnQueue(xypoint(CurrentHeight - 1, currentWidth));
			
			 }
			 isQueueEmpty = q1.isEmpty();// if the queue is Empty

			 if (isQueueEmpty == true)
			 {
				 cout << "------------there is no path from the start spot to the finish spot-----------" << endl;

				 exit(1);
			 }
		 }
		 limits[CurrentHeight][currentWidth] = '$';//mark the current spot as one we have visit at
		
	}
}
//___________________________________________________________________________________________________________________________________________________________________________________
void maze::printMaze()
{
	for (int i = 0; i < SIZEOFMAZE; i++) 
	{
		for (int j = 0; j < SIZEOFMAZE; j++) {
			cout << "" << limits[i][j];
		}
		cout << endl;
	
	}
}
void maze::makingMaze()
{
	/*
	limits[1][2] = '*';	limits[1][6] = '*';	limits[1][8] = '*';	limits[2][2] = '*';	limits[2][3] = '*';
	limits[2][4] ='*'; limits[2][6]='*'; limits[2][8] = '*';	limits[4][1] = '*';	limits[4][2] = '*';	limits[4][3] = '*';	limits[4][4] = '*';
	limits[4][6] = '*'; limits[4][7] = '*'; limits[4][8] = '*';	limits[5][2] = '*';	limits[5][6] = '*';	limits[6][2] = '*';	limits[6][4] = '*';
	limits[6][6] = '*'; limits[6][7] = '*'; limits[6][8] = '*';	limits[7][4] = '*';	limits[7][8] = '*';	limits[8][2] = '*';	limits[8][4] = '*';
	limits[8][5] = '*'; limits[8][6] = '*'; limits[8][8] = '*';	limits[8][9] = '*';	limits[9][2] = '*';	limits[9][4] = '*', limits[2][5] = '*';
	limits[1][0] = NULL; limits[SIZEOFMAZE - 2][SIZEOFMAZE - 1] = NULL;
	*/
	limits[2][1] = '*'; limits[2][2] = '*'; limits[2][3] = '*', limits[1][5] = '*';
	limits[1][0] = NULL; limits[SIZEOFMAZE - 2][SIZEOFMAZE - 1] = NULL;
}
bool maze::checkIfAvailable(int heightCur, int widthCur)
{
	return (limits[heightCur][widthCur] != '$' &&limits[heightCur][widthCur] != '*');
		
		
}
//_____________________________________________________________________________________________
void maze::setMazeAtBegining()
{
	for (int i = 0; i < SIZEOFMAZE; i++)
	{
		for (int j = 0; j < SIZEOFMAZE; j++)
			limits[i][j] = NULL;
	}
	for (int i = 0; i < SIZEOFMAZE; i++)
		limits[0][i] = '*';
	for (int i = 0; i < SIZEOFMAZE; i++)
		limits[SIZEOFMAZE - 1][i] = '*';
	for (int i = 1; i < (SIZEOFMAZE - 1); i++)
	{
		for (int j = 0; j < SIZEOFMAZE; j++)
		{
		
			if (j % 2 == 0)
				limits[i][j] = '*';
		}
	}
	limits[1][0] = NULL;
	limits[SIZEOFMAZE - 2][SIZEOFMAZE - 1] = NULL;
	xypoint temp;
	s1.push(xypoint(1, 1));
	xypoint arrayP[4];
	while (s1.isEmpty() == false) 
	{
		temp = s1.pop();
		int  CurrentHeight = temp.getHight();
		int currentWidth = temp.getWidth();
		if (checkIfAvailable(CurrentHeight, currentWidth + 1) && currentWidth != (SIZEOFMAZE - 1))//checkng if we can walk to the right side of the current point 
		{
			arrayP[0]=(CurrentHeight, currentWidth+1);
		}
		if (checkIfAvailable(CurrentHeight + 1, currentWidth))//checkng if we can walk down  from the current point 
		{
			arrayP[1] = (CurrentHeight+1, currentWidth);
		}
		if (checkIfAvailable(CurrentHeight, currentWidth - 1) && currentWidth != 0)//checkng if we can walk to the left side of the current point 
		{
			arrayP[2] = (CurrentHeight, currentWidth-1);

		}
		if (checkIfAvailable(CurrentHeight - 1, currentWidth))//checkng if there is no wall upper then th current point 
		{
			arrayP[3] = (CurrentHeight-1, currentWidth);

		}
	}

	srand(time(NULL));// that way we can have arandom number every time 
	int i = rand()%5;
	cout << i;
	
}





//_______________________________________________________________________________________________________________________________________________
// the main is
/*

*/