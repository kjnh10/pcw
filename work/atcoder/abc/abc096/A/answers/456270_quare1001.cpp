#include <iostream>
int a, b;
int main() {
	std::cin >> a >> b;
	if (a > b) {
		std::cout << a - 1 << '\n';
	}
	else {
		std::cout << a << '\n';
	}
	return 0;
}