#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int nrows = 2;
  int ncols = 5;
  int i, j;

  // Allocate memory for nrows pointers
  // Double pointer
  char **pvowels = (char **) malloc(nrows * sizeof(char *));

  // For each row, allocate memory for ncols elements
  pvowels[0] = (char *) malloc(ncols * sizeof(char));
  pvowels[1] = (char *) malloc(ncols * sizeof(char));

  pvowels[0][0] = 'A';
  pvowels[0][1] = 'E';
  pvowels[0][2] = 'I';
  pvowels[0][3] = 'O';
  pvowels[0][4] = 'U';

  pvowels[1][0] = 'a';
  pvowels[1][1] = 'e';
  pvowels[1][2] = 'i';
  pvowels[1][3] = 'o';
  pvowels[1][4] = 'u';

  for (i = 0; i < nrows; i++) {
      for(j = 0; j < ncols; j++) {
          printf("%c ", pvowels[i][j]);
      }

      printf("\n");
  }

  //Check for pointer addr
  printf("==== POINTER ADDRESS ====\n");
  printf("==>top pointer = %p\n",pvowels);
  printf("\t==>%p\n",pvowels[0]);
  printf("\t\t==>%p --> %c\n",&pvowels[0][0],pvowels[0][0]);
  printf("\t\t==>%p --> %c\n",&pvowels[0][1],pvowels[0][1]);
  printf("\t\t==>%p --> %c\n",&pvowels[0][2],pvowels[0][2]);
  printf("\t\t==>%p --> %c\n",&pvowels[0][3],pvowels[0][3]);
  printf("\t\t==>%p --> %c\n",&pvowels[0][4],pvowels[0][4]);
  printf("\t==>%p\n",pvowels[1]);
  printf("\t\t==>%p --> %c\n",&pvowels[1][0],pvowels[1][0]);
  printf("\t\t==>%p --> %c\n",&pvowels[1][1],pvowels[1][1]);
  printf("\t\t==>%p --> %c\n",&pvowels[1][2],pvowels[1][2]);
  printf("\t\t==>%p --> %c\n",&pvowels[1][3],pvowels[1][3]);
  printf("\t\t==>%p --> %c\n",&pvowels[1][4],pvowels[1][4]);

  // Free individual rows
  free(pvowels[0]);
  free(pvowels[1]);

  // Free the top-level pointer
  free(pvowels);

  return 0;
}
