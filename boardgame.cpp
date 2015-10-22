#include "boardgame.h"
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <iterator>

using namespace std;

boardgame::boardgame() {
	boardSize = 10;
	numOfTraps = 20;
	gCoor[0] = rand() % boardSize;
	gCoor[1] = rand() % boardSize;
	xCoor[0] = rand() % boardSize;
	xCoor[1] = rand() % boardSize;
	for(int i = 0; i < numOfTraps; i++) {
		do {
			trapCoor[i][0] = rand() % boardSize;
			trapCoor[i][1] = rand() % boardSize;
		} while (sub2ind(trapCoor[i][0], trapCoor[i][1]) == sub2ind(gCoor[0], gCoor[1]));
	}
}

void boardgame::setSize(int x) {
	boardSize = x;
}

void boardgame::setGCoor(int x, int y) {
	gCoor[0] = max(0, min(x, boardSize - 1));
	gCoor[1] = max(0, min(y, boardSize - 1));
}

void boardgame::setXCoor(int x, int y) {
	xCoor[0] = min(x, boardSize - 1);
	xCoor[1] = min(y, boardSize - 1);
}

void boardgame::setTrapCoor(int ind, int x, int y) {
	if (ind >= numOfTraps)
		return;
	trapCoor[ind][0] = max(0, min(x, boardSize - 1));
	trapCoor[ind][1] = max(0, min(y, boardSize - 1));
}

void boardgame::moveG(int x, int y) {
	setGCoor(gCoor[0] + x, gCoor[1] + y);
}

void boardgame::moveX(int x, int y) {
	setXCoor(xCoor[0] + x, xCoor[1] + y);
}

void boardgame::moveTraps(bool bl) {
	if (!bl)
		return;
	for(int i = 0; i < numOfTraps; i++) {
		int aa, bb;
		aa = rand() % 2;
		bb = rand() % 3 - 1;
		setTrapCoor(i, trapCoor[i][0] + aa * bb, trapCoor[i][1] + (1 - aa) * bb); 
	}
}

void boardgame::displayCoor() {
	cout << "G: " << gCoor[0] << ", " << gCoor[1] << endl;
	cout << "X: " << xCoor[0] << ", " << xCoor[1] << endl;
	for(int i = 0; i < numOfTraps; i++) {
		cout << "Trap[" << i << "]: " << trapCoor[i][0] << ", " << trapCoor[i][1] << endl;
	}
}

int boardgame::status() {
	if (sub2ind(gCoor[0], gCoor[1]) == sub2ind(xCoor[0], xCoor[1])) {
		cout << "Congratulations!" << endl;
		return 1;
	}
	for(int i = 0; i < numOfTraps; i++) {
		if (sub2ind(gCoor[0], gCoor[1]) == sub2ind(trapCoor[i][0], trapCoor[i][1])) {
			cout << "You lose!" << endl;
			return -1;
		}
	}
	return 0;
}

int boardgame::sub2ind(int i, int j) {
	return j * boardSize + i;
}

void boardgame::makeBoard() {
	for(int i = 0; i < boardSize; i++) {
		for(int j = 0; j < boardSize; j++) {
			if (sub2ind(i, j) == sub2ind(gCoor[0], gCoor[1])) {
				cout << "G "; 
				continue;
			}
			if (sub2ind(i, j) == sub2ind(xCoor[0], xCoor[1])) {
				cout << "X "; 
				continue;
			}
			bool trapInRow = false;
			for(int k = 0; k < numOfTraps; k++) {
				if (sub2ind(i, j) == sub2ind(trapCoor[k][0], trapCoor[k][1])) {
					cout << "T "; 
					trapInRow = true;
					break;
				}
			}
			if (!trapInRow)
				cout << ". ";
		}
		cout << "\n";
	}

	displayCoor();
}
