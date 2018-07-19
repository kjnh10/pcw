#include<cstdio>
#include<algorithm>
#include<bitset>
#define BS 4096
using namespace std;
bitset<4096>w[6], X, G, TP;
int n, GL, Mod = 998244353, po[4096];
char p[4096];
void Put(bitset<4096> &TP, char *key) {
	int i, L;
	for (i = 0; key[i]; i++);
	L = i;
	for (i = 0; i < L; i++) {
		TP[L - i - 1] = key[i]-'0';
	}
}
int Len(bitset<4096> &TP) {
	int j;
	for (j = BS - 1; j >= 0; j--) {
		if (G[j])break;
	}
	return j+1;
}
int main() {
	int i, j;
	po[0] = 1;
	for (i = 1; i <= 4000; i++)po[i] = po[i - 1] * 2 % Mod;
	scanf("%d", &n);
	scanf("%s", p);
	Put(X, p);
	for (i = 0; i < n; i++) {
		scanf("%s", p);
		Put(w[i], p);
	}
	G = w[0];
	while (1) {
		int ck = 0;
		for (i = 0; i < n; i++) {
			TP = w[i];
			GL = Len(G);
			for (j = BS - 1; j >= GL - 1; j--) {
				if (TP[j]) {
					TP ^= G << (j + 1 - GL);
				}
			}
			for (j = BS - 1; j >= 0; j--)if (TP[j])break;
			if (j != -1) {
				ck = 1;
				G = TP;
			}
		}
		if (!ck)break;
	}
	GL = Len(G);
	long long res = 0;
	TP.reset();
	for (i = BS - 1; i >= GL - 1; i--) {
		if (X[i]) {
			res = (res + po[i - (GL - 1)]) % Mod;
		}
		if (TP[i] != X[i]) {
			TP ^= G << (i + 1 - GL);
		}
	}
	int ck = 0;
	for (i = BS - 1; i >= 0; i--) {
		if (X[i] != TP[i]) {
			if (TP[i]) ck = 1;
			break;
		}
	}
	res = (res + 1 - ck) % Mod;
	printf("%d\n", res);
}