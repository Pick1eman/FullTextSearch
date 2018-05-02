bin/FullTextSearch: build/main.o build/hashtab.o build/build_hashtab.o
		gcc -Wall -o bin/FullTextSearch build/main.o build/hashtab.o build/build_hashtab.o
build/main.o: src/main.c
		gcc -c -o build/main.o src/main.c
build/hashtab.o: src/hashtab.c
		gcc -c -o build/hashtab.o src/hashtab.c
build/build_hashtab.o: src/build_hashtab.c
		gcc -c -o build/build_hashtab.o src/build_hashtab.c

clean:
		rm build/main.o build/hashtab.o build/build_hashtab.o

