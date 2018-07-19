#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    int rc=0,bc=0;
    string loc[n];
    for(int i=0; i<n; i++){
        cin>>loc[i];
        for(int j=0; j<n; j++){
            if(loc[i][j]=='R'){
                rc++;
            }
            else if(loc[i][j]=='B'){
                bc++;
            }
        }
    }
    if(rc>bc)cout<<"TAKAHASHI"<<endl;
    else if(bc>rc)cout<<"AOKI"<<endl;
    else cout<<"DRAW"<<endl;
    return 0;
}
