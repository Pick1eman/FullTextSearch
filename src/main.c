#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "int_vector.h"
#include "dir_tree.h"
#include "search.h"

char *sample;

int main(int argc, char *argv[])
{
	//char directory[256] = "./res";
	//direction_recurs(directory);
	FILE *log = fopen("./logs/user.log", "w");
	fclose(log);

	if (argc == 4) {
		if (!strcmp(argv[1], "-r")) {
			DIR *check_dir = opendir(argv[3]);
			if (check_dir != NULL) {
				closedir(check_dir);
				sample = argv[2];
				direction_recurs(argv[3]);
				printf("Search done\n");
			} else {
				printf("Invalid argument 3! Directory doesn't exist or cannot be opened\nSearch failed\n");
				return -1;
			}
		} else {
			printf("Invalid argument 1! Expected -r key but argument 1 is unknown\nSearch failed\n");
			return -1;
		}
	} else if (argc == 3) {
		DIR *check_dir = opendir(argv[2]);
		if (check_dir != NULL) {
			closedir(check_dir);
			sample = argv[1];
			direction(argv[2]);
			printf("Search done\n");
        } else {
            printf("Invalid argument 2! Directory doesn't exist or cannot be opened\nSearch failed\n");
            return -1;
        }
    } else {
        printf("Invalid number of arguments!\nSearch failed\n");
        return -1;
	}
	
	return 0;
}
