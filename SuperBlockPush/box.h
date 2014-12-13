#ifndef box_h
#define box_h
#include <string>

class box
{
public:
	int coordinates[2];
	std::string type;
	box();
	void render(int start[2], char map[5][5]);
	bool occupied(int cords[2]);
	void pushable(bool set[200], box boxes[200], int direction, bool& flag);
};

#endif