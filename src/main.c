#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "int_vector.h"
#include "output.h"
#include "traversal.h"
#include "search.h"

char *sample;

int r = 0, h = 0, s = 0;

extern size_t general_counter;

int main(int argc, char *argv[])
{
	FILE *log = fopen("./logs/user.log", "w");
	fprintf(log, "         Output format\n _____________________________\n|<file_name>: <matches_number>|\n|<line>-<character>           |\n|_____________________________|\n\n");
	fclose(log);

	if (argc == 6) {
		if (!strcmp(argv[1], "-r") && (!strcmp(argv[2], "-h")) && (!strcmp(argv[3], "-s"))) {
			DIR *check_dir = opendir(argv[5]);
			if (check_dir != NULL) {
				closedir(check_dir);
				sample = argv[4];
				r = 1;
				h = 1;
				s = 1;
				traversal(argv[5]);
				//Скрытые папки/файлы
				//Симлинк
				printf("Search done\n");
			} else {
				printf("Directory doesn't exist or cannot be opened\nSearch failed\n");
				return -1;
			 }
		} else {
			printf("Invalid key\nSearch failed\n");
			return -1;
		}		
	} else if (argc == 5) {
		if (!strcmp(argv[1], "-r") && (!strcmp(argv[2], "-h"))) {
			DIR *check_dir = opendir(argv[4]);
			if (check_dir != NULL) {
				closedir(check_dir);
				sample = argv[3];
				r = 1;
				h = 1;
				//Скрытые папки/файлы
				traversal(argv[4]);
				printf("Search done\n");
			} else {
				printf("Directory doesn't exist or cannot be opened\nSearch failed\n");
				return -1;
			}
		} else if (!strcmp(argv[1], "-h") && (!strcmp(argv[2], "-s"))){
			DIR *check_dir = opendir(argv[4]);
			if (check_dir != NULL) {
				closedir(check_dir);
				sample = argv[3];
				h = 1;
				s = 1;
				//Симлинк
				traversal(argv[4]);
				printf("Search done\n");
			} else {
				printf("Directory doesn't exist or cannot be opened\nSearch failed\n");
				return -1;
			}
		} else if (!strcmp(argv[1], "-r") && (!strcmp(argv[2], "-s"))){
			DIR *check_dir = opendir(argv[4]);
			if (check_dir != NULL) {
				closedir(check_dir);
				sample = argv[3];
				r = 1;
				s = 1;
				//Симлинк
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
		if (!strcmp(argv[1], "-r")) {
			DIR *check_dir = opendir(argv[3]);
			if (check_dir != NULL) {
				closedir(check_dir);
				sample = argv[2];
				r = 1;
				traversal(argv[3]);
				printf("Search done\n");
			} else {
				printf("Directory doesn't exist or cannot be opened\nSearch failed\n");
				return -1;
			}
		} else if (!strcmp(argv[1], "-h")) {
			DIR *check_dir = opendir(argv[3]);
			if (check_dir != NULL) {
				closedir(check_dir);
				sample = argv[2];
				h = 1;
				//Скрытые папки/файлы
				traversal(argv[3]);
				printf("Search done\n");
			} else {
				printf("Directory doesn't exist or cannot be opened\nSearch failed\n");
				return -1;
			}
		} else if (!strcmp(argv[1], "-s")) {
			DIR *check_dir = opendir(argv[3]);
			if (check_dir != NULL) {
				closedir(check_dir);
				sample = argv[2];
				s = 1;
				//Симлинк
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

	log = fopen("./logs/user.log", "a");
	fprintf(log, "Total: %zd\n", general_counter);
	fclose(log);
	
	return 0;
}
