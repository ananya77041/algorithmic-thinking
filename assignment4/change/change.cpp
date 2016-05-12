#include <iostream>
#include <vector>
using namespace std;

int coin_ct = 0;
vector<int> denoms = {10, 5, 1};

int use_coin(int n, int m) {
	while (m >= n) {
		m = m - n;
		coin_ct++;
	}
	return m;
}

int get_change(int n) {
	while (n > 0) {
		for (int i = 0; i < denoms.size(); ++i) {
			n = use_coin(denoms[i], n);
		}
	}
	return coin_ct;
}

int main() {
  int n;
  std::cin >> n;
  std::cout << get_change(n) << '\n';
}
