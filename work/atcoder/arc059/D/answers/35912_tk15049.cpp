#include<bits/stdc++.h>

using namespace std;


struct I{I(){ios::sync_with_stdio(false);cin.tie(0);}}init;

typedef long long LL;

typedef vector<int> V;
typedef vector<V> VV;
typedef VV Graph;

const LL MOD=1e9+7;
int main(){
    string s;
    cin>>s;
    int n=s.size();
    for(int i=0,j=1;j<n;i++,j++)
        if(s[i]==s[j]){
            cout<<i+1<<" "<<j+1<<endl;
            return 0;
        }
    for(int i=0,j=2;j<n;i++,j++)
        if(s[i]==s[j]){
            cout<<i+1<<" "<<j+1<<endl;
            return 0;
        }
    
    cout<<"-1 -1"<<endl;

    return 0;
}
