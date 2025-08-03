// program for software to manage colliders
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1'000'005;

vector<int> spf(MAXN); // Smallest prime factor
vector<int> usedPrimes(MAXN,
                       0); // usedPrimes[p] = collider number using prime p
vector<bool> isActive(MAXN, false); // isActive[num] = is collider num active?

void computeSPF() {
  for (int i = 2; i < MAXN; ++i)
    spf[i] = i;
  for (int i = 2; i * i < MAXN; ++i) {
    if (spf[i] == i) {
      for (int j = i * i; j < MAXN; j += i) {
        if (spf[j] == j)
          spf[j] = i;
      }
    }
  }
}

vector<int> getUniquePrimeFactors(int x) {
  vector<int> factors;
  while (x > 1) {
    int p = spf[x];
    factors.push_back(p);
    while (x % p == 0)
      x /= p;
  }
  return factors;
}

void activate(int num) {
  if (isActive[num]) {
    cout << "Already on\n";
    return;
  }

  vector<int> primes = getUniquePrimeFactors(num);
  for (int p : primes) {
    if (usedPrimes[p] != 0) {
      cout << "Conflict with " << usedPrimes[p] << "\n";
      return;
    }
  }

  // No conflicts
  for (int p : primes) {
    usedPrimes[p] = num;
  }
  isActive[num] = true;
  cout << "Success\n";
}

void deactivate(int num) {
  if (!isActive[num]) {
    cout << "Already off\n";
    return;
  }

  vector<int> primes = getUniquePrimeFactors(num);
  for (int p : primes) {
    if (usedPrimes[p] == num)
      usedPrimes[p] = 0;
  }
  isActive[num] = false;
  cout << "Success\n";
}

int main() {
  computeSPF();

  int n, m;
  cin >> n >> m;

  while (m--) {
    char op;
    int x;
    cin >> op >> x;

    if (op == '+')
      activate(x);
    else
      deactivate(x);
  }

  return 0;
}
