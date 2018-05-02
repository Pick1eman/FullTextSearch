#include <stdio.h>
#include <dirent.h>
#include <string.h>



int main()
{
	int count = 0;
	DIR *dir;
	DIR *nes_dir;
	struct dirent *ent;

	char directory[255] = "./";
	char nested_dir[255];//Для вложенных директориях
	dir = opendir(directory);
	while ((ent = readdir(dir)) != NULL) {
		if ((strcmp(ent->d_name, ".")) && (strcmp(ent->d_name, ".."))){
			printf("%s\n", ent->d_name);
			for (int i = 0; i < strlen(ent->d_name); ++i){
				if (ent->d_name[i] == '.') {
					count++;
					//printf("ПРОВРЕКА 1 ---- %d\n", count);
				}
			}
			if ((count == 0) && (strcmp(ent->d_name, "main"))) {
				strcpy(nested_dir, ent->d_name);
				//printf("ПРОВРЕКА 2 ---- %s\n", nested_dir);				
			}
			count = 0;			
		}
	}
	closedir(dir);


	return 0;
}
