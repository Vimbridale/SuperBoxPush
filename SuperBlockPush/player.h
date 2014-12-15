#ifndef player_h
#define player_h
#include "box.h"
class player {
public:
	int coordinates[2];
	void move(int move[2], box boxes[200], int strength);
	player();
};

#endif