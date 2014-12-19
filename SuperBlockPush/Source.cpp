#include "header.h"


using namespace std;

int main(){
	srand(time(0));
	box boxes[200];
	int strength = 3;
	for (int i = 0; i < 200; i++){
		place(boxes, i);
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


void place(box boxes[200], int pointer) {
	bool validplace = false;
	while (!validplace) {
		validplace = true;
		boxes[pointer].coordinates[0] = ((rand() % 196) + 2);
		boxes[pointer].coordinates[1] = ((rand() % 196) + 2);
		for (int i = 0; i < 200; i++) {
			if (boxes[pointer].close(boxes[i].coordinates) && pointer != i) {
				for (int j = -3; j < 3; j++) {
					for (int k = -3; k < 3; k++) {
						int tmpcords[] = {boxes[pointer].coordinates[0] + j, boxes[pointer].coordinates[1] + k};
						if (boxes[pointer].occupied(tmpcords) && boxes[i].occupied(tmpcords)) {
							validplace = false;
						}
					}
				}
			}
		}
	}
}