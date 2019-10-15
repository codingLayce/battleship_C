CFLAGS=-Wall -Wextra -pedantic -ansi -W -g
TEST_CFLAGS=-Wall -Wextra -pedantic -W -lrt -lm
INCLUDES=-Iinclude -Ietc

all: battleship

battleship: main.o
	gcc $(INCLUDES) bin/.o_file/main.o -o bin/battleship $(CFLAGS)

main.o: src/main.c
	gcc -c $(INCLUDES) src/main.c -o bin/.o_file/main.o $(CFLAGS)

boat.o: src/boat/boat.c
	gcc $(INCLUDES) -c src/boat/boat.c -o bin/.o_file/boat.o $(CFLAGS)

player.o: src/player/player.c
	gcc $(INCLUDES) -c src/player/player.c -o bin/.o_file/player.o $(CFLAGS)

test_boat: boat.o test/boat/boat.c
	gcc $(INCLUDES) bin/.o_file/boat.o test/boat/boat.c -o bin/test_boat $(TEST_CFLAGS)

test_player: player.o test/player/player.c 
	gcc $(INCLUDES) bin/.o_file/player.o test/player/player.c -o bin/test_player $(TEST_CFLAGS)

run_tests: test_player test_boat
	bin/test_boat
	echo "###################"
	bin/test_player

clean:
	rm -Rf *.o
