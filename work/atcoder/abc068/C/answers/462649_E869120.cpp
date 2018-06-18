#include<bits/stdc++.h>
using namespace std;
int n,m,a,b;map<int,int>M[220000];
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;M[a][b]=1;M[b][a]=1;
    }
    for(int i=2;i<=n-1;i++){
        if(M[1][i]==1 && M[i][n]==1){cout<<"POSSIBLE"<<endl;return 0;}
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}