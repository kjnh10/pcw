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
	string s; cin >> s;

	bool f = false;
	lli x = 0, y = 0;
	rep(i, s.size()){
		if(s[i] == '/'){ f = true; continue; }
		else if(f == false){
			x = x*10 + (s[i] - '0') ;
		}else{
			y = y*10 + (s[i] - '0');
		}
	}

	lli p = x, q = y;
	lli r = -1;
	
	while(r != 0){
		 r = p % q;
		 p = q;
		 q = r;
	}
	
	x /= p; y /= p;
		
	lli n, m ,l = ((2*x)/y - 1)/y;
	bool fl = false;

	while(true){
		n = l*y;
		m = n*(n+1)/2-l*x;
		l++;
		if(m <= 0) continue;
		else if(m <= n){
			cout << n << " " << m << endl;
			fl = true;
		}else if(fl == false){
			cout << "Impossible" << endl;
			break;
		}else{
			break;
		}
	}
	
	return 0;
}