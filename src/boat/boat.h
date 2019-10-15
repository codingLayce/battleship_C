#ifndef BOAT_H_GUARD
#define BOAT_H_GUARD

/* A, B, C, S, D  */
typedef enum {CARRIER, BATTLESHIP, CRUISER, SUBMARINE, DESTROYER} Boat_type;

typedef struct {
	char boat_char;
	int size;
	int hits;
} Boat;

void boat_factory(Boat *boat, Boat_type type);

void new_boat(Boat *boat, char boat_char, int size, int hits);

#endif
