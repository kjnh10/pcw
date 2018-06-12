#include<cstdio>
#include<deque>
#include<algorithm>

using namespace std;

typedef double Real;

long long ts[500500];
long long vs[500500];
Real vals[500500];
int N;
long long L;

void input(){
	scanf("%d%lld", &N, &L);
	for(int i = 0; i < N; ++i){
		scanf("%lld%lld", ts + i, vs + i);
	}
}

typedef pair<long long, Real> P;

deque<P> deq;

Real ans[500500];

bool check(P p1, P p2, P p3){
	Real dx1 = p2.first - p1.first;
	Real dy1 = p2.second - p1.second;
	Real dx2 = p3.first - p1.first;
	Real dy2 = p3.second - p1.second;
	return (dx1 * dy2 - dx2 * dy1 >= 0);
}

Real f(Real x, Real y, Real a, Real b){
	//printf("%f %f %f %f\n", x, y, a, b);
	return x + (y - x) * (a / (a + b));
}

void solve(){
	for(int i = 0; i < N; ++i){
		vals[i] = (Real)ts[i] * vs[i];
//		printf("%f\n", vals[i]);
	}
	ans[0] = ts[0];
	deq.push_front(P(0, 0));
	deq.push_back(P(L, vals[0]));
	for(int i = 1; i < N; ++i){
		if(vs[i] == L){
			P fi = deq[0];
			P nfi = P(fi.first - vs[i], fi.second - vals[i]);
			while(deq.size() >= 2){
				deq.pop_back();
			}
			deq.push_front(nfi);
			ans[i] = ts[i];
			continue;
		}
		long long ub = deq[0].first + L - vs[i];
		while(deq.back().first > ub){
			P tmp = deq.back();
			deq.pop_back();
			if(deq.back().first > ub){
				continue;
			}else if(deq.back().first == ub){
				break;
			}else{
				Real nxt = f(deq.back().second, tmp.second, ub - deq.back().first, tmp.first - ub);
				deq.push_back(P(ub, nxt));
//				printf("%f\n", nxt);
				break;
			}
		}
		P fi = deq[0];
		P nfi = P(fi.first - vs[i], fi.second - vals[i]);
		while(deq.size() >= 2){
			if(check(nfi, deq[0], deq[1])){
				deq.pop_front();
			}else{
				break;
			}
		}
		deq.push_front(nfi);
		Real val = deq.back().second - deq[0].second;
		ans[i] = val / L;
	}
}

int main(){
	input();
	solve();
	for(int i = 0; i < N; ++i){
		printf("%.12f\n", ans[i]);
	}
	return 0;
}
