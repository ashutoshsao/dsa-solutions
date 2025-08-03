#include <stdio.h>
int main() {
  int *p[3];
  int x[3] = {1, 2, 3};
  int y[3] = {4, 6, 7};
  int z[3] = {8, 9, 10};
  p[0] = x;
  p[1] = y;
  p[2] = z;
  printf("%d %d\n", *(*(p + 0) + 2), *(x + 2));
}
