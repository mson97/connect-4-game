connectn.out: main.o board.o valid.o move.o win.o
	gcc -g -Wall -Werror -o connectn.out main.o board.o valid.o move.o win.o

main.o: main.c board.h move.h win.h
	gcc -g -Wall -Werror -c main.c

board.o: board.c board.h
	gcc -g -Wall -Werror -c board.c

move.o: move.c move.h valid.h board.h
	gcc -g -Wall -Werror -c move.c

win.o: win.c win.h board.h
	gcc -g -Wall -Werror -c win.c

clean:
	rm -f *.o *.out