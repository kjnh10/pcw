#include <bits/stdc++.h>
using namespace std;
const int dx[]={1,0,-1,0,1,-1,-1,1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
const int INF = 1<<30;
const long long LINF = 1e18;
const int EPS = 1e-8;
#define PB push_back
#define mk make_pair
#define fr first
#define sc second
#define ll long long
#define reps(i,j,k) for(int i = (j); i < (k); i++)
#define rep(i,j) reps(i,0,j)
#define MOD 1000000007
typedef pair<int,int> Pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
int stage[200100];
int main(){
	int N,Q;
	scanf("%d%d",&N,&Q);
	rep(i,Q){
		int l,r;
		scanf("%d%d",&l,&r);
		--l;--r;
		stage[l]++;
		stage[r+1]--;
	}
	stage[0] = stage[0] % 2;
	reps(i,1,N+1){
		stage[i] += stage[i-1];
		stage[i] = stage[i] % 2;
	}

	/*rep(i,N+1){
		printf("%d ",stage[i]);
	}*/

	rep(i,N){
		if(stage[i]){
			printf("1");
		}
		else{
			printf("0");
		}
	}

	puts("");

	return 0;
}