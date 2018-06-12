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
    rep(i,1,n){
        str s1=s.substr(0,i);
        str s2=s.substr(i);
        set<char>z1,z2;for(char i:s1)z1.insert(i);for(char i:s2)z2.insert(i);
        int d=0;
        for(char i:z1)if(z2.count(i))d++;
        ans=max(ans,d);
    }
    put ans;eol;
}
int32_t main() {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);run();return 0;}
