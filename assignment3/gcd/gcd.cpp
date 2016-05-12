#include <iostream>

int gcd(int a, int b) {
  //write your code here
  int rem;
  if (b > a) {
    rem = b % a;
    if (rem == 0)
      return a;
    return gcd(a, rem);
  }
  else {
    rem = a % b;
    if (rem == 0)
      return b;
    return gcd(b, rem);
  }
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd(a, b) << std::endl;
  return 0;
}
