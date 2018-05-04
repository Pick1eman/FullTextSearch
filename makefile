bin/FullTextSearch: build/main.o build/dir_tree.o
	gcc -Wall -o bin/FullTextSearch build/main.o build/dir_tree.o
build/main.o: src/main.c
	gcc -Wall -c -o build/main.o src/main.c
build/dir_tree.o: src/dir_tree.c
	gcc -Wall -c -o build/dir_tree.o src/dir_tree.c

clean:
		rm build/main.o

