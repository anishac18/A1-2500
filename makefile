chadhaAnishaA1: chadhaAnishaA1.o chadhaAnishaA1Main.o
gcc -Wall -std=c99 chadhaAnishaA1.o chadhaAnishaA1Main.c -o chadhaAnishaA1
chadhaAnishaA1.o: chadhaAnishaA1.c givenA1.h
gcc -Wall -std=c99 -c chadhaAnishaA1.c
chadhaAnishaA1Main.o: chadhaAnishaA1Main.c givenA1.h
gcc -Wall -std=c99 -c chadhaAnishaA1Main.c
clean:
	rm *.o