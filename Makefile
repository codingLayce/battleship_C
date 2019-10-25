CFLAGS=-Wall -Wextra -pedantic -ansi -W -g -lncurses
TEST_CFLAGS=-Wall -Wextra -pedantic -W -lrt -lm
INCLUDES=-Iinclude -Ietc
BINOBJECT=bin/.o_file/

all: battleship

battleship: main.o boat.o player.o board.o cell.o view.o board_view.o game.o
	gcc $(INCLUDES) $(BINOBJECT)*.o -o bin/battleship $(CFLAGS)
	cp game.save.test game.save

main.o: src/main.c
	gcc -c $(INCLUDES) src/main.c -o $(BINOBJECT)main.o $(CFLAGS)

# MODEL
boat.o: src/boat/boat.c
	gcc $(INCLUDES) -c src/boat/boat.c -o $(BINOBJECT)boat.o $(CFLAGS)

player.o: src/player/player.c
	gcc $(INCLUDES) -c src/player/player.c -o $(BINOBJECT)player.o $(CFLAGS)

cell.o: src/cell/cell.c
	gcc $(INCLUDES) -c src/cell/cell.c -o $(BINOBJECT)cell.o $(CFLAGS)

board.o: src/board/board.c
	gcc $(INCLUDES) -c src/board/board.c -o $(BINOBJECT)board.o $(CFLAGS)

game.o: src/game/game.c
	gcc $(INCLUDES) -c src/game/game.c -o $(BINOBJECT)game.o $(CFLAGS)

#VIEW
view.o: src/view/view.c
	gcc $(INCLUDES) -c src/view/view.c -o $(BINOBJECT)view.o $(CFLAGS)

board_view.o: src/view/board_view.c	
	gcc $(INCLUDES) -c src/view/board_view.c -o $(BINOBJECT)board_view.o $(CFLAGS)

# TESTS
test_boat: boat.o test/boat/boat.c
	gcc $(INCLUDES) $(BINOBJECT)boat.o test/boat/boat.c -o bin/test_boat $(TEST_CFLAGS)

test_player: player.o board.o cell.o boat.o test/player/player.c 
	gcc $(INCLUDES) $(BINOBJECT)player.o $(BINOBJECT)board.o $(BINOBJECT)cell.o $(BINOBJECT)boat.o test/player/player.c -o bin/test_player $(TEST_CFLAGS)

test_cell: cell.o boat.o board.o player.o test/cell/cell.c	
	gcc $(INCLUDES) $(BINOBJECT)cell.o $(BINOBJECT)boat.o $(BINOBJECT)board.o $(BINOBJECT)player.o test/cell/cell.c -o bin/test_cell $(TEST_CFLAGS)

test_board: board.o cell.o test/board/board.c boat.o
	gcc $(INCLUDES) $(BINOBJECT)board.o $(BINOBJECT)cell.o $(BINOBJECT)boat.o test/board/board.c -o bin/test_board $(TEST_CFLAGS)

run_tests: test_player test_boat test_cell
	bin/test_boat;bin/test_player;bin/test_cell

clean:
	rm -Rf *.o
