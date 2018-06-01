#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <dirent.h>
#include "strings.h"
#include "int_vector.h"
#include "output.h"
#include "traversal.h"
#include "search.h"

char *sample;

int r = 0, h = 0;

extern size_t general_counter;

int main(int argc, char *argv[])
{
	int retry = 0;

	do {
		FILE *log = fopen("./logs/user.log", "w");
		fprintf(log, "Search failed\n");
		fclose(log);

		if (argc == 5) {
			if (!scmp(argv[1], "-r") && (!scmp(argv[2], "-h"))) {
				DIR *check_dir = opendir(argv[4]);
				if (check_dir != NULL) {
					closedir(check_dir);
					sample = argv[3];
					r = 1;
					h = 1;
					//Скрытые папки/файлы
					beginning_output(argv[4]);
					traversal(argv[4]);
					printf("Search done\n");
				} else {
					printf("Directory doesn't exist or cannot be opened\nSearch failed\n");
					return -1;
				}
			} else {
				printf("Invalid key\nSearch failed\n");
				return -1;
			}
		} else if (argc == 4) {
			if (!scmp(argv[1], "-r")) {
				DIR *check_dir = opendir(argv[3]);
				if (check_dir != NULL) {
					closedir(check_dir);
					sample = argv[2];
					r = 1;
					beginning_output(argv[3]);
					traversal(argv[3]);
					printf("Search done\n");
				} else {
					printf("Directory doesn't exist or cannot be opened\nSearch failed\n");
					return -1;
				}
			} else if (!scmp(argv[1], "-h")) {
				DIR *check_dir = opendir(argv[3]);
				if (check_dir != NULL) {
					closedir(check_dir);
					sample = argv[2];
					h = 1;
					//Скрытые папки/файлы
					beginning_output(argv[3]);
					traversal(argv[3]);
					printf("Search done\n");
				} else {
					printf("Directory doesn't exist or cannot be opened\nSearch failed\n");
					return -1;
				}
			} else {
					printf("Invalid key\nSearch failed\n");
				return -1;
			}
		} else if (argc == 3) {	
			DIR *check_dir = opendir(argv[2]);
			if (check_dir != NULL) {
				closedir(check_dir);
				sample = argv[1];
				beginning_output(argv[2]);
				traversal(argv[2]);
				printf("Search done\n");
			} else {
				printf("Directory doesn't exist or cannot be opened\nSearch failed\n");
				return -1;
			}
		} else {
			printf("Invalid arguments number\nSearch failed\n");
			return -1;
		}

		ending_output();

		general_counter = 0;

		printf("Do yoy want to try again? (1 - yes / 0 - no)\n> ");
		scanf("%d", &retry);

	} while (retry);
	
	return 0;
}
