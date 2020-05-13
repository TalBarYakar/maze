#include"maze.h"
int main()
{
	
	int userChoice;
	int height, width;
	cout << "would you like to make your owen Maze? press 0   or  you want it to create randomly? press 1" << endl;
	cin >> userChoice;
	cout << "type you maze height" << endl;
	cin >> height;
	cout << "type th maze width" << endl;
	cin >> width;
	switch (userChoice)
	{
	case 0:
		if (height > 25 || width > 80)
			cout << "the maze limits are too big" << endl;
		maze currentMaze(height, width);

	}
	system("pause");
}