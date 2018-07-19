#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define REPO(i,n) for(int (i)=1; (i)<=(int)(n); (i)++)
#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
typedef long long ll;
typedef pair<int, int> pi;
const int INF = 0x3f2f1f0f;
const ll LINF = 1ll * INF * INF;

const int MAX_N = 2e5 + 100;

int N, M; pi Nr[MAX_N];
int main() {
	cin >> N >> M;
	REP(i, N) scanf("%d%d", &Nr[i].one, &Nr[i].two);
	sort(Nr, Nr+N, [&](pi a, pi b) {
		if(a.one == b.one) return a.two > b.two;
		return a.one < b.one;
	});
	
	priority_queue<int, vector<int>, greater<int>> Q;
	priority_queue<int, vector<int>, greater<int>> R;
	for(int i=0, m=1; m<=M; m++) {
		while(i < N && Nr[i].one < m) R.push(Nr[i++].two);
		while(i < N && Nr[i].one == m) Q.push(Nr[i++].two);
		while(Q.size() > m) R.push(Q.top()), Q.pop();
	}
	int l = Q.size() + 1;
	for(int m=l; m<=M; m++) {
		if(!R.empty() && R.top() <= m) R.pop();
	}
	printf("%d\n", R.size());
	return 0;
}