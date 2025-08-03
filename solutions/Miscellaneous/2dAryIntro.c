// program to input and output 3d array with sum
#include <stdio.h>
int main() {
  int i, j, sum = 0;
  scanf("%d %d", &i, &j);
  int arr[i][j];
  for (int a = 0; a < i; a++) {
    for (int b = 0; b < j; b++) {
      scanf("%d", &arr[a][b]);
    }
  }
  for (int a = 0; a < i; a++) {
    for (int b = 0; b < j; b++) {
      sum += arr[a][b];
      printf("%d ", arr[a][b]);
    }
    printf("\n");
  }
  printf("%d\n", sum);
  return 0;
}
