// this program is to evaluate 2 words lexicographical order (like in
// dictionary)
#include <stdio.h>
#include <string.h>
int main() {
  char word1[100];
  char word2[100];
  scanf("%s %s", word1, word2);
  int i = 0;
  while (word1[i] != '\0' && word2[i] != '\0') {
    if (word1[i] < word2[i]) {
      printf("%s %s\n", word1, word2);
      break;
    } else {
      printf("%s %s", word2, word1);
      break;
    }
    i++;
  }
  // If we reach here, one is prefix of the other or both are equal
  if (word1[i] == '\0' && word2[i] != '\0') {
    printf("%s %s\n", word1, word2);
  } else {
    printf("%s %s\n", word2, word1);
  }
}
