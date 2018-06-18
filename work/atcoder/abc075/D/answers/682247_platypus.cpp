
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <array>
#include <cassert>
#include <bitset>
using namespace std;
using LL = long long;

int N, K;
vector<pair<int, int>>vec;

int main(void)
{
	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		int x, y;
		cin >> x >> y;
		vec.push_back({ x,y });
	}
	LL answer = LLONG_MAX;
	for (int A = 0; A < N; ++A)
	{
		for (int B = 0; B < N; ++B)
		{
			if (vec[A].second >= vec[B].second)continue;
			vector<pair<int, int>>inner;
			for (int c = 0; c < N; ++c)
			{
				if (vec[A].second <= vec[c].second && vec[c].second <= vec[B].second)
				{
					inner.push_back(vec[c]);
				}
			}
			sort(inner.begin(), inner.end());
			LL height = (LL)vec[B].second - vec[A].second;
			for (int i = 0; i <= (int)inner.size() - K; ++i)
			{
				LL width = inner[i + K - 1].first - inner[i].first;
				LL area = height * width;
				answer = min(answer, area);
			}
		}
	}
	cout << answer << endl;
	return 0;
}
