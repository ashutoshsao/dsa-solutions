/*
Problem: Car Fleet
Link: https://leetcode.com/problems/car-fleet/
Problem Statement: Given n cars at different positions on a one-lane road heading to a target, and their respective speeds, determine the number of car fleets that will arrive at the destination. A car fleet is formed when a faster car catches up to a slower one.
Approach: The solution calculates the time for each car to reach the target. It then sorts the cars by their starting positions in descending order. By iterating through the sorted cars, it counts the number of fleets. A new fleet is formed whenever a car's arrival time is greater than the arrival time of the fleet ahead of it.
Time Complexity: O(n log n)
Space Complexity: O(n)
*/
#include <bits/stdc++.h>
using namespace std;

int carFleetCount(int n, int target, vector<int> &position,
                  vector<int> &speed) {
  vector<pair<int, double>> cars;
  for (int i = 0; i < n; i++) {
    double time = (double)(target - position[i]) / speed[i];
    cars.push_back({position[i], time});
  }

  sort(cars.rbegin(), cars.rend());
  int fleets = 0;
  double maxTime = 0;

  for (auto &car : cars) {
    double time = car.second;
    if (time > maxTime) {
      fleets++;
      maxTime = time;
    }
  }
  return fleets;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, target;
    cin >> n >> target;
    vector<int> position(n), speed(n);
    for (int i = 0; i < n; i++)
      cin >> position[i];
    for (int i = 0; i < n; i++)
      cin >> speed[i];

    cout << carFleetCount(n, target, position, speed) << "\n";
  }
  return 0;
}