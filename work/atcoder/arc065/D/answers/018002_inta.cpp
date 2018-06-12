#include<stdio.h>
#include<algorithm>
#include<map>
using namespace std;
#define pii pair<int,int>
map<pii,int>Map;
int n, m, K;
int UF[2][201000];
int Find(int pv, int a){
    if(UF[pv][a]==a)return a;
    return UF[pv][a] = Find(pv, UF[pv][a]);
}
void Merge(int pv, int a, int b){
    a=Find(pv,a);
    b=Find(pv,b);
    if(a!=b)UF[pv][a]=b;
}
int main(){
    int i, a, b;
    scanf("%d%d%d",&n,&m,&K);
    for(i=1;i<=n;i++)UF[0][i]=UF[1][i]=i;
    for(i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        Merge(0,a,b);
    }
    for(i=0;i<K;i++){
        scanf("%d%d",&a,&b);
        Merge(1,a,b);
    }
    for(i=1;i<=n;i++){
        Map[pii(Find(0,i),Find(1,i))]++;
    }
    for(i=1;i<=n;i++)printf("%d ",Map[pii(Find(0,i),Find(1,i))]);
    printf("\n");
}