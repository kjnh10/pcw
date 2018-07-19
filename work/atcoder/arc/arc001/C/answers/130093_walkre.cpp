#include <bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(int i=(x);i<(y);++i)
#define debug(x) #x << "=" << (x)

#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define print(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define print(x)
#endif

const int inf=1e9;
const int64_t inf64=1e18;
const double eps=1e-9;

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){
    os << "[";
    for (const auto &v : vec) {
    	os << v << ",";
    }
    os << "]";
    return os;
}

using i64=int64_t;

void solve(){
    vector<string> c(8);
    rep(i,0,8) cin >> c[i];
    
    vector<int> ys,xs;
    rep(y,0,8) if(count(c[y].begin(),c[y].end(),'Q')==0) ys.push_back(y);
    rep(x,0,8){
        bool ok=true;
        rep(y,0,8) if(c[y][x]=='Q') ok=false;
        if(ok) xs.push_back(x);
    }

    if(xs.size()!=5 or ys.size()!=5){
        cout << "No Answer" << endl;
        return;
    }

    auto ok=[&](vector<string> &ans){
        int cnt=0;
        rep(y,0,8) cnt+=count(ans[y].begin(),ans[y].end(),'Q');
        if(cnt!=8) return false;

        rep(y,0,8){
            rep(x,0,8){
                if(ans[y][x]!='Q') continue;
                rep(i,-1,2){
                    if(i==0) continue;
                    rep(j,-1,2){
                        if(j==0) continue;
                        rep(k,1,8){
                            int x_=x+i*k,y_=y+j*k;
                            if(0<=x_ and x_<8 and 0<=y_ and y_<8 and ans[y_][x_]=='Q') return false;
                        }
                    }
                }
            }
        }
        return true;
    };

    do{
        vector<string> ans=c;
        rep(i,0,5) ans[ys[i]][xs[i]]='Q';
        if(!ok(ans)) continue;
        rep(y,0,8) cout << ans[y] << endl;
        return;
    }while(next_permutation(xs.begin(),xs.end()));

    cout << "No Answer" << endl;
}

int main(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(10);
    solve();
    return 0;
}
