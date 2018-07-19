/** MIT License Copyright (c) 2018 Vasilyev Daniil **/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
template<typename T> using v=vector<T>;
#define int long long
typedef string str;
typedef vector<int> vint;
#define rep(a,l,r) for(int a=(l);a<(r);a++)
#define pb push_back
#define sz(a) ((int)(a).size())
const long long inf=4611686018427387903;//2^62-1
#if 0 //FileIO
ifstream fin ("input.txt" );
ofstream fout("output.txt");
#define get fin>>
#define put fout<<
#else
#define get cin>>
#define put cout<<
#endif
#define eol put endl
void read(){}             template<typename Arg,typename... Args> void read (Arg& arg,Args&... args){get   (arg)     ;read(args...) ;}
void print(){}            template<typename Arg,typename... Args> void print(Arg  arg,Args...  args){put   (arg)<<" ";print(args...);}
void debug(){cerr<<endl;} template<typename Arg,typename... Args> void debug(Arg  arg,Args...  args){cerr<<(arg)<<" ";debug(args...);}
int getInt(){int a; get a; return a;}
//code goes here
void run(){int ans=0;
    int n;get n;str s;get s;
    int w1=0,e2=0;for(char i:s)if(i=='E')e2++;
    ans=inf;
    rep(i,0,n){
        if(s[i]=='E')e2--;
        ans=min(ans,e2+w1);
        if(s[i]=='W')w1++;
    }put ans;eol;
}
int32_t main() {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);run();return 0;}
