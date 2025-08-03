#include <stdio.h>
struct person {
  char name[50];
  int age;
};
int main() {
  struct person persons[3] = {{"ashutosh", 20}, {"ash", 22}, {"bash", 24}};
  printf("%s %d", persons[0].name, persons[0].age);
}
