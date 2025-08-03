#include <stdio.h>
#include <string.h>
struct limbs {
  int hands;
  int legs;
};
struct person {
  char name[20];
  int age;
  struct limbs body;
};
int main() {
  struct person p1;
  strcpy(p1.name, "ashutosh");
  p1.age = 23;
  p1.body.hands = 2;
  p1.body.legs = 2;
  printf("%s %d %d %d\n", p1.name, p1.age, p1.body.hands, p1.body.legs);
  printf("%ld\n", sizeof(struct person));
}
