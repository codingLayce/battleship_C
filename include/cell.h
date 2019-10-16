#ifndef CELL_H_GUARD
#define CELL_H_GUARD

#include "boat.h"

typedef struct {
	Boat *boat;
	int touched;
} Cell;

void new_cell(Cell *cell, Boat *boat, int touched);

void set_boat(Cell *cell, Boat *boat);

#endif
