#include "cell.h"

void new_cell(Cell *cell, Boat *boat, int touched){
	cell->boat = boat;
	cell->touched = touched;
}
