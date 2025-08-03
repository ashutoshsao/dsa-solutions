#include <stdio.h>
struct Point {
  int x, y;
};
int main() {
  struct Point p;
  scanf("%d %d", &(p.x), &(p.y));
  printf("%d %d", p.x * 2, p.y * 3);
  return 0;
}
