#include <iostream>
#include <string>

int main(){
	std::string nums;
	std::getline(std::cin, nums);
	int a = nums.at(0) - '0';
	int b = nums.at(nums.length()-1) - '0';
	int sum = a + b;
	std::cout << sum << std::endl;
	return 0;
}