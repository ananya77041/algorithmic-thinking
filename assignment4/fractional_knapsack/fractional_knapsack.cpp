#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  vector<tuple<double, int>> ratios;
  for (int i = 0; i < weights.size(); ++i) {
    ratios.push_back(make_tuple(((double)values[i] / (double)weights[i]), weights[i]));
  }
  sort (ratios.rbegin(), ratios.rend());

  for (int i = 0; i < ratios.size(); ++i) {
    while (get<1>(ratios[i]) > 0 && capacity > 0) {
      value = value + get<0>(ratios[i]);
      ratios[i] = make_tuple(get<0>(ratios[i]), get<1>(ratios[i]) - 1);
      capacity = capacity - 1;
    }
  }

  return value;
}

int main() {
  int n;
  int capacity;
  cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  cout.precision(10);
  cout << optimal_value << endl;
  return 0;
}

// calculate ratio of value to weight for each item
// greedy: choose item with highest value:weight ratio and add as much as possible
// continue until knapsack is full