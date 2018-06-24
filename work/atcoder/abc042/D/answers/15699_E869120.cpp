#include<iostream>
using namespace std;
#define mod 1000000007
long long H, W, A, B, K, ret, res, fact[300000], inv[300000], factinv[300000];
long long ncr(int n, int r) { return (n - r >= 0 && r >= 0) ? 1LL * fact[n] * factinv[r] % mod * factinv[n - r] % mod : 0; }
int main() {
	fact[0] = 1; for (int i = 1; i < 300000; i++) fact[i] = 1LL * fact[i - 1] * i % mod;
	inv[1] = 1; for (int i = 2; i < 300000; i++) inv[i] = 1LL * inv[mod % i] * (mod - mod / i) % mod;
	factinv[0] = 1; for (int i = 1; i < 300000; i++) factinv[i] = 1LL * factinv[i - 1] * inv[i] % mod;
	cin >> H >> W >> A >> B; long long sum = 0;
	for (int i = 0; i < H - A; i++) {
		sum += ncr(B + i - 1, B - 1)*ncr((W - B - 1) + (H - i - 1), W - B - 1); sum %= mod;
	}
	cout << sum << endl;
	return 0;
}
