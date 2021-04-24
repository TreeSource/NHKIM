compare: compare.o compare_dates.o
	gcc -o compare.exe compare.o compare_dates.o
compare.o: compare.c compare_dates.h
	gcc -c compare.c
compare_dates.o: compare_dates.c compare_dates.h
	gcc -c compare_dates.c