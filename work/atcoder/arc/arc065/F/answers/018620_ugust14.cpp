#include <stdio.h>

const long long mod = 1000000007;

int N, M;
char S[3030];
int l[3030], r[3030];
long long comb[3030][3030];
long long p[3030],n[3030];

int main()
{
	scanf("%d %d %s", &N, &M, S);
	for (int i = 0; i < M; i++){
		scanf("%d %d", &l[i], &r[i]);
		l[i]--; r[i]--;
		if (i > 0 && l[i - 1] == l[i])
		{
			if (r[i - 1] < r[i])
				r[i - 1] = r[i];
			i--;
			M--;
		}
		else if (i > 0 && r[i] <= r[i-1])
		{
			i--;
			M--;
		}
	}

	for (int i = 0; i <= N; i++){
		comb[i][0] = comb[i][i] = 1;
		for (int j = 1; j < i; j++) comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
	}

	int have = 0;
	p[0] = 1;
	for (int i = 0; i < M; i++){
		int nxt = ((i == M - 1) ? 0 : (r[i] < l[i + 1] ? 0 : r[i] - l[i + 1] + 1));

		int L = (i == 0 || r[i - 1] < l[i]) ? l[i] : r[i - 1] + 1;
		int R = r[i];

		int cnt = 0;
		for (int j = L; j <= R; j++) if (S[j] == '1') cnt++;
		int all = r[i] - l[i] + 1;

		for (int k = 0; k <= nxt; k++) n[k] = 0;

		for (int j = 0; j <= have; j++){
			int v = cnt + j;
			for (int k = 0; k <= nxt; k++){
				int p1 = v - k;
				int p0 = (all - nxt) - p1;
				if (p1 < 0 || p0 < 0) continue;

				n[k] = (n[k] + p[j] * comb[all - nxt][p1]) % mod;
			}
		}

		for (int k = 0; k <= nxt; k++) p[k] = n[k];
		have = nxt;
	}

	printf("%lld\n", p[0]);

	return 0;
}