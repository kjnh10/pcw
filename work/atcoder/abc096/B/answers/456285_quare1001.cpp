#include <iostream>
#include <algorithm>
int A, B, C, K;
int main() {
	std::cin >> A >> B >> C >> K;
	std::cout << A + B + C + std::max({ A, B, C }) * ((1 << K) - 1) << '\n';
	return 0;
}