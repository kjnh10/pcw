#include "bits/stdc++.h"
 
#define REP(i,n) for(int i=0;i<n;++i)
typedef long long ll;
using namespace std;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	string p[] = { "Perfect","Great","Good","Bad" };
	int v[] = { 100,90,60,0 };
	REP(i, 4) {
		if (n >= v[i]) {
			cout << p[i] << endl;
			break;
		}
	}
}