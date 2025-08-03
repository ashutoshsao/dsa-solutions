#include <stdio.h>
int main() {
  char a[3][10];
  for (int i = 0; i < 3; i++) {
    scanf("%9s", a[i]);
  }
  for (int i = 0; i < 3; i++) {
    printf("%s\n", a[i]);
  }
  printf("%c\n", *(*a + 1));
}
