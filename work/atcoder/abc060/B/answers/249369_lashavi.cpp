#include<bits/stdc++.h>
#define ll long long int
#define mp make_pair
#define pb push_back
#define si(x) scanf("%d",&x)
#define pi(x) printf("%d\n",x)
#define s(x) scanf("%I64d",&x)
#define p(x) printf("%I64d\n",x)
#define sc(x) scanf("%s",x)
#define pc(x) printf("%s",x)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define F first
#define S second
#define M 1000000007
#define N 1000002
#define inf 1e15
#define PQG priority_queue< int,std::vector<int>,std::greater<int> >
#define PQL priority_queue< int,std::vector<int>,std::less<int> >
#define PQPL priority_queue<pii ,vector< pii >, less< pii > >
#define PQPG priority_queue<pii ,vector< pii >, greater< pii > >
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;


int main() {
    fast_io;
    int a,b,c;
    cin>>a>>b>>c;
int x=a;
    while(a<=1e6) {
        if(a%b==c) {
            cout<<"YES\n";
            return 0;
        }
        a+=x;
    }
    cout<<"NO\n";

    return 0;
}
