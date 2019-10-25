#include <stdlib.h>
#include "boat.h"

void boat_factory(Boat *boat, Boat_type type){
	switch (type) {
		case CARRIER:
			new_boat(boat, 'A', 5, 0, -1, -1, NORTH);
			break;
		case BATTLESHIP:
			new_boat(boat, 'B', 4, 0, -1, -1, NORTH);
			break;
		case CRUISER:
			new_boat(boat, 'C', 3, 0, -1, -1, NORTH);
			break;
		case SUBMARINE:
			new_boat(boat, 'S', 3, 0, -1, -1, NORTH);
			break;
		case DESTROYER:
			new_boat(boat, 'D', 2, 0, -1, -1, NORTH);
			break;
		default:
			boat = NULL;
			break;
	}
}

void new_boat(Boat *boat, char boat_char, int size, int hits, int row, int col, Direction dir){
	boat->boat_char = boat_char;
	boat->size = size;
	boat->hits = hits;
	boat->start_row = row;
	boat->start_col = col;
	boat->direction = dir;
}


