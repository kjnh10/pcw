#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define pb(a) push_back(a)
#define vi vector<int>
#define vvi vector<vi>
#define P pair<int,int>
#define all(vec) (vec.begin()),(vec.end())
#define ll long long;
#define sz(x) ((int)(x).size())
#define in(x) int x;cin>>x;
#define bit(n) (1<<(n))

#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define REP3(i, m, n) for(int i = m, i##_len=(n);i < i##_len;i++)
#define FORVEC(i, v) for(int i = 0;i < sz(v);i++)


int main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a+b==c+d){
		cout<<"Balanced\n";
	}else if(a+b>c+d){
		cout<<"Left\n";
	}else{
		cout<<"Right\n";
	}
	return 0;
}