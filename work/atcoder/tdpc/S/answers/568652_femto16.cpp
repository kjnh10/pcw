#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = ll(1e9 + 7);

void printBit(int b, int n){
	for(int i = n - 1; i >= 0; i--){
		cout << (b >> i & 1);
	}
	cout << endl;
}

struct UnionFind{
	vector<int> par;
	int cnt;
	UnionFind(int size_) : par(size_, -1), cnt(size_){}
	void unite(int x, int y){
		if((x = find(x)) != (y = find(y))){
			if(par[y] < par[x]) swap(x, y);
			par[x] += par[y]; par[y] = x; cnt--;
		}
	}
	bool same(int x, int y){ return find(x) == find(y); }
	int find(int x){ return par[x] < 0 ? x : par[x] = find(par[x]); }
	int size(int x){ return -par[find(x)]; }
	int size(){ return cnt; }
};

int H, W;
ll dp[101][1 << 12];

pair<vector<vector<int>>, vector<int>> makeBlock(int bit){

	vector<vector<int>> blocks;
	vector<int> group(6, -100);
	vector<int> b;
	for(int i = 0; i < 7; i++){
		if(bit >> i & 1){
			b.push_back(i);
			group[i] = blocks.size();
		}
		else if(b.size()){
			blocks.push_back(b);
			b.clear();
		}
	}
	return { blocks, group };
}

int nextState(int bit, int nxtblock){
	int  edge, connect;
	edge = bit & 7, bit >>= 3;
	connect = bit & 7, bit >>= 3;
	auto res1 = makeBlock(bit);
	auto blocks1 = res1.first;
	auto group1 = res1.second;
	auto res2 = makeBlock(nxtblock);
	auto blocks2 = res2.first;
	auto group2 = res2.second;
	if(blocks2.size() == 0) return -1;

	for(int i = 0; i < 6; i++){
		group2[i] += 3;
	}
	UnionFind uf(6);
	for(int i = 0; i < 6; i++){
		// 隣チェック
		if((bit >> i & 1) && (nxtblock >> i & 1)){
			uf.unite(group1[i], group2[i]);
		}
	}
	// 辺
	if(edge >> 0 & 1) uf.unite(0, 1);
	if(edge >> 1 & 1) uf.unite(0, 2);
	if(edge >> 2 & 1) uf.unite(1, 2);

	int nconnect = 0, nedge = 0;
	if(uf.same(3, 4)) nedge |= 1 << 0;
	if(uf.same(3, 5)) nedge |= 1 << 1;
	if(uf.same(4, 5)) nedge |= 1 << 2;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if((connect >> i & 1) && uf.same(i, 3 + j)){
				nconnect |= 1 << j;
			}
		}
	}
	if(nconnect == 0) return -1;
	return (nxtblock << 6) | (nconnect << 3) | nedge;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> W >> H;

	int bit = (1 << 6) | (1 << 3);
	dp[0][bit] = 1;
	for(int i = 0; i < H; i++){
		for(int j = 0; j < 1 << 12; j++){
			if(dp[i][j] == 0) continue;
			for(int k = 0; k < 1 << W; k++){
				int nbit = nextState(j, k);
				if(nbit == -1) continue;
				dp[i + 1][nbit] += dp[i][j];
				dp[i + 1][nbit] %= MOD;
			}
		}
	}

	ll ans = 0;
	for(int j = 0; j < 1 << 12; j++){
		bit = j;
		int edge, connect;
		edge = bit & 7, bit >>= 3;
		connect = bit & 7, bit >>= 3;
		auto res1 = makeBlock(bit);
		auto blocks1 = res1.first;
		auto group1 = res1.second;
		if(group1[W - 1] < 0) continue;
		int g = group1[W - 1];
		if(connect >> g & 1){
			ans += dp[H][j];
			ans %= MOD;
		}
	}
	cout << ans << endl;
}
