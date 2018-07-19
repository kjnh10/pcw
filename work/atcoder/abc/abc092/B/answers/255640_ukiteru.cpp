#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<stdio.h>
#include<cmath>
#include<vector>
#include<utility>
#include<stack>
#include<queue>
#include<list>
#include<bitset>
#include<functional>

#define FOR(i, a, b) for(long long int i=(a);i<=(b);i++)
#define RFOR(i, a, b) for(long long int i=(a);i>=(b);i--)
#define MOD 1000000007
#define INF 1000000000 //2000000000
#define LLINF 1000000000000000000 //9000000000000000000
#define PI 3.14159265358979

using namespace std;
typedef long long int ll;
typedef pair< long long int, long long  int> P;



int main(void) {
	int n, d, x;
	int a[101];
	int count = 0;
	int point = 0;

	cin >> n >> d >> x;
	FOR(i, 1, n) {
		cin >> a[i];
		for (int t = 1; t <= d; t += a[i]) {
			count++;
		}
	}
	cout << x + count << endl;
	return 0;
}