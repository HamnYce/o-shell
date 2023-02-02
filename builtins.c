#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>

void ls(char *path) {
  struct dirent *de;
  DIR *dr = opendir(path);

  if (dr == NULL) {
    printf("No such file or directory (os error 2)");
  }

  while ((de = readdir(dr)) != NULL) printf("%s ", de->d_name);

  closedir(dr);
}
