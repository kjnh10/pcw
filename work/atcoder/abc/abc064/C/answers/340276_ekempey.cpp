#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
	int n;
	std::cin >> n;

	std::vector<bool> a(8);
	int over = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int t;
		std::cin >> t;
		if (t >= 3200) {
			over++;
		} else {
			if (!a[t / 400]) {
				a[t / 400] = true;
				cnt++;
			}
		}
	}

	std::cout << std::max(1, cnt) << std::endl;
	std::cout << (cnt + over) << std::endl;
}
