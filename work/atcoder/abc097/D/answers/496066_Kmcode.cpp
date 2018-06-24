#include <bits/stdc++.h>

using namespace std;

#define MAX 100002

int n;
int m;
vector<int> p;
int belong[MAX];
inline int root(int b){
    if(belong[b]==-1){
        return b;
    }
    belong[b]=root(belong[b]);
    return belong[b];
}
void merge(int a,int b){
    a=root(a);
    b=root(b);
    if(a==b)return;
    belong[a]=b;
}

set<int> s[100002];

int main(){
    memset(belong,-1,sizeof(belong));
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int p2;
        scanf("%d",&p2);
        p2--;
        p.push_back(p2);
    }
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        a--;
        b--;
        merge(a,b);
    }
    for(int i=0;i<n;i++){
        s[root(i)].insert(i);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(s[root(i)].count(p[i])){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
