#include <stdio.h>
int *getfirstfiveint(int p[]) {
  int x = 2, i;
  for (i = 0; i < 5; i++) {
    *(p + i) = x;
    x += 2;
  }
  return p;
}
int main() {
  int arr[5];
  int *p = getfirstfiveint(arr);
  for (int i = 0; i < 5; i++) {
    printf("%d ", *(arr + i));
  }
  printf("\n");
}
