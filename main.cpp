#include <iostream>
#include "boardgame.h"
#include <string.h>

using namespace std;

int main() {
	boardgame bgObj;
	char input;
	int status = bgObj.status();
	while (status == 0) {
		bgObj.makeBoard();
		cout << "Use a, d, w, s to move left, right, up, down to X: ";
		cin >> input;
		if (strncmp(&input, "a", 1) == 0) {
			cout << "You moved to the left." << endl;
			bgObj.moveG(0, -1);
		}
		else if (strncmp(&input, "d", 1) == 0) {
			cout << "You moved to the right." << endl;
			bgObj.moveG(0, 1);
		}
		else if (strncmp(&input, "w", 1) == 0) {
			cout << "You moved up." << endl;
			bgObj.moveG(-1, 0);
		}
		else if (strncmp(&input, "s", 1) == 0) {
			cout << "You moved down." << endl;
			bgObj.moveG(1, 0);
		}
		else {
			cout << "Unrecognized input" << endl;
			cout << "Use a, d, w, s to move left, right, up, down to X: " << endl;
		}

		bgObj.moveTraps(true);
		status = bgObj.status();
	}
	bgObj.makeBoard();
	return 0;
}