#include <stdio.h>

unsigned int multiply(unsigned int x, unsigned int y)
{
    if (x == 1)
    {
        /* Terminating case */
        return y;
    }
    else if (x > 1)
    {
        /* Recursive step */
        return y + multiply(x-1, y);
    }

    /* Catch scenario when x is zero */
    return 0;
}

int main(int argc, char const *argv[]) {
    printf("3 * 5 = %d\n", multiply(3, 5));
    return 0;
  return 0;
}
