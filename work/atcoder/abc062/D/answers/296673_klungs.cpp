#include<bits/stdc++.h>

#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define pb2 pop_back
#define pf2 pop_front
#define line printf("\n")
#define pq priority_queue
#define rep(k,i,j) for(int k = (int)i;k<(int)j;k++)
#define repd(k,i,j) for(int k = (int)i;k>=(int)j;k--)
#define ll long long

using namespace std;

double EPS = 1e-9;
int INF = 1e9+7;;
long long INFLL = 1e17;
double pi = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};

inline void OPEN (string s) {
  freopen ((s + ".in").c_str (), "r", stdin);
  freopen ((s + ".out").c_str (), "w", stdout);
}

//end of template

const int maxn = 3e5+5;
int n;
int arr[maxn];

ll Left[maxn],Right[maxn];
int main(){
	scanf("%d",&n);
	rep(k,0,3*n)scanf("%d",&arr[k]);
	
	pq<int,vector<int>,greater<int> > ki;
	pq<int> ka;
	
	ll ret = 0;
	rep(k,0,3*n){
		ki.push(arr[k]);ret+= arr[k];
		while(ki.size()>n)ret-=ki.top(),ki.pop();
		Left[k] = ret;
	}
	ret = 0;
	repd(k,3*n-1,0){
		ka.push(arr[k]);ret+= arr[k];
		while(ka.size()>n)ret-=ka.top(),ka.pop();
		Right[k] = ret;
	}
	
	ret = -INFLL;
	rep(k,n-1,2*n)ret = max(ret,Left[k] -Right[k+1]);
	cout<<ret<<endl;
	return 0;
}
