inventory2.exe: inventory2.o readline.o
	gcc -o inventory2.exe inventory2.o readline.o
inventory3.exe: inventory3.o readline.o
	gcc -o inventory3.exe inventory3.o readline.o
inventory4.exe: inventory4.o readline.o
	gcc -o inventory4.exe inventory4.o readline.o
inventory2.o: inventory2.c readline.h
	gcc -c inventory2.c
inventory3.o: inventory3.c readline.h
	gcc -c inventory3.c
inventory4.o: inventory4.c readline.h
	gcc -c inventory4.c
readline.o: readline.c readline.h
	gcc -c readline.c