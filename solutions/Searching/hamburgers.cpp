/*
Problem: Hamburgers
Link: https://codeforces.com/problemset/problem/371/C
Problem Statement: The user wants to find the maximum number of hamburgers they can make given a recipe, the number of ingredients they have, the price of each ingredient, and the total money they have.
Approach: The solution uses binary search on the number of hamburgers that can be made. The `canMake` function checks if it's possible to make a certain number of hamburgers. It calculates the cost of buying the extra ingredients required and returns true if the cost is within the available money. The main function reads the input, and then uses a binary search to find the maximum number of hamburgers that can be made. The search space for the binary search is from 0 to a large enough number (money + max_have + max_price).
Time Complexity: O(log(N)), where N is the search space for the number of hamburgers. The `canMake` function is O(1).
Space Complexity: O(1), as the space used is constant regardless of the input size.
*/
#include <bits/stdc++.h>
#include <climits>
using namespace std;
using ll = long long;

bool canMake(long long burgers, const vector<ll> &have, const vector<ll> &price,
             const vector<ll> &need, ll money) {
  long long cost = 0;
  for (int i = 0; i < 3; i++) {
    long long required = need[i] * burgers;
    long long extra = max(0LL, required - have[i]);
    cost += extra * price[i];
    if (cost > money)
      return false;
  }
  return cost <= money;
}

int main() {

  string recipe;
  cin >> recipe;

  vector<ll> have(3), price(3), need(3, 0);
  ll maxhave = INT_MIN, maxPrice = INT_MIN;

  for (int i = 0; i < have.size(); i++) {
    cin >> have[i];
    maxhave = max(have[i], maxhave);
  }

  for (int i = 0; i < price.size(); i++) {
    cin >> price[i];
    maxPrice = max(price[i], maxPrice);
  }

  ll money;
  cin >> money;

  // count ingredients needed for one hamburger
  for (char c : recipe) {
    if (c == 'B')
      need[0]++;
    else if (c == 'S')
      need[1]++;
    else if (c == 'C')
      need[2]++;
  }

  ll lo = 0, hi = money + maxhave + maxPrice, ans = 0;
  while (lo <= hi) {
    ll mid = lo + (hi - lo) / 2;
    if (canMake(mid, have, price, need, money)) {
      ans = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }

  cout << ans << "\n";
  return 0;
}
