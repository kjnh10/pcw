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
using namespace std;
#define MOD @
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int N, M;
i64 A[5050];
i64 B[5050][202];

i64 imos[5050][5050];
bool vis[5050];
int mate[5050];

void join(int p, int q)
{
	if (mate[p] == p) {
		if (mate[q] == q) {
			mate[p] = q;
			mate[q] = p;
		} else {
			mate[p] = mate[q];
			mate[mate[q]] = p;
		}
	} else {
		if (mate[q] == q) {
			mate[q] = mate[p];
			mate[mate[p]] = q;
		} else {
			mate[mate[p]] = mate[q];
			mate[mate[q]] = mate[p];
		}
	}
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N - 1; ++i) scanf("%lld", A + i);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) scanf("%lld", &(B[i][j]));
	}
	for (int i = 0; i < M; ++i) {
		vector<pair<i64, int> > cand;
		for (int j = 0; j < N; ++j) cand.push_back({ B[j][i], j });
		sort(cand.begin(), cand.end());

		for (int j = 0; j <= N + 1; ++j) {
			vis[j] = false;
			mate[j] = j;
		}
		for (auto p : cand) {
			int idx = p.second + 1;
			int lf = idx, rg = idx;
			vis[idx] = true;
			if (vis[idx - 1]) {
				lf = mate[idx - 1];
				join(idx - 1, idx);
			} 
			if (vis[idx + 1]) {
				rg = mate[idx + 1];
				join(idx, idx + 1);
			}
		//	printf("%d--%d, %d--%d %lld\n", lf, idx, idx, rg, p.first);
			imos[lf][idx] += p.first;
			imos[lf][rg + 1] -= p.first;
			imos[idx + 1][idx] -= p.first;
			imos[idx + 1][rg + 1] += p.first;
		}
	}
	for (int i = 0; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			imos[i][j] += imos[i][j - 1];
		}
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j <= N; ++j) {
			imos[i][j] += imos[i - 1][j];
		}
	}
	i64 best = 0;
	for (int i = 0; i < N; ++i) {
		i64 cs = 0;
		for (int j = i; j < N; ++j) {
		//	printf("%d--%d %lld\n", i, j, imos[i + 1][j + 1]);
			best = max(best, imos[i + 1][j + 1] - cs);
			cs += A[j];
		}
	}
	printf("%lld\n", best);

	return 0;
}
