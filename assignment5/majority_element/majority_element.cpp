#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int get_majority_element(vector<int> &a) {
  unordered_map<int, int> counts;
  for (int i = 0; i < a.size(); ++i) {
    counts[a[i]] += 1;
  }
  for (auto it = counts.begin(); it != counts.end(); ++it) {
    // cout << it->first << ":" << it->second << "\n";
    if (it->second > (int)a.size() / 2) {
      return 1;
    }
  }
  return 0;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    cin >> a[i];
  }
  cout << get_majority_element(a) << '\n';
}
