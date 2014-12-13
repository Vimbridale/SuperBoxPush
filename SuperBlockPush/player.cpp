#include "player.h"
#include <iostream>

using namespace std;

player::player(){
	coordinates[0] = 100;
	coordinates[1] = 100;
}
void player::move(int direction, box boxes[200], int strength) {
	// 4
	//3 1
	// 2
	bool tmp = true;
	int tmpCords[2];
	switch(direction) {
	case 1: tmpCords[1] = 1 + coordinates[1]; tmpCords[0] = coordinates[0]; break;
	case 2: tmpCords[0] = 1 + coordinates[0]; tmpCords[1] = coordinates[1]; break;
	case 3: tmpCords[1] = -1 + coordinates[1]; tmpCords[0] = coordinates[0]; break;
	case 4: tmpCords[0] = -1 + coordinates[0]; tmpCords[1] = coordinates[1]; break;
	}
	bool set[200];
	bool flag = false;
	for (int i = 0; i < 200; i++) {
		set[i] = false;
	}
	for (int i = 0; i < 200; i++){
		if (boxes[i].occupied(tmpCords)){
			set[i] = true;
			boxes[i].pushable(set, boxes, direction, flag);
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
				switch (direction) {
				case 1:boxes[i].coordinates[1]++; break;
				case 2:boxes[i].coordinates[0]++; break;
				case 3:boxes[i].coordinates[1]--; break;
				case 4:boxes[i].coordinates[0]--; break;
				}
			}
		}
	}
}

