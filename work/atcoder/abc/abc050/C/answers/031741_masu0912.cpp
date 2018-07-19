#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <list>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstring>
#include <cmath>
#include <fstream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)
#define INF 1000000007
using namespace std;
typedef long long LL;
//typedef pair<int,int> P;
//typedef priority_queue<P, vector<P>, greater<P> > minPQ;
struct edge {int to,cost;};
//const int SIZE = 1<<18;

int N,A[100010];
int main() {
	cin >> N;
	REP(i,N) cin >> A[i];
	sort(A,A+N);
	bool f = true;
	if(N%2==1) {
		if(A[0]!=0) f = false;
		REP(i,(N-1)/2) {
			int j = i*2+1;
			if(A[j]!=A[j+1] || A[j]!=(i+1)*2) f = false;
		}
	} else {
		REP(i,N/2) {
			int j = i*2;
			if(A[j]!=A[j+1] || A[j]!=(i*2+1)) f = false;
		}
	}
	if(!f) {
		cout << 0 << endl;
		return 0;
	}
	LL ans = 1;
	if(N%2==1) {
		REP(i,(N-1)/2) {
			ans *= 2;
			ans %= 1000000007;
		}
	} else {
		REP(i,N/2) {
			ans *= 2;
			ans %= 1000000007;
		}
	}
	cout << ans << endl;
	return 0;
}