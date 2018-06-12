#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <bitset>

using namespace std;
typedef pair<int, int> Pi;
typedef long long ll;
#define pii Pi
#define pll PL
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> PL;
typedef long double ldouble;

const int inf = 1e9;

vector <ll> V;

struct node{
	node(){add = val = 0, cnt = 1; child[0] = child[1] = par = 0;}
	node(int x){
		add = 0, val = x, cnt = 1, child[0] = child[1] = par = 0;
	}
	int cnt;
	ll add, val;
	node *child[2], *par;
	inline int mydir(){
		return par->child[0] != this;
	}
	void pushdown(){
		if(add){
			if(child[0])child[0]->add += add, child[0]->val += add;
			if(child[1])child[1]->add += add, child[1]->val += add;
			add = 0;
		}
	}
	void pushup(){
		cnt = 1 + (child[0] ? child[0]->cnt : 0) + (child[1] ? child[1]->cnt : 0);
	}
	inline void Ins(int dir, int x){
		child[dir] = new node(x);
		child[dir]->par = this;
		pushup();
	}
	void *rotate(int dir){
		node *tmp = child[!dir];
		pushdown();
		tmp->pushdown();
		tmp->par = par;
		if(par)par->child[mydir()] = tmp;
		child[!dir] = tmp->child[dir];
		if(tmp->child[dir])tmp->child[dir]->par = this;
		tmp->child[dir] = this;
		par = tmp;
		pushup();
		tmp->pushup();
		return tmp;
	}
	void splay(node *rootp){
		while(par != rootp){
			int myd = mydir();
			if(par->par == rootp){
				par->rotate(!myd);
			}
			else if(myd == par->mydir()){
				par->par->rotate(!myd);
				par->rotate(!myd);
			}
			else{
				par->rotate(!myd);
				par->rotate(myd);
			}
		}
	}
	node *kth_node(int k){
		pushdown();
		int c = (child[0] ? child[0] -> cnt : 0);
		if(c+1 == k)return this;
		else if(c+1 < k){
			k -= c+1;
			return child[1]->kth_node(k);
		}
		else{
			return child[0]->kth_node(k);
		}
	}
	void travel(){
		pushdown();
		if(child[0])child[0]->travel();
		V.pb(val);
		//printf("%lld ", val);
		if(child[1])child[1]->travel();
	}
	node *Insert(int x){
		pushdown();
		if(val >= x){
			if(!child[0]){ Ins(0, x); return child[0]; }
			else{
				auto res = child[0]->Insert(x);
				pushup();
				return res;
			}
		}
		else{
			if(!child[1]){ Ins(1, x); return child[1]; }
			else{
				auto res = child[1]->Insert(x);
				pushup();
				return res;
			}
		}
	}
};

struct splaytree{
	splaytree(int x){
		root = new node(x);
		root->Ins(1, x);
		root->pushup();
		C = 2;
	}
	int C;
	node *root;
	void travel(){
		root->travel(); //puts("");
	}
	node *kth_splay(int k, node *rootp){
		node *tmp = root->kth_node(k);
		tmp->splay(rootp);
		return tmp;
	}
	void query(int ls, int rs){
		auto p = kth_splay(C / 2, 0);
		root = p;
		p->val -= ls;
		if(p->child[0])p->child[0]->val -= ls, p->child[0]->add -= ls;
		if(p->child[1])p->child[1]->val += rs, p->child[1]->add += rs;
	}
	void Insert(int x){
		auto p = root->Insert(x);
		p->splay(0); root = p;
		p = root->Insert(x);
		p->splay(0); root = p;
		C += 2;
	}
}*ST;

int L[100010], R[100010];

//#define __int128 long long

void solve(){
	int N; scanf("%d", &N);
	for(int i=1;i<=N;i++)scanf("%d%d", L+i, R+i), R[i] -= L[i];
	ST = new splaytree(L[1]);
	ll T = -2000000000000000LL;
	__int128 F = -T + L[1];
	for(int i=2;i<=N;i++){
		ST->query(R[i], R[i-1]);
		F -= (__int128) R[i] * (i-1);
		ST->Insert(L[i]);
		F += (-T + L[i]);
		//ST->travel();
	}
	V.pb(T);
	ST->travel();
	__int128 now = F;
	__int128 ans = F;
	for(int i=1;i<sz(V);i++){
		int a = i - N - 1;
		now += (__int128)(V[i] - V[i-1]) * a;
		ans = min(ans, now);
	}
	if(ans == 0){
		puts("0");
		return;
	}
	//printf("%lld\n", ans);
	string s;
	while(ans)s.pb(ans % 10 + '0'), ans /= 10;
	reverse(all(s));
	printf("%s\n", s.c_str());
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}