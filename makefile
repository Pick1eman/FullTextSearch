bin/FullTextSearch: build/main.o build/dir_tree.o build/search.o build/int_vector.o build/output.o
		gcc -Wall build/main.o build/dir_tree.o build/search.o build/int_vector.o build/output.o -o bin/FullTextSearch
build/main.o: src/main.c
		gcc -Wall -c src/main.c -o build/main.o
build/dir_tree.o: src/dir_tree.c
		gcc -Wall -c src/dir_tree.c -o build/dir_tree.o
build/search.o: src/search.c
		gcc -Wall -c src/search.c -o build/search.o
build/int_vector.o: src/int_vector.c
		gcc -Wall -c src/int_vector.c -o build/int_vector.o
build/output.o: src/output.c
		gcc -Wall -c src/output.c -o build/output.o

clean:
		rm build/*.o

dir:
		mkdir build
		mkdir bin
		mkdir logs
