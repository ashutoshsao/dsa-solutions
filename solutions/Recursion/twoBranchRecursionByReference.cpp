#include <bits/stdc++.h>
using namespace std;
void func(int &x) {
  cout << x << " ";
  if (x >= 3) {
    return;
  }
  x++;
  func(x);
  x++;
  func(x);
}
int main() {
  int x = 0;
  func(x);
}
