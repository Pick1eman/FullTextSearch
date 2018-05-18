bin/FullTextSearch: build/main.o build/dir_tree.o build/hashtab.o build/build_hashtab.o
		gcc -Wall -o bin/FullTextSearch build/main.o build/dir_tree.o build/hashtab.o build/build_hashtab.o
build/main.o: src/main.c
		gcc -Wall -c -o build/main.o src/main.c
build/dir_tree.o: src/dir_tree.c
		gcc -Wall -c -o build/dir_tree.o src/dir_tree.c
build/hashtab.o: src/hashtab.c
		gcc -Wall -c -o build/hashtab.o src/hashtab.c
build/build_hashtab.o: src/build_hashtab.c
		gcc -Wall -c -o build/build_hashtab.o src/build_hashtab.c

clean:
		rm build/main.o build/dir_tree.o build/hashtab.o build/build_hashtab.o
dir:
		mkdir build
		mkdir bin
		mkdir logs
