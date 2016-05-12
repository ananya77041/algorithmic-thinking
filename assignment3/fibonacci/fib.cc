#include <iostream>
#include <vector>

std::vector<int> fibs = {0, 1};

int calc_fib(int n) {
    if (n > 1) {
    	for (int i = 2; i < n + 1; ++i) {
    		fibs.push_back(fibs[i-1] + fibs[i-2]);
    	}
    }
    return fibs[n];
}

int main() {
    int n = 0;
    std::cin >> n;

    std::cout << calc_fib(n) << '\n';
    return 0;
}