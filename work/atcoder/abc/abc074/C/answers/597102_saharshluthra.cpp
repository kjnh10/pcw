#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define upperlimit 1000100
#define INF 1000000100
#define INFL 1000000000000000100
#define eps 1e-8
#define endl '\n'
#define sd(n) scanf("%d",&n)
#define slld(n) scanf("%lld",&n)
#define pd(n) printf("%d",n)
#define plld(n) printf("%lld",n)
#define pds(n) printf("%d ",n)
#define pllds(n) printf("%lld ",n)
#define pdn(n) printf("%d\n",n)
#define plldn(n) printf("%lld\n",n)
#define REP(i,a,b) for(i=a;i<=b;i++)
#define mp make_pair
#define pb push_back
#define pcc pair<char,char>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define tr(container,it) for(typeof(container.begin()) it=container.begin();it!=container.end();it++)
#define F first
#define S second
#define clr(a) memset(a,0,sizeof(a))
using namespace std;

ll gcd(ll n1,ll n2){
    if(!n1)return n2;
    if(!n2)return n1;
    if(n1%n2==0)return n2;
    return gcd(n2,n1%n2);
}
ll powmod(ll base,ll exponent){
    base%=mod;
    ll ans=1;
    while(exponent){
        if(exponent&1)ans=(ans*base)%mod;
        base=(base*base)%mod;
        exponent/=2;
    }
    ans%=mod;
    return ans;
}
int main()
{
    int a,b,c,d,e,f;
    int i1,i2,i3,i4,tot,sug;
    cin>>a>>b>>c>>d>>e>>f;
    a*=100;
    b*=100;
    tot=a;
    sug=0;
    for(i1=0;i1<=100;i1++)for(i2=0;i2<=100;i2++)for(i3=0;i3<=100;i3++)for(i4=0;i4<=100;i4++){
        int totwat=i1*a+i2*b;
        int totsug=i3*c+i4*d;
        if(totwat+totsug<=f){
            if(totsug*100<=totwat*e){
                if(sug*(totsug+totwat)<=tot*totsug){
                    sug=totsug;
                    tot=totwat+totsug;
                }
            }
        }
    }
    cout<<tot<<" "<<sug<<endl;
    return 0;
}