#include "bits/stdc++.h"
using namespace std;
#define FOR(i,j,k) for(int (i)=(j);(i)<(int)(k);++(i))
#define rep(i,j) FOR(i,0,j)
#define each(x,y) for(auto &(x):(y))
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<(x)<<endl
#define smax(x,y) (x)=max((x),(y))
#define smin(x,y) (x)=min((x),(y))
#define MEM(x,y) memset((x),(y),sizeof (x))
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

// 8方向 + そこ
const int dy[] = { 0, 0, 1, -1, 0, 1, 1, -1, -1 };
const int dx[] = { 0, 1, 0, 0, -1, 1, -1, -1, 1 };

int H, W;
string S[100], T[100], U[100];


void solve(){
    rep(y, H)T[y] = U[y] = string(W, '.');
    rep(y, H)rep(x, W){
        bool isBlack = true;
        rep(i, 9){
            int ny = y + dy[i], nx = x + dx[i];
            if(ny < 0 || ny >= H || nx < 0 || nx >= W){
                continue;
            }
            if(S[ny][nx] != '#'){
                isBlack = false;
                break;
            }
        }
        if(isBlack){
            T[y][x] = '#';
            rep(i, 9){
                int ny = y + dy[i], nx = x + dx[i];
                if(ny < 0 || ny >= H || nx < 0 || nx >= W){
                    continue;
                }
                U[ny][nx] = '#';
            }
        }
    }
    
    bool same = true;
    rep(y, H){
        if(S[y] != U[y]){
            same = false;
            break;
        }
    }
    if(!same){
        cout << "impossible" << endl;
    } else{
        cout << "possible" << endl;
        rep(y, H){
            cout << T[y] << endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> H >> W){
        rep(y, H)cin >> S[y];
        solve();
    }
}