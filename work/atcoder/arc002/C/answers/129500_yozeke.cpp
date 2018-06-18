#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i = 0;i<((int)(n));i++)
#define reg(i,a,b) for(int i = ((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i = ((int)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(int i = ((int)(b)-1);i>=((int)(a));i--)
typedef long long int lli;
typedef pair<int, int> mp;
#define fir first
#define sec second
#define IINF INT_MAX
#define LINF LLONG_MAX
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define pque(type) priority_queue<type,vector<type>,greater<type> >
#define memst(a,b) memset(a,b,sizeof(a))

int main(void){
	int n; cin >> n;
	string s;
	cin >> s;

	string b[16] = {"AA", "AB", "AX", "AY",
					"BA", "BB", "BX", "BY",
					"XA", "XB", "XX", "XY",
					"YA", "YB", "YX", "YY"};
	
	int ans = n;
	
	reg(l, 0, 15) reg(r, l+1, 15){
		int p = n;
		rep(i, n-1){
			if( (s[i] == b[l][0] && s[i+1] == b[l][1]) || (s[i] == b[r][0] && s[i+1] == b[r][1]) ){
				p--;
				i++;
			}
		}
		ans = min(ans, p);
	}
	
	cout << ans << endl;
}