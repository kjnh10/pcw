#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int A, B, n, cnt = 0;
int P[4010], Q[4010];
char p[4010];
vector<int>G[4010], S;
int Input(){
    cnt++;
    if(cnt > 2*n){
        while(1){}
    }
    char pp[2];
    scanf("%s",pp);
    if(pp[0]=='Y')return 1;
    return 0;
}
void Merge(int a, int b){
    int i;
    for(i=0;i<G[b].size();i++)G[a].push_back(G[b][i]);
}
int Do(vector<int>&V){
    int i, sz = V.size();
    if(sz == 1)return V[0];
    vector<int>Q;
    for(i=0;i<sz-1;i+=2){
        printf("? %d %d\n",V[i],V[i+1]);
        fflush(stdout);
        int t = Input();
        if(t == 0){
            S.push_back(V[i]);
            S.push_back(V[i+1]);
            continue;
        }
        printf("? %d %d\n",V[i+1],V[i]);
        fflush(stdout);
        t = Input();
        if(t == 0){
            S.push_back(V[i+1]);
            continue;
        }
        Merge(V[i],V[i+1]);
        Q.push_back(V[i]);
    }
    if(sz%2 == 0 && Q.empty())return -1;
    if(sz%2==1){
        int t = Do(Q);
        if(t == -1)return V[sz-1];
        S.push_back(V[sz-1]);
        return t;
    }
    return Do(Q);
}
int main(){
    scanf("%d%d",&A,&B);
    if(A <= B){
        printf("Impossible\n");
        fflush(stdout);
        return 0;
    }
    n = A+B;
    int i;
    vector<int>V;
    for(i=0;i<n;i++){
        V.push_back(i);
        G[i].push_back(i);
        p[i]='0';
    }
    int a = Do(V);
    for(i=0;i<G[a].size();i++)p[G[a][i]]='1';
    for(i=0;i<S.size();i++){
        int x = S[i];
        printf("? %d %d\n",a,x);
        fflush(stdout);
        int t = Input();
        if(t == 1){
            for(int j=0;j<G[x].size();j++)p[G[x][j]]='1';
        }
    }
    printf("! %s\n",p);
    fflush(stdout);
}