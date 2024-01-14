#include "countwords.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/* Get the next word in a stream and write it to the buffer. */
int getWord(FILE *input, char *buffer) {

  int length = 0;
  int c;

  while ((c = getc(input)) != EOF) {

    if (length + 1 > MAX_WORD_LEN) {
      fprintf(stderr, "Maximum word length exceeded!\n%s\n", buffer);
      exit(EXIT_FAILURE);
    }

    if (ispunct(c) || c == ' ') {
      buffer[length] = '\0';
      return 1;
    }

	if (isalpha(c))
		buffer[length++] = c;
  }

  buffer[length] = '\0';
  return EOF;
}
