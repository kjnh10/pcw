#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define REP3(i, m, n) for(int i = m, i##_len=(n);i < i##_len;i++)
#define FORVEC(i, v) for(int i = 0;i < v.size();i++)

#define INF 1000000000
#define pb(a) push_back(a)
#define llong long long

int main(){
	int n,a;
	cin>>n>>a;
	cout<<n*n-a<<endl;
	return 0;
}
