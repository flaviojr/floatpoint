SRC = src/
OBJ_DIR = /Users/flavioipiranga/git/floatpoint/Floatpoint/
all:main
	cd ./src	; $(MAKE) clean
	cd ./src	; $(MAKE)
	
main: main.o $(SRC)floatpoint.o
	gcc -o executavel main.o $(SRC)floatpoint.o -lgmp -lm

main.o: main.c $(SRC)floatpoint.h
	gcc -o main.o -c main.c
	
clean: 
	rm -rf *.o executavel
