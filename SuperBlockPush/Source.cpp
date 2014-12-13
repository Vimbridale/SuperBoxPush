#include "header.h"


using namespace std;

int main(){
	srand(time(0));
	box boxes[200];
	int strength = 3;
	for (int i = 0; i < 200; i++){
		boxes[i].coordinates[0] = (rand() % 195 + 2);
		boxes[i].coordinates[1] = (rand() % 195 + 2);
	}
	player player;
	world world;
	while(1) {
		world.printWorld(player, boxes);
		char tmp;
		int x;
		tmp = _getch();
		if (tmp == 'w') {
			x = 4;
		}else if (tmp == 'a') {
			x = 3;
		}else if (tmp == 's') {
			x = 2;
		}else if (tmp == 'd') {
			x = 1;
		}
		player.move(x, boxes, strength);
	}
}
