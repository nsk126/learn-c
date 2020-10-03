#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {

  char *str1 = "String1";
  printf("%ld\n",strlen(str1) );

  char *f1 = "hel";
  char *f2 = "hal";

  if(f1 == f2){
    printf("Works\n");
  }

  if(!strncmp(f1,"hal",1)){ // 0  if true, works when arg3 is 1 and not when 2+
    printf("Strncmp in action !\n" );
  }

  char tocar[30] = "cating this";
  char *toappend = " and it doesnt work again and again !";

  strncat(tocar,toappend,20);

  // interesting note on strncat
  //   => dest arg needs to have declared array/char size
  //   => src arg need not i.e can be delcared as char array with pointer
  

  printf("%s\n",tocar);
  return 0;
}
