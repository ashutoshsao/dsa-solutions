#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
  vector<int> v = {1, 2, 3};
  vector<int>::reverse_iterator it; // Declare reverse iterator

  cout << "Distance between rbegin and rend: " << *v.rbegin() << *(--v.rend())
       << endl;
  for (it = v.rbegin(); it != v.rend(); ++it) {
    cout << *it << " ";
  }

  v.clear();

  return 0;
}
