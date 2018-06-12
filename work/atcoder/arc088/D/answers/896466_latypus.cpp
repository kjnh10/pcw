
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

string S;

int main(void)
{
	cin >> S;
	int N = S.size();
	for (int i = N / 2; i < N; ++i) {
		if (i == N / 2 && N % 2 == 1)continue;
		if (S[i] == S[N - 1 - i] && S[i] == S[i - 1]) {}
		else {
			cout << i;
			return 0;
		}
	}
	cout << N << endl;
	return 0;
}
