#include <iostream>
#include<algorithm>
#include<set>
#include<queue>
#include<bitset>
#define rep(i,j,n) for(int i=j;i<n;i++)
using namespace std;
#define int long long
int mul[214514];
int divi[214514];
#define inf 1000000007
int bit[114514],n;
struct edge{int u,v,cost;};
edge es[214514];
int zero=0;
string alph("abcdefghijklmnopqrstuvwxyz");
int fi[2005][2005]={};
signed main(){
    int a,b,c,x;cin>>a>>b>>c>>x;
    int count=0;
    rep(i,0,a+1){
        rep(j,0,b+1){
            rep(k,0,c+1){
                if(i*500+100*j+50*k==x)count++;
            }
        }
    }
    cout<<count<<endl;
    return 0;
}
