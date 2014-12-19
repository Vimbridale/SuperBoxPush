#include "world.h"
#include <iostream>
#include "Windows.h"

using namespace std;

world::world(){
}

void world::printWorld(player player, box boxes[200]){
	COORD spot = {0,0};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), spot);
	char worldMap[200][200];
	for (int i = 0; i < 200; i++){
		for (int j = 0; j < 200; j++){
			if (i == 0 || i == 199) {
				worldMap[j][i] = '_';
			}else if (j == 0 || j == 199) {
				worldMap[j][i] = '|';
			}else {
				worldMap[j][i] = '.';
			}
		}
	}
	for (int i = 0; i < 200; i++){
		char map[5][5];
		int startCords[2];
		boxes[i].render(startCords, map);
		if (startCords[0] > -1){
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++){
					if (map[j][i] != '.')
						worldMap[startCords[0] + j][startCords[1] + i] = map[j][i];
				}
			}
		}
	}
	worldMap[player.coordinates[0]][player.coordinates[1]] = '@';
	int effectiveCoordinates[2];
	if (player.coordinates[0] < 10) {
		effectiveCoordinates[0] = 10;
	}else if (player.coordinates[0] < 191) {
		effectiveCoordinates[0] = player.coordinates[0];
	}else {
		effectiveCoordinates[0] = 190;
	}
	if (player.coordinates[1] < 10) {
		effectiveCoordinates[1] = 10;
	}else if (player.coordinates[1] < 191) {
		effectiveCoordinates[1] = player.coordinates[1];
	}else {
		effectiveCoordinates[1] = 190;
	}
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			cout << worldMap[effectiveCoordinates[0] - 10 + j][effectiveCoordinates[1] + 10 - i];
		}
		cout << endl;
	}
}