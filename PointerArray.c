#include <stdio.h>

int main(int argc, char const *argv[]) {

  // Array declaration
  char vowels[] = {'A', 'E', 'I', 'O', 'U'};
  // Give Array Addr to a pointer
  char *pvowels = vowels;
  int i;

  // Print the addresses
  for (i = 0; i < 5; i++) {
      printf("&vowels[%d]: %p, pvowels + %d: %p, vowels + %d: %p\n", i, &vowels[i], i, pvowels + i, i, vowels + i);
  }

  // Print the values
  for (i = 0; i < 5; i++) {
      printf("vowels[%d]: %c, *(pvowels + %d): %c, *(vowels + %d): %c\n", i, vowels[i], i, *(pvowels + i), i, *(vowels + i));
  }

  printf("--> pointer addr => %p\n",pvowels);

  return 0;
}
