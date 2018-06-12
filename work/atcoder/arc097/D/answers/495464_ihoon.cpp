#include <bits/stdc++.h>
using namespace std;

int perm[100001];
int clr[100001];

int fnd(int x){
    if(x != clr[x]){
        clr[x] = fnd(clr[x]);
    }
    return clr[x];
}
int main(){
    int n, m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&perm[i]);
        clr[i] = i;
    }
    for(int i=0;i<m;i++){
        int aa, bb;
        scanf("%d%d",&aa,&bb);
        if(fnd(aa) == fnd(bb)) continue;
        clr[clr[bb]] = clr[aa];
    }
    for(int i=1;i<=n;i++) fnd(i);
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(clr[i] == clr[perm[i]]) ans++;
    }
    printf("%d\n", ans);
}
