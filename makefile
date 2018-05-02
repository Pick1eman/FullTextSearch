bin/FullTextSearch: build/main.o
		gcc -Wall -o bin/FullTextSearch build/main.o
build/main.o: src/main.c
		gcc -c -o build/main.o src/main.c

clean:
		rm build/main.o

