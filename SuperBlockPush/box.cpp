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
			map[i][j] = tmp;
		}
	}
}

void box::pushable(bool set[200], box boxes[200], int direction, bool& flag){
	int cords1[2], cords2[2], cords3[2];
	switch (direction) {
	case 1: cords1[0] = coordinates[0] - 1; cords1[1] = coordinates[1] + 2;  cords2[0] = coordinates[0]; cords2[1] = coordinates[1] + 2;  cords3[0] = coordinates[0] + 1; cords3[1] = coordinates[1] + 2; break;
	case 2: cords1[0] = coordinates[0] + 2; cords1[1] = coordinates[1] - 1;  cords2[0] = coordinates[0] + 2; cords2[1] = coordinates[1];  cords3[0] = coordinates[0] + 2; cords3[1] = coordinates[1] + 1; break;
	case 3: cords1[0] = coordinates[0] - 1; cords1[1] = coordinates[1] - 2;  cords2[0] = coordinates[0]; cords2[1] = coordinates[1] - 2;  cords3[0] = coordinates[0] + 1; cords3[1] = coordinates[1] - 2; break;
	case 4: cords1[0] = coordinates[0] - 2; cords1[1] = coordinates[1] - 1;  cords2[0] = coordinates[0] - 2; cords2[1] = coordinates[1];  cords3[0] = coordinates[0] - 2; cords3[1] = coordinates[1] + 1; break;
	}
	if(cords1[0] < 1 || cords1[0] > 198 || cords1[1] < 1 || cords1[1] > 198 || cords2[0] < 1 || cords2[0] > 198 || cords2[1] < 1 || cords2[1] > 198 || cords3[0] < 1 || cords3[0] > 198 || cords3[1] < 1 || cords3[1] > 198)
		flag = true;
	for (int i = 0; i < 200; i++) {
		if (boxes[i].occupied(cords1) || boxes[i].occupied(cords2) || boxes[i].occupied(cords3)) {
			set[i] = true;
			boxes[i].pushable(set, boxes, direction, flag);
		}
	}
}