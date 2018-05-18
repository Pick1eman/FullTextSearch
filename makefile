bin/FullTextSearch: build/main.o build/dir_tree.o build/search.o
		gcc -Wall -o bin/FullTextSearch build/main.o build/dir_tree.o build/search.o
build/main.o: src/main.c
		gcc -Wall -c -o build/main.o src/main.c
build/dir_tree.o: src/dir_tree.c
		gcc -Wall -c -o build/dir_tree.o src/dir_tree.c
build/search.o: src/search.c
		gcc -Wall -c -o build/search.o src/search.c

clean:
		rm build/*.o
dir:
		mkdir build
		mkdir bin
		mkdir logs
