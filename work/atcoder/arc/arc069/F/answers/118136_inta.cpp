#include<stdio.h>
#include<algorithm>
#include<vector>
#include<set>
#define pii pair<int,int>
using namespace std;
int A[101000], B[101000], n, mid, cnt, ord[201000], X[201000], SCC[201000];
set<pii>Set;
bool v[201000];
void DFS(int a, int x){
    int x2, pp;
    if(a<=n)x2 = X[a+n], pp=a+n;
    else x2 = X[a-n], pp=a-n;
    v[a] = true;
    Set.erase(pii(x2,pp));
    while(!Set.empty()){
        auto it = Set.lower_bound(pii(x-mid+1, -1));
        if(it==Set.end() || it->first > x+mid-1)break;
        int y = it->second;
        if(y==a){
            it++;
            if(it==Set.end() || it->first > x+mid-1)break;
            y = it->second;
        }
        if(y>n)DFS(y-n,X[y-n]);
        else DFS(y+n,X[y+n]);
    }
    ord[++cnt] = a;
}
void DFS2(int a, int x){
    SCC[a] = cnt;
    Set.erase(pii(x,a));
    int x2;
    if(a<=n)x2 = X[a+n];
    else x2 = X[a-n];
    while(!Set.empty()){
        auto it2 = Set.lower_bound(pii(x2-mid+1, -1));
        if(it2==Set.end() || it2->first > x2+mid-1)break;
        int y = it2->second;
        if(y==a-n || y==a+n){
            it2++;
            if(it2==Set.end() || it2->first > x2+mid-1)break;
            y = it2->second;
        }
        DFS2(y,X[y]);
    }
}
bool Pos(){
    int i;
    Set.clear();
    for(i=1;i<=n+n;i++){
        Set.insert(pii(X[i],i));
        v[i]=false;
        SCC[i] = 0;
    }
    for(i=1;i<=n+n;i++)v[i]=false;
    cnt = 0;
    for(i=1;i<=n+n;i++){
        if(!v[i])DFS(i, X[i]);
    }
    cnt = 0;
    for(i=1;i<=n+n;i++){
        Set.insert(pii(X[i],i));
    }
    for(i=n+n;i>=1;i--){
        if(!SCC[ord[i]]){
            cnt++;
            DFS2(ord[i],X[ord[i]]);
        }
    }
    for(i=1;i<=n;i++)if(SCC[i] == SCC[i+n])return false;
    return true;
}
int main(){
    int b = 0,e = 1000000000, res = 0, i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d%d",&A[i],&B[i]);
        X[i]=A[i],X[n+i]=B[i];
    }
    while(b<=e){
        mid = (b+e)>>1;
        if(Pos()){
            b = mid + 1;
            res = mid;
        }
        else e = mid -1;
    }
    printf("%d\n",res);
}