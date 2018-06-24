#include <bits/stdc++.h>
using namespace std;
 
#define M 1000000007
 
#define mp make_pair
#define pb push_back
#define tri pair<int, pair<int, int> >
#define TRI(a,b,c) (make_pair(a,make_pair(b,c)))
 
typedef long long ll;
typedef long double ld;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll a, b, c, x, y; cin>>a>>b>>c>>x>>y;
    ll tot=0;
    ll mn = min(x, y);
    tot+=min(2*c, a+b)*mn;
    x-=mn, y-=mn;
    tot+=x*min(2*c, a)+y*min(2*c, b);
    cout<<tot<<endl;
    return 0;
}