#ifndef BOARDGAME_H
#define BOARDGAME_H

class boardgame {
private:
	int boardSize, numOfTraps;
	int gCoor[2], xCoor[2], trapCoor[10][2];
	int *trapPtr;

public:
	boardgame();
	void setSize(int x);
	void setGCoor(int x, int y);
	void setXCoor(int x, int y);
	void setTrapCoor(int ind, int x, int y);
	void moveG(int x, int y);
	void moveX(int x, int y);
	void moveTraps(bool bl);
	void displayCoor();
	
	int status();
	int sub2ind(int i, int j);
	void makeBoard();

};

#endif