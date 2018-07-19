


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

int32_t N,K;
int32_t memo[2001][2001];//黒の始点,x,y

void imos(int32_t x, int32_t y, int32_t x2, int32_t y2)
{
	++memo[x][y];
	--memo[x][y2];
	--memo[x2][y];
	++memo[x2][y2];
}

int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	in.tie(nullptr);
	out.tie(nullptr);

	in >> N>>K;
	for (size_t i = 0; i < N; i++)
	{
		int32_t x, y; char c;
		in >> x >> y>>c;
		x %= 2*K; y %= 2*K;

		if (((x < K && y < K) || (x >= K && y >= K)) == (c == 'B'))
		{
			auto x_ = x % K, y_ = y % K;
			//++memo[0][0]; --memo[x_ + 1][y_ + 1];
			imos(0, 0, x_ + 1, y_ + 1);
			imos(x_ + K + 1, 0, 2 * K, y_ + 1);

			imos(0, y_ + K + 1, x_ + 1, 2 * K);
			imos(x_ + K + 1, y_ + K + 1, 2 * K, 2 * K);

			imos(x_ + 1, y_ + 1, x_ + K + 1, y_ + K + 1);
		}
		else
		{
			auto x_ = x % K, y_ = y % K;
			//++memo[x_ + 1][y_ + 1]; --memo[x_ + K + 1][y_ + K + 1];

			imos(x_ + 1, 0, x_ + K + 1, y_ + 1);
			imos(x_ + 1, y_ + K + 1, x_ + K + 1, 2 * K);

			imos(0, y_ + 1, x_ + 1, y_ + K + 1);
			imos(x_ + K + 1, y_ + 1, 2 * K, y_ + K + 1);
		}
	}

	for (size_t i = 0; i < 2001; i++)
		for (size_t j = 1; j < 2001; j++)
	{
			memo[i][j] += memo[i][j - 1];
	}
	for (size_t i = 1; i < 2001; i++)
		for (size_t j = 0; j < 2001; j++)
	{
		memo[i][j] += memo[i - 1][j];
	}

	int32_t max = 0;
	for (size_t i = 0; i < 2 * K; i++)
		for (size_t j = 0; j < 2*K; j++)
		{
			max = std::max(max, memo[i][j]);
		}
	out << max << endl;

	return 0;
}
#endif
