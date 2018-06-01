.PHONY: clean

all: main.o traversal.o search.o int_vector.o output.o strings.o
		gcc -Wall -std=c99 build/main.o build/traversal.o build/search.o build/int_vector.o build/output.o build/strings.o -o bin/ftsearch
test: test_main.o traversal.o search.o int_vector.o output.o strings.o
		gcc -Wall -std=c99 build/test/main.o build/traversal.o build/search.o build/int_vector.o build/output.o build/strings.o -o bin/ftsearch_test
test_main.o: 
		gcc -Wall -std=c99 -I src -I thirdparty -c test/main.c -o build/test/main.o
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
strings.o:
		gcc -Wall -std=c99 -c src/strings.c -o build/strings.o

clean:
		rm build/*.o build/test/*.o

dir:
		mkdir build
		mkdir build/test
		mkdir bin
		mkdir logs
