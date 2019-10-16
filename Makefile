CFLAGS=-Wall -Wextra -pedantic -ansi -W -g -lncurses
TEST_CFLAGS=-Wall -Wextra -pedantic -W -lrt -lm
INCLUDES=-Iinclude -Ietc

all: battleship

battleship: main.o boat.o player.o board.o cell.o view.o board_view.o
	gcc $(INCLUDES) bin/.o_file/*.o -o bin/battleship $(CFLAGS)

main.o: src/main.c
	gcc -c $(INCLUDES) src/main.c -o bin/.o_file/main.o $(CFLAGS)

# MODEL
boat.o: src/boat/boat.c
	gcc $(INCLUDES) -c src/boat/boat.c -o bin/.o_file/boat.o $(CFLAGS)

player.o: src/player/player.c
	gcc $(INCLUDES) -c src/player/player.c -o bin/.o_file/player.o $(CFLAGS)

cell.o: src/cell/cell.c
	gcc $(INCLUDES) -c src/cell/cell.c -o bin/.o_file/cell.o $(CFLAGS)

board.o: src/board/board.c
	gcc $(INCLUDES) -c src/board/board.c -o bin/.o_file/board.o $(CFLAGS)

#VIEW
view.o: src/view/view.c
	gcc $(INCLUDES) -c src/view/view.c -o bin/.o_file/view.o $(CFLAGS)

board_view.o: src/view/board_view.c	
	gcc $(INCLUDES) -c src/view/board_view.c -o bin/.o_file/board_view.o $(CFLAGS)

# TESTS
test_boat: boat.o test/boat/boat.c
	gcc $(INCLUDES) bin/.o_file/boat.o test/boat/boat.c -o bin/test_boat $(TEST_CFLAGS)

test_player: player.o test/player/player.c 
	gcc $(INCLUDES) bin/.o_file/player.o test/player/player.c -o bin/test_player $(TEST_CFLAGS)

test_cell: cell.o boat.o test/cell/cell.c	
	gcc $(INCLUDES) bin/.o_file/cell.o bin/.o_file/boat.o test/cell/cell.c -o bin/test_cell $(TEST_CFLAGS)

test_board: board.o cell.o test/board/board.c
	gcc $(INCLUDES) bin/.o_file/board.o bin/.o_file/cell.o test/board/board.c -o bin/test_board $(TEST_CFLAGS)

run_tests: test_player test_boat test_cell
	bin/test_boat;bin/test_player;bin/test_cell

clean:
	rm -Rf *.o
