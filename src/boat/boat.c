#include <stdlib.h>
#include "boat.h"

void boat_factory(Boat *boat, Boat_type type){
	switch (type) {
		case CARRIER:
			new_boat(boat, 'A', 5, 0);
			break;
		case BATTLESHIP:
			new_boat(boat, 'B', 4, 0);
			break;
		case CRUISER:
			new_boat(boat, 'C', 3, 0);
			break;
		case SUBMARINE:
			new_boat(boat, 'S', 3, 0);
			break;
		case DESTROYER:
			new_boat(boat, 'D', 2, 0);
			break;
		default:
			boat = NULL;
			break;
	}
}

void new_boat(Boat *boat, char boat_char, int size, int hits){
	boat->boat_char = boat_char;
	boat->size = size;
	boat->hits = hits;
}


