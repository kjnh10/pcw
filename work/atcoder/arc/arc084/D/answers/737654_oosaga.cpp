#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
const int MAXN = 1000000;
const int mod = 1e9 + 7;
typedef pair<int, int> pi;

int dis[MAXN];
priority_queue<pi, vector<pi>, greater<pi> > pq;

int main(){
	int n;
	cin >> n;
	memset(dis, 0x3f, sizeof(dis));
	for(int i=1; i<=9; i++){
		if(dis[i % n] > i){
			dis[i % n] = i;
			pq.push(pi(i, i % n));
		}
	}
	while(!pq.empty()){
		auto x = pq.top();
		pq.pop();
		if(dis[x.second] != x.first) continue;
		for(int i=0; i<10; i++){
			int nxt = 10 * x.second + i;
			nxt %= n;
			if(dis[nxt] > dis[x.second] + i){
				dis[nxt] = dis[x.second] + i;
				pq.push(pi(dis[nxt], nxt));
			}
		}
	}
	cout << dis[0] << endl;
}
