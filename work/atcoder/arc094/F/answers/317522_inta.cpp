#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
char p[201000];
int Mod = 998244353, n, s;
long long D[201000][3][3], res = 1;
map<string, int>Map;
int main() {
	int i, ck = 0, j, k, ii;
	scanf("%s", p);
	for (i = 0; p[i]; i++) {
		s += (p[i] - 'a');
		if (i)res = 3 * res%Mod;
	}
	n = i;
	if (n <= 6) {
		Map[p] = 1;
		while (1) {
			int ckk = 0;
			for (auto &t : Map) {
				string tp = t.first;
				for (j = 0; j < tp.size() - 1; j++) {
					if (tp[j] != tp[j + 1]) {
						for (char tt = 'a'; tt <= 'c'; tt++) {
							if (tt != tp[j] && tt != tp[j + 1]) {
								string u = tp;
								u[j] = u[j + 1] = tt;
								if (!Map.count(u)) {
									Map[u] = 1;
									ckk = 1;
								}
								break;
							}
						}
					}
				}
			}
			if (!ckk)break;
		}
		printf("%d\n", Map.size());
		return 0;
	}
	s %= 3;
	int ckk = 0;
	for (i = 0; i < n - 1; i++) {
		if (p[i] == p[i + 1])ck = 1;
		if (p[i] != p[i + 1])ckk = 1;
	}
	if (!ckk) {
		printf("1\n");
		return 0;
	}
	D[1][0][0] = D[1][1][1] = D[1][2][2] = 1;
	for (i = 2; i <= n; i++) {
		for (j = 0; j < 3; j++)for (k = 0; k < 3; k++) {
			for (ii = 0; ii < 3; ii++) {
				if (ii == k)continue;
				D[i][(j + ii) % 3][ii] = (D[i][(j + ii) % 3][ii] + D[i - 1][j][k]) % Mod;
			}
		}
	}
	for (i = 0; i < 3; i++) {
		res = (res - D[n][s % 3][i] + Mod) % Mod;
	}
	res += 1 - ck;
	printf("%lld\n", res%Mod);
}