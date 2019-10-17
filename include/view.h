#ifndef VIEW_H_GUARD
#define VIEW_H_GUARD

#include <ncurses.h>

#define POP_UP_PAIR 6

void init_view ();
void end_view ();

/* @return the selected choice */
int create_pop_up (int start_row, int start_col, int height, int width, char *ask, char * choices, int number);

#endif
