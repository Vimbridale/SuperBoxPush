#include "player.h"
#include <iostream>

using namespace std;

player::player(){
	coordinates[0] = 100;
	coordinates[1] = 100;
}
void player::move(int move[], box boxes[200], int strength) {
	// 4
	//3 1
	// 2
	bool tmp = true;
	int tmpCords[2] = {coordinates[0] + move[0], coordinates[1] + move[1]};
	bool set[200];
	bool flag = false;
	for (int i = 0; i < 200; i++) {
		set[i] = false;
	}
	for (int i = 0; i < 200; i++){
		if (boxes[i].occupied(tmpCords)){
			set[i] = true;
			boxes[i].collides(set, boxes, move, flag, i);
		}
	}
	if (flag)
		tmp = false;
	int count = 0;
	for (int i = 0; i < 200; i++) {
		if (set[i])
			count++;
	}
	if (count > strength)
		tmp = false;
	if (tmpCords[0] < 1 || tmpCords[1] < 1 || tmpCords[0] > 198 || tmpCords[1] > 198)
		tmp = false;
	if (tmp) {
		coordinates[0] = tmpCords[0];
		coordinates[1] = tmpCords[1];
		for (int i = 0; i < 200; i++) {
			if(set[i]){
				boxes[i].coordinates[0] += move[0];
				boxes[i].coordinates[1] += move[1];
			}
		}
	}
}

