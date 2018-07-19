#include<bits/stdc++.h>
using namespace std;
 
 
#define MAX 52
 
int n;
int a;
int b;
 
long long int v[MAX];
 
long long int dp[MAX][MAX];
 
 
struct fraction{
	long long int A;
	long long int B;
	long long int way;
	fraction(long long int a_, long long int b_, long long int way_){
		A = a_;
		B = b_;
		way = way_;
	}
};
bool big(fraction a, fraction b){
	return a.A*b.B > b.A*a.B;
}
bool eq(fraction a, fraction b){
	return a.A*b.B == b.A*a.B;
}
map<long long int, int> mp;
map<long long int, int> use;
int main(){
	dp[0][0] = 1;
	for (int i = 0; i <50; i++){
		for (int j = 0; j <= i; j++){
			dp[i + 1][j] += dp[i][j];
			dp[i + 1][j + 1] += dp[i][j];
		}
	}
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++){
		long long int A;
		scanf("%lld", &A);
		v[i] = A;
		mp[v[i]]++;
	}
	sort(v, v + n);
	reverse(v, v + n);
	fraction cur(0, 0, 1);
	fraction maxt(0, 1, 0);
	for (int i = 0; i < n; i++){
		cur.A += v[i];
		cur.B++;
		use[v[i]]++;
		if (cur.B >= a&&cur.B <= b){
			if (big(maxt, cur)){
				continue;
			}
			if (eq(maxt, cur)){
 
			}
			else{
				maxt = cur;
				maxt.way = 0;
			}
			maxt.way += dp[mp[v[i]]][use[v[i]]];
		}
	}
	double f = (long double)(maxt.A) / (long double)(maxt.B);
	printf("%.16f\n", f);
	printf("%lld\n", maxt.way);
	return 0;
}