// clang-format off
#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <iomanip>
#include <queue>
#include <map>

#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define RFOR(i, a, b) for(int i = (b)-1; i >= (a); i--)
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep(i, n) for(int i = (n)-1; i >= 0; i--)

#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define pii pair<int, int>
#define vi vector<int>

using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T>& p){return o<<"("<<p.first<<","<<p.second<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T>& vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}
typedef long long ll;
constexpr ll MOD = 1000000007;

int N, K;
constexpr int MAX = 5000;
ll a[MAX];
ll cnt = 0;
bool func(int i){
            vector<vector<bool>> check(N, vector<bool>(K, false)); // a[0]~a[j](a[i]除く)でL(L < K)が作れるか(ざこい)
        rep(l, K){
            check[0][l] = false;           
        }
        check[0][0] = true;
        if(i != 0){
            if(a[0] < K){
                check[0][a[0]] = true;
            }
        }
        rep1(j, N-1){
            if(i == j){
                rep(l, K){
                    check[j][l] = check[j-1][l];
                }
            } else {
                rep(l, K){
                    if(l >= a[j]){
                        if(check[j-1][l-a[j]]){
                            check[j][l] = true;
                            continue;
                        }
                    }
                    if(check[j-1][l]){
                        check[j][l] = true;
                        continue;
                    }
                }
            }
        }
        ll M = (K > a[i])?K-a[i]:0;
        bool f = false;
        for(int j = M; j < K; j++){
            if(check[N-1][j]){
                f = true;
                break;
            }
        }
        return f;
}

int main()
{
    cin >> N >> K;
    rep(i, N){
        cin >> a[i];
    }
    sort(a,a+N);

    int min = 0;
    if(func(min)){
        cout << 0 << endl;
        return 0;
    }
    int max = N;
    while(min < max){
        const int mid = (min+max)/2;
        if(func(mid)){
            max = mid;
        } else {
            if(min == mid){
                break;
            } else {
                min = mid;
            }
        }
    }

    // rep(i, N){
    //     func(i);
    // }
    cout << min +1 << endl;
    
    return 0;
}
