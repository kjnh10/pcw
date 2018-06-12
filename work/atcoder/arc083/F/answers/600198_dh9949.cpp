#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MN = 200005;
const ll M = ll(1e9) + 7;

struct E{ int x, i; };

int n, ln, vis[MN], cyc[MN], as[MN], nas[MN], vc, ec, sz[MN], oth[MN], hp[MN], fnd;
vector<E> e[MN];
vector<int> vl, cv, tv, ch[MN];
ll fc[MN], ifc[MN], ans = 1;

void T_T(){
	puts("0");
	exit(0);
}

ll pw(ll x, ll k){
	if(k == 1) return x;
	return pw(x * x % M, k / 2) * (k % 2 ? x : 1) % M;
}

ll cm(int n, int r){
	return fc[n] * ifc[r] % M * ifc[n - r] % M;
}

void g(int x){
	vis[x] = 1;
	vc++;
	ec += e[x].size();
	tv.push_back(x);
	for(auto &i : e[x]) if(!vis[i.x]) g(i.x);
}

void h(int x, int p){
	//printf("%d\n", x);
	if(vis[x] == 2){
		//puts("CYCLE");
		cyc[x] = 1;
		cv.push_back(x);
		for(int i = int(vl.size()) - 1; vl[i] != x; i--){
			//printf("%d\n", vl[i]);
			cyc[vl[i]] = 1;
			cv.push_back(vl[i]);
		}
		//puts("--");
		fnd = 1;
		return;
	}
	vis[x] = 2;
	vl.push_back(x);
	for(auto &i : e[x]){
		if(i.x != p){
			//printf("%d -> %d\n", x, i.x);
			h(i.x, x);
		}
		if(fnd) return;
	}
	vl.pop_back();
}

void af(int x, int p){
	for(auto &i : e[x]){
		if(i.x != p && !cyc[i.x]){
			as[i.x] = nas[i.x] = i.i;
			af(i.x, x);
		}
	}
}

void cf(){
	int cs = int(cv.size());
	for(int i = 0; i < cs; i++){
		for(auto &j : e[cv[i]]){
			if(j.x == cv[(i + 1) % cs]){
				//printf("%d : %d - %d (%d)\n", i, cv[i], j.x, j.i);
				as[cv[i]] = nas[j.x] = j.i;
			}
		}
	}
}

int sf(int x){
	sz[x] = 1;
	vc++;
	for(auto &i : ch[x]) sz[x] += sf(i);
	return sz[x];
}

ll tf(int x){
	ll ret = 1;
	int cs = sz[x] - 1;
	for(auto &i : ch[x]){
		ret = ret * cm(cs, sz[i]) % M;
		ret = ret * tf(i) % M;
		cs -= sz[i];
	}
	//printf("tf %d : %lld\n", x, ret);
	return ret;
}

ll get(){
	//puts("GET");
	for(auto &i : tv){
		int to = oth[as[i]] - i;
		for(auto &j : e[i]){
			if(j.x < to){
				//printf("%d - %d\n", j.x, i);
				ch[i].push_back(j.x);
				hp[j.x]++;
			}
		}
	}
	ll ret = 1;
	int tln = int(tv.size());
	for(auto &i : tv){
		if(!hp[i]){
			vc = 0;
			sf(i);
			ret = ret * cm(tln, vc) % M;
			ret = ret * tf(i) % M;
			tln -= vc;
		}
	}
	for(auto &i : tv){
		for(auto &j : ch[i]){
			hp[j]--;
		}
		ch[i].clear();
	}
	return ret;
}

ll f(int x){
	vl.clear();
	cv.clear();
	fnd = 0;
	h(x, x);
	for(auto &i : cv) af(i, i);
	cf();
	//for(auto &i : cv) printf("%d : %d %d\n", i, as[i], nas[i]);
	ll t = get();
	for(auto &i : cv) as[i] = nas[i];
	t += get();
	return t % M;
}

int main(){
	scanf("%d", &n);
	for(int i = 1, x, y; i <= 2 * n; i++){
		scanf("%d%d", &x, &y);
		y += n;
		e[x].push_back({y, i});
		e[y].push_back({x, i});
		oth[i] = x + y;
	}
	fc[0] = ifc[0] = 1;
	for(int i = 1; i <= 2 * n; i++){
		fc[i] = fc[i - 1] * i % M;
		ifc[i] = pw(fc[i], M - 2);
	}
	ln = 2 * n;
	for(int i = 1; i <= 2 * n; i++){
		if(!vis[i]){
			vc = ec = 0;
			tv.clear();
			g(i);
			if(ec != 2 * vc) T_T();
			//printf("%d %d\n", ln, vc);
			ans = ans * cm(ln, vc) % M;
			ln -= vc;
			//printf("%lld\n", ans);
			ans = ans * f(i) % M;
			//printf("////// %lld\n", ans);
		}
	}
	printf("%lld\n", ans);
}