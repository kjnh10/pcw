#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <cassert>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define mod 1000000007
bool u[105][105];
int main(){
	char f[105][105];
	int n,m; cin >> n >> m;
	for(int i=0;i<n;i++) scanf("%s",&f[i]);
	int dx[8]={1,1,1,0,0,-1,-1,-1};
	int dy[8]={1,0,-1,1,-1,1,0,-1};
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(f[i][j] == '.'){ u[i][j] = 1;
				for(int k=0;k<8;k++){
					int nx = i+dx[k],ny = j+dy[k];
					if(0<=nx&&nx<n&&0<=ny&&ny<m){
						u[nx][ny] = 1;
					}
				}
			}
		}
	}
	char F[105][105];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(u[i][j]) F[i][j] = '.';
			else F[i][j] = '#';
		}
	}
	char G[105][105];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			G[i][j] = F[i][j];
			{
				for(int k=0;k<8;k++){
					int nx = i+dx[k],ny = j+dy[k];
					if(0<=nx&&nx<n&&0<=ny&&ny<m&&F[nx][ny]=='#'){
						G[i][j] = '#';
					}
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(G[i][j] != f[i][j]){
				puts("impossible"); return 0;
			}
		}
	}puts("possible");
	for(int i=0;i<n;i++){
		printf("%s\n",F[i]);
	}
}