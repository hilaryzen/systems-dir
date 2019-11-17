#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
  DIR *d;
  char *path = "../structs/";
  char file_path[200];
  struct stat s;
  d = opendir(path);
  if (d == NULL) {
    printf("Opening directory didn't work\n");
  }
  printf("Statistics for directory: %s\n", path);

  int dir_size = 0;
  struct dirent *file;
  file = readdir(d);
  while (file != NULL) {
    if (file->d_type == 4) {
      printf("Directory: %s\n", file->d_name);
    } else {
      printf("File: %s\n", file->d_name);
    }
    sprintf(file_path, "%s%s", path, file->d_name);
    stat(file_path, &s);
    //printf("%d\n", s.st_size);
    dir_size += s.st_size;
    //printf("%s\n", file->d_name);
    //printf("%d\n", file->d_type);
    file = readdir(d);
  }
  closedir(d);

  printf("Total Directory Size: %d\n", dir_size);

  return 0;
}
