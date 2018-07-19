#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pip;
typedef vector<int> vi;
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


signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<ll> a(n);
    vector<ll> b(m);
    rep(i,n) cin >> a[i];
    a.pb(3000000000);
    rep(i,m) cin >> b[i];
    b.pb(3000000000);
    int now=a[0];
    int cnt=0;
    int ans=0;
    while (true){
        if (cnt%2==0){
            auto it=lower_bound(all(b),now+x);
            if (*it==3000000000) break;
            now=*it;
            cnt+=1;
            ans+=1;
        }
        else{
            auto it=lower_bound(all(a),now+y);
            if (*it==3000000000) break;
            now=*it;
            cnt+=1;
        }
    }
    cout << ans << endl;
}
