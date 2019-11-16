#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>

int main() {
  DIR *d;
  char *path = "../structs/";
  d = opendir(path);
  if (d == NULL) {
    printf("Opening directory didn't work\n");
  }

  char *directories;
  char *files;
  struct dirent *file;
  file = readdir(d);
  while (file != NULL) {
    printf("%s\n", file->d_name);
    printf("%d\n", file->d_type);
    file = readdir(d);
  }

  printf("Statistics for directory: %s\n", path);
  printf("Total Directory Size: \n");

  return 0;
}
