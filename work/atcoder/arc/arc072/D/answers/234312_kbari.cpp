#include <bits/stdc++.h>

using namespace std ;

const int MAXN = 1e6 + 100 ; 

int a[MAXN] ; 
int32_t main() {	
	ios_base::sync_with_stdio(0) ; 
	cin . tie(0) ; cout . tie(0) ; 

	long long x , y ; cin >> x >> y ;
	if(abs(x - y) < 2)cout << "Brown" ; 
	else cout << "Alice" ; 

}