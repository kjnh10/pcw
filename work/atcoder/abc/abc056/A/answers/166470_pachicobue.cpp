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



int main()
{
    char c1,c2;
    cin >> c1 >> c2;
    if(c1 == 'H'){
        if(c2 == 'H'){
            cout << 'H' << endl;
            return 0;
        }
        if(c2 == 'D'){
            cout << 'D' << endl;
            return 0;
        }
    }
    if(c1 == 'D'){
        if(c2 == 'D'){
            cout << 'H' << endl;
            return 0;
        }
        if(c2 == 'H'){
            cout << 'D' << endl;
            return 0;
        }
    }
    return 0;
}
