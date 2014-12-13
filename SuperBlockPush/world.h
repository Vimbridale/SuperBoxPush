#ifndef world_h
#define world_h
#include "player.h"
#include "box.h"
//woot!
class world
{
public:
	world();
	void printWorld(player player, box boxes[200]);
};


#endif