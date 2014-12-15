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
		int move[2] = {0,0};
		tmp = _getch();
		if (tmp == 'w') {
			move[1] = 1;
		}else if (tmp == 'a') {
			move[0] = -1;
		}else if (tmp == 's') {
			move[1] = -1;
		}else if (tmp == 'd') {
			move[0] = 1;
		}
		player.move(move, boxes, strength);
	}
}
