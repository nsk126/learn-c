#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int n = 5;

  char *pvowels = (char *) malloc(n* sizeof(char));
  int i;


  // all of these do the same op
  pvowels[0] = 'A';
  pvowels[1] = 'E';
  *(pvowels + 2) = 'I';
  pvowels[3] = 'O';
  *(pvowels + 4) = 'U';

  for (i = 0; i < n; i++) {
      printf("%c ", pvowels[i]);
  }

  printf("\n");

  free(pvowels);

  return 0;
}
