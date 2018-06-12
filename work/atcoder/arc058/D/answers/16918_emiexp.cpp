#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
using namespace std;
#define MOD @
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

typedef bitset<1000002> bs;

int N, K;
string S[2020];
string Sc;
int idx[2020];

char in[1010101];

bool dp[2020][10101];
bs state;

bs finder[64];

char smallest()
{
	int pos = 1;
	while (pos < 32) {
		if ((state & finder[pos * 2]).none()) pos = pos * 2 + 1;
		else pos *= 2;
	}
	return (pos - 32) + 'a';
}

int main()
{
	/*
	bitset<1000005> bs;
	bs.set(1, true);
	int a = 0;
	for (int i = 0; i < 100000; ++i) {
		bs = bs & bs;
		a += bs.none() ? 1 : 0;
	}
	printf("%d\n", a);

	return 0;
	*/

	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; ++i) {
		scanf("%s", in);
		S[i] = in;
	}

	dp[N][0] = true;
	for (int i = N - 1; i >= 0; --i) {
		for (int j = 0; j <= K; ++j) if (dp[i + 1][j]) {
			dp[i][j] = true;
			if (j + S[i].size() <= K) dp[i][j + S[i].size()] = true;
		}
	}
	for (int i = 0; i < N; ++i) {
		idx[i] = Sc.size();
		for (char c : S[i]) Sc.push_back(c);
	}
	idx[N] = Sc.size();

	for (int i = 0; i < 64; ++i) finder[i].reset();
	for (int i = 0; i < Sc.size(); ++i) {
		finder[Sc[i] - 'a' + 32].set(i);
	}
	for (int i = 31; i >= 1; --i) finder[i] = finder[i * 2] | finder[i * 2 + 1];

	state.reset();
	state.set(0, true);

	string ret;

	for (int i = 0; i < K; ++i) {
		for (int j = 0; j < N; ++j) {
			if (state[idx[j]]) state.set(idx[j + 1]);
		}
		for (int j = 0; j < N; ++j) {
			if (K - i - (int)S[j].size() < 0 || !dp[j + 1][K - i - S[j].size()]) state.reset(idx[j]);
		}

		char nxt = smallest();
		ret.push_back(nxt);
	//	printf("%d %c %d\n", i, nxt, (int)nxt);
		state &= finder[(nxt - 'a') + 32];
		state <<= 1;
	}

	puts(ret.c_str());

	return 0;
}
