#include "bits/stdc++.h"
using namespace std;
#define fi first
#define se second
#define ll long long
#define dbg(v) cerr<<#v<<" = "<<v<<'\n'
#define vi vector<int>
#define vl vector <ll>
#define pii pair<int,int>
#define mp make_pair
#define db long double
#define pb push_back
#define all(s) s.begin(),s.end()
#include <x86intrin.h>
template < class T > T smin(T &a,T b) {if (a > b) a = b;return a;}
template < class T > T smax(T &a,T b) {if (a < b) a = b;return a;}
const int N = (1e6) + 5;
char str[N];
int sum[N];
const int offset = 250005;
int mod1,mod2;
int prime(int k) {
	for (int i = 2;1ll * i * i <= k;++i)
		if (!(k % i))
			return 0;
	return 1;
}
int P1[N];
int P2[N];
int pow(int a,int b,int mod) {
	int ans = 1;
	while (b) {
		if (b & 1)
			ans = (1ll * ans * a) % mod;
		b /= 2;
		a = (1ll * a * a) % mod;
	}
	return ans;
}
const int base1 = 1e6 + 3;
const int base2 = 666013;
int pw1[N];
int pw2[N];
map < pii , int > M;
int main(void) {
	int n;
	srand(__rdtsc());
	cin>>n;
	cin>>(str + 1);
	sum[0] = offset;
	for (int i = 1;i <= n;++i) {
		sum[i] = sum[i - 1] + (str[i] == '<' ? -1 : str[i] == '>' ? 1 : 0);
	}
	do {	
		mod1 = ((1ll * rand() << 16) ^ rand()) & ((1ll << 30) - 1);
		if (mod1 < (1 << 29))
			mod1 += (1 << 29);
	} while (!prime(mod1));
    do {	
		mod2 = ((1ll * rand() << 16) ^ rand()) & ((1ll << 30) - 1);
		if (mod2 < (1 << 29))
			mod2 += (1 << 29);
	} while (!prime(mod2));
	const int iv1 = pow(base1,mod1 - 2,mod1);
	const int iv2 = pow(base2,mod2 - 2,mod2);
	pw1[offset] = pw2[offset] = 1;
	for (int i = offset - 1;i >= 0;--i) {
		pw1[i] = (1ll * pw1[i + 1] * iv1) % mod1;
		pw2[i] = (1ll * pw2[i + 1] * iv2) % mod2;
	}
	for (int i = offset + 1;i <= 2 * offset;++i) {
		pw1[i] = (1ll * pw1[i - 1] * base1) % mod1;
		pw2[i] = (1ll * pw2[i - 1] * base2) % mod2;
	}
	P1[0] = 0;
	P2[0] = 0;
	for (int i = 1;i <= n;++i) {
		if (sum[i] != sum[i - 1])
			P1[i] = P1[i - 1],
			P2[i] = P2[i - 1];
		else {
			int cnt1 = pw1[sum[i]];
			if (str[i] == '-')
				cnt1 = (mod1 - cnt1) % mod1;
			P1[i] = (P1[i - 1] + cnt1) % mod1;
			int cnt2 = pw2[sum[i]];
			if (str[i] == '-')
				cnt2 = (mod2 - cnt2) % mod2;
			P2[i] = (P2[i - 1] + cnt2) % mod2;
		}
	}
	ll ans = 0; 	
	for (int i = n;i >= 0;--i) {
 		int cnt1 = (P1[i] + 1ll * P1[n] * pw1[sum[i]]) % mod1;
 		int cnt2 = (P2[i] + 1ll * P2[n] * pw2[sum[i]]) % mod2;
 		if (M.count(mp(cnt1,cnt2)))
 			ans += M[mp(cnt1,cnt2)];
 		++M[mp(P1[i],P2[i])];
 	}
 	cout << ans << '\n';
    return 0;
}