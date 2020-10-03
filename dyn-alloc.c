#include <stdio.h>
#include <stdlib.h>

typedef struct{
  char *name;
  int age;
} person;

int main(int argc, char const *argv[]) {

  person *myperson = (person *) malloc(sizeof(person));

  myperson->name = "josh";
  myperson->age = 21;

  printf("name: %s\n",myperson->name);
  printf("age: %d\n",myperson->age);

  free(myperson);
  //the data the pointer is pointing to is cleared
  




  return 0;
}
