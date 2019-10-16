#include <stdlib.h>
#include "cell.h"

void new_cell (Cell *cell, Boat *boat, int touched){
	cell->boat = boat;
	cell->touched = touched;
}

void set_boat (Cell *cell, Boat *boat) {
	cell->boat = boat;
}

void hit_cell (Cell *cell) {
	cell->touched++;
}
