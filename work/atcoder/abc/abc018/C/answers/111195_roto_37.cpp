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

int r,c,k;
char s[505][505];
int check[505][505]={};

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> r >> c >> k;
    rep(i,r){
        rep(j,c){
            cin >> s[i][j];
        }
    }
    rep(i,r){
        rep(j,c){
            if (j==0){
                if(s[i][j]=='o') check[i][j]=0;
                else check[i][j]=1;
            }
            else if (s[i][j]=='o') check[i][j]=check[i][j-1];
            else check[i][j]=check[i][j-1]+1;
        }
    }
    int ans=0;
    rep(i,r){
        rep(j,c){
            bool ok=true;
            rep(l,k){
                if (i-k+1<0 || i+k-1>r-1 || j-k+1<0 || j+k-1>c-1){ok=false; break;}
                if(j-k+l<0){
                    if (check[i-l][j+k-1-l]!=0){ok=false; break;}
                    if (check[i+l][j+k-1-l]!=0){ok=false; break;}
                }
                else{
                    if (check[i-l][j+k-1-l]-check[i-l][j-k+l]!=0){ok=false; break;}
                    if (check[i+l][j+k-1-l]-check[i+l][j-k+l]!=0){ok=false; break;}
                }
            }
            if (ok) ans+=1;
        }
    }
    cout << ans << endl;
}
