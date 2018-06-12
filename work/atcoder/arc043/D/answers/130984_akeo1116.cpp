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

int main(){
	long long ans=0;
	long long N,D[100000]={};
	long long tes[100000]={},ket[100000]={},xal[100000]={};
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>D[i];
	}
	sort(D,D+N);
	for(int i=0;i<N;i++)
		tes[i]=N-(lower_bound(D,D+N,2*D[i])-D);
	ket[N-1]=tes[N-1];
	for(int i=N-1;i>=0;i--)
		ket[i]=ket[i+1]+tes[i];
	for(int i=0;i<N;i++)
		xal[i]=(upper_bound(D,D+N,D[i]/2)-D);

	for(int i=0;i<N;i++)
		ans=(ans+xal[i]*ket[lower_bound(D,D+N,2*D[i])-D])%MOD;
	cout<<ans<<endl;
	return 0;
}