.PHONY: clean

all: main.o traversal.o search.o int_vector.o output.o
		gcc -Wall build/main.o build/traversal.o build/search.o build/int_vector.o build/output.o -o bin/FullTextSearch
main.o:
		gcc -Wall -c src/main.c -o build/main.o
traversal.o:
		gcc -Wall -c src/traversal.c -o build/traversal.o
search.o:
		gcc -Wall -c src/search.c -o build/search.o
int_vector.o:
		gcc -Wall -c src/int_vector.c -o build/int_vector.o
output.o:
		gcc -Wall -c src/output.c -o build/output.o

clean:
		rm build/*.o

dir:
		mkdir build
		mkdir bin
		mkdir logs
