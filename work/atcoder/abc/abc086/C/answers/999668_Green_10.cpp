#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const ll inf=(1ll<<61);
const int MX=3e5+9;
int n,t[2],x[2],y[2];
int main(){
    scanf("%d",&n);
    t[0]=x[0]=y[0]=0;
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&t[1],&x[1],&y[1]);
        int dis=abs(x[1]-x[0])+abs(y[1]-y[0]);
        int time=t[1]-t[0];
        if(dis==time)continue;
        if(dis>time){
            puts("No");
            return 0;
        }
        if(dis%2==time%2)continue;
        puts("No");
        return 0;
        t[0]=t[1];
        x[0]=x[1];
        y[0]=y[1];
    }
    puts("Yes");
}
