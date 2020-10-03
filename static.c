#include<stdio.h>


// Without Static
int r() {
    int c = 0;
    c++;
    return c;
}

// With static
int x() {
    static int a = 0;
    a++;
    return a;
}

/*
  Static keyword
    => static declaration gives global scope -> Use it anywhere in the file
    => functions are global by default
    => using static on functions decreases scope to file containing it

  static v global
    => global var can also be accessed outside file
    => static var only have scope over the file containing it -> global only inside that file
*/

int main()
{
  printf("without static\n");
  printf("%d ", r());
  printf("%d \n", r());

  printf("with static\n");
  printf("%d ", x());
  printf("%d \n", x());

    return 0;
}
