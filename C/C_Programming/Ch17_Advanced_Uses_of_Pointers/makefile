remind2: 17_2_remind2.o
	gcc -o remind2.exe 17_2_remind2.o
inventory2: 17_5_inventory2.o readline.o
	gcc -o inventory2.exe 17_5_inventory2.o readline.o
tabulate: 17_7_tabulate.o
	gcc -o tabulate.exe 17_7_tabulate.o -lm
17_2_remind2.o: 17_2_remind2.c readline.h
	gcc -c 17_2_remind2.c
17_5_inventory2.o: 17_5_inventory2.c readline.h
	gcc -c 17_5_inventory2.c
readline.o: readline.c readline.h
	gcc -c readline.c
17_7_tabulate.o: 17_7_tabulate.c
	gcc -c 17_7_tabulate.c