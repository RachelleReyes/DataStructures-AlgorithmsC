#include <stdio.h>
#include <stdlib.h>
int main(void) {
  int i = 0;
  char c, *input;
  input = (char *) malloc(sizeof(char));

  if(input == NULL) {
    printf("Could not allocate memory!");
    exit(1);
  }

  printf("Input a string, press enter when done: ");

  while((c = getchar()) != '\n') {
    input =  (char*)realloc(input, (sizeof(char)));
    input[i++] = c;
  }

  input[i] = '\0';
  printf("\nYou entered the string: %s\n", input);
  free(input);
}
