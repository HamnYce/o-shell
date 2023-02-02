#include <stdio.h>
#include <stdbool.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include "builtins.c"

#define BUF_S 1024
#define STDIN 0

void osh_loop() {
}

void osh_init() {
  osh_loop();
}

void osh_readline() {

}

int main(int argc, char* argv[]) {
  //osh_init();

  int size = read(STDIN, str, 10);
  str[size] = '\0';

  getchar();

  printf("input string: %s", str);
  return 0;
}
