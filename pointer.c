#include <stdio.h>


int main(int argc, char const *argv[]) {


  char *x = "123";
  printf("%p Addr has value %s\n",&x,*&x);


  int a = 177;

  int *ptoa = &a;

  printf("Addr %p has value %d\n",ptoa,*ptoa);
  // *pota <==> a
  // pota <==> &a

  //changing value using addr of var

  *ptoa += 1;
  printf("Addr %p has value %d\n",ptoa,*ptoa);
  printf("Addr %p has value %d\n",&a,a);



  return 0;
}
