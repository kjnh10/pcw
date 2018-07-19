# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <utility>
# include <stack>
# include <queue>
# include <list>
# include <ctime>
constexpr int MOD = 1000000007;
constexpr int INF = 2000000000;
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	if (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0) {
		cout << "Possible" << endl;
	}
	else {
		cout << "Impossible" << endl;
	}
}

	

