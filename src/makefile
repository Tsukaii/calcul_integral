all : simpson.o fonctions.o main.o
	gcc simpson.o fonctions.o main.o -o main -lm
	
simpson.o : simpson.c simpson.h
	gcc -c simpson.c
	
fonctions.o: fonctions.c fonctions.h
	gcc -c fonctions.c
	
main.o: main.c
	gcc -c main.c

