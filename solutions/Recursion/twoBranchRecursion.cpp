#include <bits/stdc++.h>
using namespace std;
void func(int x) {
  cout << x << " ";
  if (x >= 3) {
    return;
  }
  func(x + 1);
  func(x + 2);
}
int main() { func(0); }
