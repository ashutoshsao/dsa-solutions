#include <stdio.h>
int main() {
  int a[] = {1, 2, 3, 4};
  int *p = a;
  printf("%d %d", p[3], p[0]);
}
