#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> plli;
typedef pair<int,pii> pipii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<pii> vpii;

#define rep(i,n) for (int i=0;i<(n);i++)
#define rep2(i,a,b) for (int i=(a);i<(b);i++)
#define rrep(i,n) for (int i=(n);i>=0;i--)
#define rrep2(i,a,b) for (int i=(a);i>b;i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()

const int mod = 1e9 + 7;
const ll INF = 1<<30;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

ll n;


signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    ll tmp=n;
    int cnt=0;
    while (tmp>=2){
        tmp/=2;
        cnt+=1;
    }
    ll x=1;
    if (cnt%2==0){
        cnt=0;
        while (x<=n){
            if (cnt%2==0) x=2*x+1;
            else x=2*x;
            cnt+=1;
        }
        if (cnt%2==1) cout << "Aoki" << endl;
        else cout << "Takahashi" << endl;
    }
    else{
        cnt=0;  
        while (x<=n){
            if (cnt%2==1) x=2*x+1;
            else x=2*x;
            cnt+=1;
        }
        if (cnt%2==1) cout << "Aoki" << endl;
        else cout << "Takahashi" << endl;
    }
}