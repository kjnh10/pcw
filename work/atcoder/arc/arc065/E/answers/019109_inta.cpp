#include<stdio.h>
#include<algorithm>
#include<cstdlib>
#include<set>
#define pli pair<long long, int>
using namespace std;
struct point{
    int x, y;
}w[101000];
int n, s1, s2, L;
bool v[101000];
set<pli>Set1, Set2;
long long p1[101000], p2[101000], Res;
long long Get(int a, int b){
    if(b == 1)return w[a].x*(1ll<<31) + w[a].y;
    else return w[a].y*(1ll<<31) + w[a].x;
}
void DFS(int a){
    v[a]=true;
    long long t1 = Get(a,1), t2 = Get(a,2);
    Set1.erase(pli(t1,a));
    Set2.erase(pli(t2,a));
    long long tt = L*(1ll<<31);
    set<pli>::iterator it;
    while(1){
        it = Set1.lower_bound(pli(t1+tt-L, 0));
        if(it!=Set1.end() && it->first <= t1+tt+L){
            DFS(it->second);
        }
        else break;
    }
    while(1){
        it = Set1.lower_bound(pli(t1-tt-L, 0));
        if(it!=Set1.end() && it->first <= t1-tt+L){
            DFS(it->second);
        }
        else break;
    }
    while(1){
        it = Set2.lower_bound(pli(t2+tt-L, 0));
        if(it!=Set2.end() && it->first <= t2+tt+L){
            DFS(it->second);
        }
        else break;
    }
    while(1){
        it = Set2.lower_bound(pli(t2-tt-L, 0));
        if(it!=Set2.end() && it->first <= t2-tt+L){
            DFS(it->second);
        }
        else break;
    }
}
int main(){
    int i;
    scanf("%d%d%d",&n,&s1,&s2);
    for(i=1;i<=n;i++){
        scanf("%d%d",&w[i].x,&w[i].y);
    }
    L = abs(w[s1].x-w[s2].x) + abs(w[s1].y-w[s2].y);
    for(i=1;i<=n;i++){
        int t = w[i].x-w[i].y;
        w[i].x = w[i].x+w[i].y;
        w[i].y = t;
        p1[i] = Get(i,1);
        p2[i] = Get(i,2);
        Set1.insert(pli(Get(i,1),i));
        Set2.insert(pli(Get(i,2),i));
    }
    DFS(s1);
    sort(p1+1,p1+n+1);
    sort(p2+1,p2+n+1);
    for(i=1;i<=n;i++){
        if(!v[i])continue;
        long long tt = L* (1ll<<31), t1 = Get(i,1), t2 = Get(i,2);
        Res += upper_bound(p1+1,p1+n+1,t1+tt+L) - lower_bound(p1+1,p1+n+1,t1+tt-L);
        Res += upper_bound(p1+1,p1+n+1,t1-tt+L) - lower_bound(p1+1,p1+n+1,t1-tt-L);
        Res += upper_bound(p2+1,p2+n+1,t2+tt+L-1) - lower_bound(p2+1,p2+n+1,t2+tt-L+1);
        Res += upper_bound(p2+1,p2+n+1,t2-tt+L-1) - lower_bound(p2+1,p2+n+1,t2-tt-L+1);
    }
    printf("%lld\n",Res/2);
}