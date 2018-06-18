#include <iostream>
#include <algorithm>

const long long mod = 1e9 + 7ll;
const int N = 2 * 1e5 + 10;

long long fac[ N ];

long long pw( long long a, long long b ) {
	if ( b == 0ll ) return 1ll;
	long long r = pw( a, b / 2ll );
	r = ( r * r ) % mod;
	if ( b % 2ll ) r = ( a * r ) % mod;
	return r;
}
long long inv( long long x ) {
	return pw( x, mod - 2ll );
}
long long path( long long a, long long b ) {
	long long ans = fac[ a + b ];
	ans = ( ans * inv( fac[ a ] ) ) % mod;
	ans = ( ans * inv( fac[ b ] ) ) % mod;
	return ans;
}
int main ( void ) {

	int h, w, a, b;
	std::cin >> h >> w >> a >> b;

	fac[0] = 1ll;
	for ( int i = 1 ; i < N ; i++ ) {
		fac[i] = ( i * fac[i-1] ) % mod;
	}

	long long ans = 0ll;
	for ( int i = h - a, j = b + 1 ; i > 0 and j <= w ; i--, j++ ) {
		ans += ( path( i - 1, j - 1 ) * path( h - i, w - j ) ) % mod;
	}

	ans = ( ans % mod + mod ) % mod;
	std::cout << ans << std::endl;

	return 0;
}