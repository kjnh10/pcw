#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<stack>
#include<cstdio>
#include<cmath>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<int,P> P1;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define rep(i,x) for(int i=0;i<x;i++)
#define rep1(i,x) for(int i=1;i<=x;i++)
#define rrep(i,x) for(int i=x-1;i>=0;i--)
#define rrep1(i,x) for(int i=x;i>0;i--)
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
#define mp1(a,b,c) P1(a,P(b,c))

const int INF=1000000000;
const int dir_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dir_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

P f(ll x,ll y,ll z,ll w){
	ll c[4] = { x , y , z , w };
	ll a[4] = {};
	rep(i,4){
		rep(j,4){
			a[i] *= 1000;
			a[i] += c[(i+j)%4];
		}
	}
	ll ret = max(max(a[0],a[1]),max(a[2],a[3]));
	ll cnt = 0;
	rep(i,4)if(a[i] == ret)cnt ++;
	return P(ret,cnt);
}

int main(){
	int n;
	ll c[402][4];
	P A[402];
	scanf("%d",&n);
	rep(i,n){
		rep(j,4){
			cin >> c[i][j];
		}
		A[i] = f(c[i][0],c[i][1],c[i][2],c[i][3]);
		//cout << A[i] << endl;
	}
	
	map<ll,int> M;
	rep(i,n)M[A[i].fr] += A[i].sc;
	
	ll ret = 0;
	rep(i,n){
		M[A[i].fr] -= A[i].sc;
		for(int j = i+1 ; j < n ; j ++){
			M[A[j].fr] -= A[j].sc;
			rep(k,4){
				P x[4];
				ll _ret = 1;
				rep(l,4){
					x[l] = f(c[i][l],c[j][(k+4-l)%4],c[j][(k+4-l-1)%4],c[i][(l+1)%4]);
					_ret *= M[x[l].fr];
					M[x[l].fr] -= x[l].sc;
				}
				rep(l,4){
					M[x[l].fr] += x[l].sc;
				}
				ret += _ret;
			}
			M[A[j].fr] += A[j].sc;
		}
	}
	
	cout << ret << endl;
}

