#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

const long long mod = 1000000007;

long long fpow(long long a, long long p)
{
	long long r = 1;
	while (p){
		if (p & 1) r = r * a % mod;
		a = a * a % mod;
		p /= 2;
	}
	return r;
}

int main()
{
	int N,K;
	scanf ("%d %d",&N,&K);

	vector<int> f;
	for (int i=1;i*i<=N;i++) if (N % i == 0){
		f.push_back(i);
		if (i * i != N) f.push_back(N/i);
	}
	sort(f.begin(),f.end());

	vector<long long> d(f.size());
	long long ans = 0;
	for (int i=0;i<f.size();i++){
		d[i] = fpow(K,(f[i]+1)/2);
		for (int j=0;j<i;j++) if (f[i] % f[j] == 0){
			d[i] = (d[i] + mod - d[j]) % mod;
		}
		long long n = d[i] * f[i] % mod;
		if (f[i] % 2 == 0) n = n * 500000004 % mod;
		ans = (ans + n) % mod;
	}

	printf ("%lld\n",ans);

	return 0;
}