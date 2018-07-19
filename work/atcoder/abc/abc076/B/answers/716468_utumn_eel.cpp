#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
#define MOD 1000000007
#define EPS (1e-10)
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

int main(){
	int n,k;cin>>n>>k;
	int a=1;
	rep(i,n){
		a=min(a*2,a+k);
	}
	cout<<a<<endl;
}
