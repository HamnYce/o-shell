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

char *osh_readline(void) {
  int buff_size = BUF_S;
  int position = 0;
  char *line = malloc(sizeof(char) * buff_size);
  int c;

  while (true) {
    c = getchar();
    if (c == '\n' || c == EOF) break;

    line[position++] = c;

    if (position >= buff_size) {
      buff_size += BUF_S;
      line = realloc(line, sizeof(char) * buff_size);
    }
  }
  line[position] = '\0';

  return line;
}

void osh_launch(int argc, char* argv[]) {
  char *line = osh_readline();

  printf("%s\n", line);
}

void osh_split_line() {
}

int main(int argc, char* argv[]) {
  osh_launch(argc, argv);

  return 0;
}
