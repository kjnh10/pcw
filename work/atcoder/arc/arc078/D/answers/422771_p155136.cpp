#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

const int MAX_N = 1e5 +6;

vector<int> edg[MAX_N];
bool visit[MAX_N];
int depth[MAX_N];
int p[MAX_N];
int sz[MAX_N];

void dfs(int id,int pp,int cur_depth) {
    visit[id]=1;
    sz[id]=1;
    p[id] = pp;
    depth[id] = cur_depth;
    for (int i:edg[id]) {
        if (!visit[i]) {
            dfs(i,id,cur_depth+1);
            sz[id] += sz[i];
        }
    }
}

int main () {
    int n;
    scanf("%d",&n);
    for (int i=1;n>i;i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        edg[a].push_back(b);
        edg[b].push_back(a);
    }
    dfs(1,1,1);
    int delta=depth[n] - depth[1];
    int cnt=(delta-1)/2;
    int tmp=n;
    while (cnt--) tmp=p[tmp];
    int cntb=sz[tmp],cnta=n-sz[tmp];
    if (cnta > cntb) puts("Fennec");
    else puts("Snuke");
}

