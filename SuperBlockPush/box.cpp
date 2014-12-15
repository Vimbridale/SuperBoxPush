#include "box.h"
#include <string>
#include <fstream>

using namespace std;

box::box(){
	coordinates[0] = -1;
	coordinates[1] = -1;
	type = "normal";
}

bool box::occupied(int cords[2]){
	bool tmp = false;
	if (cords[0] > coordinates[0] - 2 && cords[0] < coordinates[0] + 2 && cords[1] > coordinates[1] - 2 && cords[1] < coordinates[1] + 2)
		tmp = true;
	return tmp;
}

void box::render(int start[2], char map[5][5]) {
	ifstream fin;
	fin.open("box_normal.txt");
	start[0] = coordinates[0] - 2;
	start[1] = coordinates[1] - 2;
	char tmp;
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			fin >> tmp;
			map[j][i] = tmp;
		}
	}
}

void box::collides(bool set[200], box boxes[200], int move[2], bool& flag, int pointer) {
	if (coordinates[0] > 198 || coordinates[1] > 198 || coordinates[0] < 3 || coordinates[1] < 3)
		flag = true;
	for (int i = 0; i < 200; i ++) {
		for (int j = 0; j < 7; j++) {
			for (int k = 0; k < 7; k++) {
				int tmpCords1[2] = {coordinates[0] - 3 + j, coordinates[1] - 3 + k};
				int tmpCords2[2] = {tmpCords1[0] + move[0], tmpCords1[1] + move[1]};
				bool tmpBool1 = occupied(tmpCords1);
				bool tmpBool2 = boxes[i].occupied(tmpCords2);
				if (tmpBool1 && tmpBool2 && i < pointer) {
					set[i] = true;
					boxes[i].collides(set, boxes, move, flag, i);
					
				}
			}
		}
	}
}