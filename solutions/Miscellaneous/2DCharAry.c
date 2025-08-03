#include <stdio.h>
int main() {
  char word[5][100];
  int i;
  for (i = 0; i < 5; i++) {
    scanf("%s", word[i]);
  }
  for (i = 0; i < 5; i++) {
    printf("%s\n", word[i]);
  }
  return 0;
}
