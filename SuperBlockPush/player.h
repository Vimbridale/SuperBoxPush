#ifndef player_h
#define player_h
#include "box.h"
class player {
public:
	int coordinates[2];
	void move(int direction, box boxes[200], int strength);
	player();
};

#endif