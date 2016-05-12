#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long min_dot_product(vector<int> a, vector<int> b) {
  sort (a.begin(), a.end());
  sort (b.rbegin(), b.rend());

  long long result = 0;
  for (size_t i = 0; i < a.size(); i++) {
    result += (long long)a[i] * (long long)b[i];
  }
  return result;
}

int main() {
  size_t n;
  cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    cin >> b[i];
  }
  cout << min_dot_product(a, b) << endl;
}
