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
typedef pair<int,int> P;
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

const ll M = 998244353;

int main(){
	string s;
	cin >> s;
	for(int i = 0 ; i+1 < s.size() ; i ++){
		if(s[i] != s[i+1])break;
		if(i+1 == s.size()-1){
			cout << 1 << endl;
			return 0;
		}
	}
	
	if(s.size() == 3){
		if(s[0] != s[1] && s[0] != s[2] && s[1] != s[2]){
			cout << 3 << endl;
			return 0;
		}
	}
	
	static ll dp[200010][2][3][3] = {};
	dp[1][0][0][0] = 1;
	dp[1][0][1][1] = 1;
	dp[1][0][2][2] = 1;
	for(int i = 1 ; i < s.size() ; i ++){
		for(int j = 0 ; j < 3 ; j ++){
			for(int k = 0 ; k < 3 ; k ++){
				dp[i+1][0][j][k] = dp[i][0][(j+3-k)%3][0]+dp[i][0][(j+3-k)%3][1]+dp[i][0][(j+3-k)%3][2]-dp[i][0][(j+3-k)%3][k];
				dp[i+1][1][j][k] = dp[i][1][(j+3-k)%3][0]+dp[i][1][(j+3-k)%3][1]+dp[i][1][(j+3-k)%3][2]+dp[i][0][(j+3-k)%3][k];
				dp[i+1][0][j][k] %= M;
				dp[i+1][1][j][k] %= M;
			}
		}
	}
	
	ll cnt = 0;
	for(int i = 0 ; i < s.size() ; i ++){
		cnt += s[i]-'a';
	}
	cnt %= 3;
	
	ll ret = dp[s.size()][1][cnt][0]+dp[s.size()][1][cnt][1]+dp[s.size()][1][cnt][2];
	
	bool t = true;
	for(int i = 0 ; i+1 < s.size() ; i ++){
		t &= s[i] != s[i+1];
	}
	if(t)ret ++;
	ret %= M;
	cout << ret << endl;
}
