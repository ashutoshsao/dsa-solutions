// program to pass 2dArray as base address pointer
#include <stdio.h>

void scan2D(int rows, int cols, int p[][4]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      scanf("%d", &p[i][j]);
    }
  }
}

int main() {
  int arr[2][4];     // 2 rows, 4 columns
  scan2D(2, 4, arr); // Only scanning inside function

  // Printing in main
  for (int i = 0; i < 2 * 4; i++) {
    printf("%d ", *((int *)arr + i));
  }
  printf("\n");
  return 0;
}
