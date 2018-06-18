#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 300300;
ll pre[N] , suf[N];
int n ;
ll a[N];
multiset<ll>ms;

int main(){

cin>>n;
for(int i=1;i<=3*n;i++)cin>>a[i];

ll sum=0;
for(int i=1;i<=3*n;i++){

    sum+=a[i];
    ms.insert(a[i]);
    if( ms.size()>=n ){

        if( ms.size()>n ){
            ll x = *ms.begin();
            sum-=x;
            ms.erase( ms.begin() );
        }
        pre[i]=sum;
    }
    else pre[i]=-(1ll<<50);

    if( i>1 )pre[i]=max( pre[i],pre[i-1] );

}

ms.clear();
sum=0;
for(int i=3*n;i>0;i--){

    sum+=a[i];
    ms.insert(a[i]);
    if( ms.size()>=n ){

        if( ms.size()>n ){
            ll x = *ms.rbegin();
            sum-=x;
            ms.erase( --ms.end() );
        }
        suf[i]=sum;
    }
    else suf[i]=(1ll<<50);

    if( i+1<=3*n )suf[i]=min(suf[i],suf[i+1]);
}


ll best = -(1ll<<50);
for(int i=1;i<3*n;i++)
    best=max( best , pre[i]-suf[i+1] );

cout<<best<<endl;
return 0;
}
