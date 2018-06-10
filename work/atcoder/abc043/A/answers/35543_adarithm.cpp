#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <vector>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define INF (INT_MAX/3)
#define PSB push_back
#define M 1000000007
typedef long long LL;
//#define int long long

/*
//booooooooooooost
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;	//多倍長整数(mp::cpp_int)
*/

int inv_mod(int a, int m)
{
	int b, x, u, q, tmp;

	b = m; x = 1; u = 0;
	while (b > 0) {
		q = a / b;
		tmp = u; u = x - q * u; x = tmp;
		tmp = b; b = a - q * b; a = tmp;
	}

	return (x < 0) ? m + x : x;
}



signed main() {


	int N;
	cin >> N;
	cout << N * (N + 1) / 2 << endl;

	return 0;
}