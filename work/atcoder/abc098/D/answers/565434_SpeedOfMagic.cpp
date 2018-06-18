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
    int n;get n;
    int a[n];rep(i,0,n)get a[i];
    int nxtNot0[n];rep(i,0,n)nxtNot0[i]=-1;
    vint pos;
    rep(i,0,n){
        if(a[i]!=0){
            for(int j:pos)nxtNot0[j]=i;
            pos.clear();
        }
        pos.pb(i);
    }
    rep(i,0,n){
        int cur=0,ind=i;
        while(ind!=-1){
            //debug(i,ind);
            if((cur^a[ind])!=cur+a[ind])break;
            cur+=a[ind];
            ind=nxtNot0[ind];
        }
        if(ind==-1)ind=n;
        ans+=max(ind-1,i)-i+1;
    }
    put ans;eol;
}
int32_t main() {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);run();return 0;}
