
#if 1
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <array>
#include <deque>
#include <algorithm>
#include <utility>
#include <cstdint>
#include <functional>
#include <iomanip>
#include <numeric>
#include <assert.h>
#include <bitset>
#include <list>

auto& in = std::cin;
auto& out = std::cout;
#define all(C) std::begin(C), std::end(C)

int32_t N;
int32_t x,y,t=0;

int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	in.tie(nullptr);
	out.tie(nullptr);

	in >> N;
	while (N--)
	{
		int32_t x2, y2, t2;
		in >> t2 >> x2 >> y2 ;

		int32_t xd = x2 - x,yd=y2-y,td=t2-t;

		if (((std::abs(xd) + std::abs(yd)) & 1) != (td & 1)) {
			out << "No\n"; return 0;
		}
		if ((std::abs(xd) + std::abs(yd)) > td) {
			out << "No\n"; return 0;
		}

		x = x2; y = y2; t = t2;
	}
	out << "Yes\n";

	return 0;
}
#endif
