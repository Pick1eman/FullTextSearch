.PHONY: clean

all: main.o traversal.o search.o int_vector.o output.o
		gcc -Wall -std=c99 build/main.o build/traversal.o build/search.o build/int_vector.o build/output.o -o bin/ftsearch
main.o:
		gcc -Wall -std=c99 -c src/main.c -o build/main.o
traversal.o:
		gcc -Wall -std=c99 -c src/traversal.c -o build/traversal.o
search.o:
		gcc -Wall -std=c99 -c src/search.c -o build/search.o
int_vector.o:
		gcc -Wall -std=c99 -c src/int_vector.c -o build/int_vector.o
output.o:
		gcc -Wall -std=c99 -c src/output.c -o build/output.o

clean:
		rm build/*.o

dir:
		mkdir build
		mkdir bin
		mkdir logs
