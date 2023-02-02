#include <stdio.h>
#include <stdbool.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include "builtins.c"
#include <string.h>

#define BUF_S 1024
#define TOKENS_NUM 64;
#define TOKENS_DELIM " \t\r\n\a"
#define STDIN 0

void osh_loop() {
}

char *osh_readline(void) {
  int buff_size = BUF_S;
  int position = 0;
  char *line = malloc(sizeof(char) * buff_size);
  int c;

  if (line == NULL) {
    printf("Allocation error: cannot allocate space for line");
    exit(EXIT_FAILURE);
  }

  while (true) {
    c = getchar();
    if (c == '\n' || c == EOF) break;

    line[position++] = c;

    if (position >= buff_size) {
      buff_size += BUF_S;
      line = realloc(line, sizeof(char) * buff_size);

      if (line == NULL) {
        printf("Allocation error: cannot allocate space for line");
        exit(EXIT_FAILURE);
      }
    }
  }

  line[position] = '\0';

  return line;
}

char **osh_split_line(char *line) {
  int buff_size = TOKENS_NUM;
  char **tokens = malloc(sizeof(char*) * buff_size);
  char *token;
  int position = 0;
 
  if (tokens == NULL) {
    printf("Allocation error: cannot allocate space for tokens");
    exit(EXIT_FAILURE);
  }

  token = strtok(line, TOKENS_DELIM);
  while (true) {
    if (token == NULL) break;

    tokens[position] = token;
    position++;

    if (position >= buff_size) {
      buff_size += TOKENS_NUM;
      tokens = realloc(tokens, sizeof(char*) * buff_size);

      if (tokens == NULL) {
        printf("Allocation error: cannot allocate space for tokens");
        exit(EXIT_FAILURE);
      }
    }

    token = strtok(NULL, TOKENS_DELIM);
  }

  tokens[position] = NULL;

  return tokens;
}

void osh_launch(int argc, char* argv[]) {
  char *line = osh_readline();

  char **tokens = osh_split_line(line);

  printf("tokens:\n");
  while (*tokens != NULL) {
    printf("%s\n", *tokens);
    tokens++;
  }
}

int main(int argc, char* argv[]) {
  osh_launch(argc, argv);

  return 0;
}
