#include <stdio.h>
struct company {
  int age;
  int employees;
};
int main() {
  struct company tesla = {20, 1000};
  struct company *ptr = &tesla;
  printf("%d %d", ptr->age, ptr->employees);
  printf("\n");
}
