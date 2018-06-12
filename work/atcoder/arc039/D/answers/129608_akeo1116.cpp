#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <utility>
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define PI 4*atan(1.0)
using namespace std;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

int calc(long long int a,long long int b,long long int p){
	if(!b) return 1;
	else if(!(b%2)){
		long long int d=calc(a,b/2,p);
		return (d*d)%p;
	}else return (a*calc(a,b-1,p))%p;
}

int main(){
	int N,K;
	long long ans=1;
	cin>>N>>K;
	if(N>K){
		for(int i=1;i<=N+K-1;i++)
			ans=ans*i%MOD;
		for(int i=1;i<=N-1;i++)
			ans=ans*calc(i,MOD-2,MOD)%MOD;
		for(int i=1;i<=K;i++)
			ans=ans*calc(i,MOD-2,MOD)%MOD;
	}
	else{
		for(int i=1;i<=N;i++)
			ans=ans*i%MOD;
		for(int i=1;i<=N-(K%N);i++)
			ans=ans*calc(i,MOD-2,MOD)%MOD;
		for(int i=1;i<=K%N;i++)
			ans=ans*calc(i,MOD-2,MOD)%MOD;
	}
	cout<<ans<<endl;
	return 0;
}