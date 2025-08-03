#include <stdio.h>
#include <string.h>

int main() {
  char word[20];
  scanf("%s", word);

  int len = strlen(word);

  // Bubble sort
  for (int i = 0; i < len - 1; i++) {
    for (int j = 0; j < len - 1 - i; j++) {
      if (word[j] > word[j + 1]) {
        char temp = word[j];
        word[j] = word[j + 1];
        word[j + 1] = temp;
      }
    }
  }

  printf("%s\n", word);
  return 0;
}
