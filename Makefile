all: exec

PEFE = on
PEFD =
PDFE =
PDFD =

exec: main.o PE.o PD.o FE.o FD.o
ifdef PEFE
	gcc -o exec main.o PE.o FE.o
endif
ifdef PEFD
	gcc -o exec main.o PE.o FD.o
endif
ifdef PDFE
	gcc -o exec main.o PD.o FE.o
endif
ifdef PDFD
	gcc -o exec main.o PD.o FD.o
endif
main.o: main.c PE.h PD.h FE.h FD.h
	gcc -o main.o main.c -c -W -Wall -pedantic

PE.o: PE.c PE.h
	gcc -o PE.o PE.c -c -W -Wall -pedantic

PD.o: PD.c PD.h
	gcc -o PD.o PD.c -c -W -Wall -pedantic

FE.o: FE.c FE.h
	gcc -o FE.o FE.c -c -W -Wall -pedantic

FD.o: FD.c FD.h
	gcc -o FD.o FD.c -c -W -Wall -pedantic

# adaptado para windows: rm -> del
clean:
	del -rf *.o exec.exe