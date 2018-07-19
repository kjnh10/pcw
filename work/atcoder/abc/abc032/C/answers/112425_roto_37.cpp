#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pip;
typedef vector<int> vi;
typedef vector<vi> vii;
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
    int n, k;
    cin >> n >> k;
    int s[n];
    rep(i,n){
        cin >> s[i];
        if (s[i]==0) {
            cout << n << endl;
            return 0;
        }
    }
    if (k==0){
        cout << 0 << endl;
        return 0;
    }
    int l=0,r=0;
    int now=1;
    int ans=0;
    int len=0;
    while (r<n){
        if (now*s[r]<=k){
            now*=s[r];
            len+=1;
            r+=1;
        }
        else{
            ans=max(ans, len);
            while (now*s[r]>k){
                len-=1;
                now/=s[l];
                l+=1;

            }
            if(r<l) {now=1;r+=1;}
        }
    }
    cout << max(ans,len) << endl;
}
