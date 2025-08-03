#include <stdio.h>
int main() {
  int x = 9;
  int *y = &x;
  printf("%d value of x:\n", *&x);
}
