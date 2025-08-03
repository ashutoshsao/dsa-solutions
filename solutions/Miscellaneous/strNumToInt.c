#include <stdio.h>
int main() {
  char s[100] = "92233720368547758070"; // max long long
  int len = 0, i = 0;
  long long x = 0;
  long long poweroften = 1;
  while (s[i] != '\0') {
    len++;
    i++;
  }
  len--;
  while (len >= 0) {
    x += (s[len] - '0') * poweroften;
    len--;
    poweroften *= 10;
  }
  x *= -1; // for -ve integers
  printf("%lld\n", x);
  return 0;
}
