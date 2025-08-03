// program to transfrom a to b
#include <iostream>
#include <vector>
using namespace std;

// Recursive function to build the path from b to a
bool buildPath(long long current, long long target, vector<long long> &path) {
  if (current < target)
    return false;

  path.push_back(current);

  if (current == target)
    return true;

  if (current % 2 == 0) {
    if (buildPath(current / 2, target, path))
      return true;
  }
  if (current % 10 == 1) {
    if (buildPath((current - 1) / 10, target, path))
      return true;
  }
  path.pop_back();
  return false;
}

int main() {
  long long a, b;
  cin >> a >> b;

  vector<long long> path;

  if (buildPath(b, a, path)) {
    cout << "YES\n";
    cout << path.size() << "\n";
    for (int i = path.size() - 1; i >= 0; --i) {
      cout << path[i] << " ";
    }
    cout << "\n";
  } else {
    cout << "NO\n";
  }

  return 0;
}
