#include <stdio.h>
#include <string.h>
int main() {
  char s1[100];
  char s2[100];
  scanf("%s", s1);
  scanf("%s", s2);
  int l1, l2, i, j;
  l1 = strlen(s1);
  l2 = strlen(s2);
  int match = 0;
  for (int i = 0; i <= l1 - l2; i++) {
    match = 1;
    for (int j = i; j <= i + l2 - 1; j++) {
      if (s1[j] != s2[j - i]) {
        match = 0;
        break;
      }
    }
    if (match == 1) {
      break;
    }
  }
  if (match == 1) {
    printf("Yes");
  } else {
    printf("No");
  }
}
