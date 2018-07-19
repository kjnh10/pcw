#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define MOD 1000000007


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;cin>>n;
    ll a[10001]={0};
    ll fact[10001];fact[0]=1;
    for(int i=1;i<=10000;i++) fact[i]=(fact[i-1]*i)%MOD;
    std::vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        a[v[i]]++;
    }
    sort(v.begin(),v.end());
    ll pen=0,time=0,res=1;
    for(int i=0;i<n;i++){
        time+=v[i];
        pen+=time;
    }
    for(int i=1;i<=10000;i++){
        if(a[i]) res =(res*fact[a[i]])%MOD;
    }
    cout<<pen<<endl<<res<<endl;
}