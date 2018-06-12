/*
*/

//#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>

#include <memory.h>
#include <assert.h>

#define y0 sdkfaslhagaklsldk

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 300031;

int n;
long long C;
vector<pair<long long, long long> > order;
long long ans;

long long x[N],S[N],win[N];
long long v[N];
long long sv[N];

void solve(vector<pair<long long, long long> > V){
	for (int i=1;i<=n;i++){
		x[i]=V[i-1].first;
		v[i]=V[i-1].second;
	}

	for (int i=n;i>=1;--i){
		S[i]=S[i+1]+v[i];
		win[i]=S[i]-(C-x[i])*2;
	}
	for (int i=n;i>=1;--i){
		win[i]=max(win[i],win[i+1]);
	}

	/*for (int i=1;i<=n;i++){
		cout<<win[i]<<endl;
	}*/
	ans=max(ans,win[1]);

	for (int i=1;i<=n;i++){
		sv[i]=sv[i-1]+v[i];
	}
	for (int i=1;i<=n;i++){
		ans=max(ans,win[i+1]+sv[i]-x[i]);
	}
}
int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n>>C;
	for (int i=1;i<=n;i++){
		long long a,b;
		cin>>a>>b;
		order.push_back(make_pair(a,b));
	}

	solve(order);
	for (int i=0;i<order.size();i++){
		order[i].first=C-order[i].first;
	}
	sort(order.begin(),order.end());

	solve(order);

	cout<<ans<<endl;


//	cin.get(); cin.get();
	return 0;
}
