#include <stdio.h>

// for variables
void addone(int n) {
    n++;
}

void addone1(int *n) {
    (*n)++;
}

// for structs

typedef struct{
  int x;
  int y;
}point;


void move(point *p){
  (*p).x++;
  (*p).y++;
}
// a better implementation using a new operator
void move1(point * p) {
    p->x++;
    p->y++;
}


point p;

int main(int argc, char const *argv[]) {

  // pass by value
  int n = 0;
  printf("Before: %d\n",n);
  addone(n);
  printf("After: %d\n",n);

  // pass by ref
  int np = 0;
  printf("Before: %d\n",np);
  addone1(&np);
  printf("After: %d\n",np);

  printf("--===Strucs===--\n");
  p.x = 0;
  p.y = 0;

  move(&p);
  printf("x = %d, y = %d\n",p.x,p.y);
  move(&p);
  printf("x = %d, y = %d\n",p.x,p.y);
  move1(&p);
  printf("x = %d, y = %d\n",p.x,p.y);
  move1(&p);
  printf("x = %d, y = %d\n",p.x,p.y);

  return 0;
}
