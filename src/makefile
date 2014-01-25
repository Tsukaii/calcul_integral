all : simpson.o fonctions.o main.o romberg.o trapeze.o
	gcc simpson.o fonctions.o main.o romberg.o trapeze.o -o integrale -lm
	
simpson.o : simpson.c simpson.h
	gcc -c simpson.c
	
fonctions.o: fonctions.c fonctions.h
	gcc -c fonctions.c
	
trapeze.o: trapeze.c trapeze.h
	gcc -c trapeze.c
	
romberg.o: romberg.c romberg.h
	gcc -c romberg.c
	
main.o: main.c
	gcc -c main.c

