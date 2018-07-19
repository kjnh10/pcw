#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%lld",&x); }
void read(pp& x){ read(x.first); read(x.second); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second

int R, C, n;

vector<pp> bord;

int ind(pp a){
	int ret=0;
	if(a.x == 0) return ret+a.y;
	ret += C;
	if(a.y == C) return ret+a.x;
	ret += R;
	if(a.x == R) return ret+(C-a.y);
	ret += C;
	if(a.y == 0) return ret+(R-a.x);
	return -1;
}

bool e[100010];

void no(){
	puts("NO");
	exit(0);
}

int main()
{
	read(R, C, n);
	for(int i=1; i<=n; ++i){
		pp p1, p2;
		read(p1, p2);
		int i1=ind(p1), i2=ind(p2);
		if(i1>=0 && i2>=0){
			bord.eb(i1, i);
			bord.eb(i2, i);
		}
	}
	sort(all(bord));
	stack<int> s;
	for(auto tmp:bord){
		int x=tmp.second;
		if(e[x]){
			if(s.empty() || s.top() != x) no();
			s.pop();
			e[x]=0;
		} else {
			e[x]=1;
			s.push(x);
		}
	}
	puts("YES");
	return 0;
}
