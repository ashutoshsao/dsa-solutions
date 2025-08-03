// program to play with srings in c++
#include <bits/stdc++.h>
using namespace std;
int main() {
  string s = "abc";
  reverse(s.begin(), s.begin() + 2); // s = "bac"
  cout << s << "\n";                 // prints "bac"
  cout << s[0] << "\n";              // prints 'b'

  cout << (s.at(2) = 'd') << "\n"; // assign 'd' to s[2], then print 'd'

  s += 'd';          // s = "bacd"
  s += "e";          // s = "bacde"
  cout << s << "\n"; // print "bacde"

  return 0;
}
