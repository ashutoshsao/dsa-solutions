#include <stdio.h>
void twodarr(int n, int m, int p[][n]) {
  int x = 2, i, j;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      *(*(p + i) + j) = x;
      x += 2;
    }
  }
}
int main() {
  int arr[3][4];
  twodarr(3, 4, arr);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}
