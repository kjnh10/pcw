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
	string s;
	int x,y;
	bool isy=false,is1st=true;
	set<int> dpx,dpy;
	set<int> buf;
	cin>>s;
	cin>>x>>y;
	dpx.insert(0);
	dpy.insert(0);
	REP(i,sz(s)){
		if(s[i]=='F'){
			int cnt=0;
			while(s[i]=='F'&&i<sz(s)){
				cnt++;
				i++;
			}i--;
			//cout<<cnt<<"Forward\n";
			if(isy){
				buf=dpy;
				dpy.clear();
				for(auto a:buf){
					dpy.insert(a+cnt);
					dpy.insert(a-cnt);
				}
			}else{
				buf=dpx;
				dpx.clear();
				for(auto a:buf){
					dpx.insert(a+cnt);
					if(!is1st)dpx.insert(a-cnt);
				}
			}
		}else if(s[i]=='T'){
			isy=!isy;
			is1st=false;
			//cout<<"Turn\n";
		}else{
			//cout<<s[i]<<"ERROR\n";
		}
	}

	//for(auto a:dpx)cout<<a<<" ";cout<<"\n";
	//for(auto a:dpy)cout<<a<<" ";cout<<"\n";

	if(dpx.count(x)&&dpy.count(y)){
		cout<<"Yes\n";
	}else{
		cout<<"No\n";
	}
	return 0;
}
