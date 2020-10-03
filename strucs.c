// This helps to reduce function input arguments
// func(x,y) becomes func(p)
// since p contains x,y

  // Use of typedef
typedef struct{
  int x;
  int y;
} point1;


typedef struct{
  char *b;
  int m;
} vech;

int main(int argc, char const *argv[]) {


  point1 pa; // <==> struct point p
  vech car;

  car.b = "honda";
  car.m = 420;

  pa.x = 1;
  pa.y = 2;

  return 0;
}
