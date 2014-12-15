#include "header.h"


using namespace std;

int main(){
	srand(time(0));
	box boxes[200];
	int strength = 3;
	for (int i = 0; i < 200; i++){
		bool placed = false;
		while (!placed) {
			bool tmp = false;
			int move[] = {0, 0};
			boxes[i].coordinates[0] = (rand() % 195 + 2);
			boxes[i].coordinates[1] = (rand() % 195 + 2);
			for (int o = 0; o < 200; o ++) {
				if (boxes[i].close(boxes[o].coordinates)){
					for (int j = 0; j < 7; j++) {
						for (int k = 0; k < 7; k++) {
							int tmpCords1[2] = {boxes[i].coordinates[0] - 3 + k, boxes[i].coordinates[1] - 3 + j};
							int tmpCords2[2] = {tmpCords1[0] + move[0], tmpCords1[1] + move[1]};
							bool tmpBool1 = boxes[i].occupied(tmpCords1); //Tests if the currently chacking block occupies a space
							bool tmpBool2 = boxes[o].occupied(tmpCords2); //Tests the same space displaced by the movement, where the block will be.
							if (tmpBool1 && tmpBool2 && i != i)
								tmp = true;
						}				
					}
				}
			}
			if (!tmp) {
				placed = true;
			}
		}
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
