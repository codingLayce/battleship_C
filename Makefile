CFLAGS=-Wall -Wextra -pedantic -ansi -W -g -lncurses -fPIC
TEST_CFLAGS=-Wall -Wextra -pedantic -W -lrt -lm
INCLUDES=-Iinclude -Ietc
OBJS_DIR=bin/.o_file/
OBJS=boat.o player.o cell.o board.o game.o view.o board_view.o main.o
OBJS_PATH=$(addprefix $(OBJS_DIR), $(OBJS))
CC=gcc

.PHONY: clean

all: battleship

battleship: $(OBJS)
	$(CC) $(INCLUDES) $(OBJS_PATH) -o bin/$@ -lncurses
	cp game.save.test game.save

main.o: src/main.c
	$(CC) -c $(INCLUDES) $< -o $(OBJS_DIR)$@ $(CFLAGS)

# MODEL
boat.o: src/boat/boat.c
	$(CC) $(INCLUDES) -c $< -o $(OBJS_DIR)$@ $(CFLAGS)

player.o: src/player/player.c
	$(CC) $(INCLUDES) -c $< -o $(OBJS_DIR)$@ $(CFLAGS)

cell.o: src/cell/cell.c
	$(CC) $(INCLUDES) -c $< -o $(OBJS_DIR)$@ $(CFLAGS)

board.o: src/board/board.c
	$(CC) $(INCLUDES) -c $< -o $(OBJS_DIR)$@ $(CFLAGS)

game.o: src/game/game.c
	$(CC) $(INCLUDES) -c $< -o $(OBJS_DIR)$@ $(CFLAGS)

#VIEW
view.o: src/view/view.c
	$(CC) $(INCLUDES) -c $< -o $(OBJS_DIR)$@ $(CFLAGS)

board_view.o: src/view/board_view.c	
	$(CC) $(INCLUDES) -c $< -o $(OBJS_DIR)$@ $(CFLAGS)

# TESTS
test_boat: boat.o test/boat/boat.c
	$(CC) $(INCLUDES) $(OBJS_DIR)boat.o test/boat/boat.c -o bin/$@ $(TEST_CFLAGS)

test_player: player.o board.o cell.o boat.o board_view.o test/player/player.c 
	$(CC) $(INCLUDES) $(addprefix $(OBJS_DIR), $(filter %.o, $^)) test/player/player.c -o bin/$@ $(TEST_CFLAGS) -lncurses

test_cell: cell.o boat.o board.o player.o board_view.o test/cell/cell.c	
	$(CC) $(INCLUDES) $(addprefix $(OBJS_DIR), $(filter %.o, $^)) test/cell/cell.c -o bin/$@ $(TEST_CFLAGS) -lncurses

test_board: board.o cell.o test/board/board.c boat.o
	$(CC) $(INCLUDES) $(addprefix $(OBJS_DIR), $(filter %.o, $^)) test/board/board.c -o bin/$@ $(TEST_CFLAGS)

run_tests: test_player test_boat test_cell test_board
	bin/test_boat
	bin/test_player
	bin/test_cell
	bin/test_board

gameboard.a: $(OBJS)
	ar rcs bin/$@ $(OBJS_PATH)

gameboard.so: $(OBJS)
	$(CC) $(INCLUDES) $(OBJS_PATH) -o bin/$@ -lncurses -shared

clean:
	rm -Rf $(OBJS_DIR)*.o
	rm bin/test_*
	rm bin/battleship
	rm bin/gameboard.*
