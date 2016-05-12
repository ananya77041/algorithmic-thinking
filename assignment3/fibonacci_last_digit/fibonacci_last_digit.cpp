#include <iostream>
#include <vector>

std::vector<int> fibLasts = {0, 1};

int get_fibonacci_last_digit(int n) {
    if (n > 1) {
    	for (int i = 2; i < n + 1; ++i) {
    		fibLasts.push_back((fibLasts[i-1] + fibLasts[i-2]) % 10);
    	}
    }
    return fibLasts[n];
}

int main() {
  int n;
  std::cin >> n;
  int c = get_fibonacci_last_digit(n);
  std::cout << c << '\n';
}
