#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "dir_tree.h"

char *sample;

int main(int argc, char *argv[])
{
	FILE *log = fopen("./logs/user.log", "w");
	fclose(log);

	if (argc == 6) {
		if (!strcmp(argv[1], "-r") && (!strcmp(argv[2], "-h")) && (!strcmp(argv[3], "-s"))) {
			DIR *check_dir = opendir(argv[5]);
			if (check_dir != NULL) {
				closedir(check_dir);
				sample = argv[4];
				direction_recurs(argv[5]);
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
				//Скрытые папки/файлы
				direction_recurs(argv[4]);
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
				//Симлинк
				direction(argv[4]);
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
				//Симлинк
				direction(argv[4]);
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
				direction_recurs(argv[3]);
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
				//Скрытые папки/файлы
				direction(argv[3]);
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
				//Симлинк
				direction(argv[3]);
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
			direction_recurs(argv[2]);
			printf("Search done\n");
		} else {
            printf("Directory doesn't exist or cannot be opened\nSearch failed\n");
            return -1;
        }
	} else {
		printf("Error\n");
		return -1;
	}
	
	return 0;
}
